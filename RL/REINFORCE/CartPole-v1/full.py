import gymnasium as gym
import torch
import torch.nn as nn
import torch.optim as optim
import matplotlib.pyplot as plt

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

class PolicyNetwork(nn.Module):
    def __init__(self, state_dim, action_dim, hidden_dim=128):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(state_dim, hidden_dim),
            nn.ReLU(),
            nn.Linear(hidden_dim, action_dim),
            nn.Softmax(dim=-1)
        )

    def forward(self, state):
        return self.net(state)

class REINFORCEAgent:
    def __init__(self, state_dim, action_dim, lr=1e-2, gamma=0.99):
        self.policy = PolicyNetwork(state_dim, action_dim).to(device)
        self.optimizer = optim.Adam(self.policy.parameters(), lr=lr)
        self.gamma = gamma
        self.reset()

    def reset(self):
        self.log_probs = []
        self.rewards = []

    def select_action(self, state, is_training=False):
        if is_training:
            state = torch.tensor(state).unsqueeze(0).to(device)
            probs = self.policy(state)
            dist = torch.distributions.Categorical(probs)
            action = dist.sample()
            self.log_probs.append(dist.log_prob(action))
            return action.item()

        with torch.no_grad():
            state = torch.tensor(state).unsqueeze(0).to(device)
            probs = self.policy(state)
            dist = torch.distributions.Categorical(probs)
            return dist.sample().item()

    def store_reward(self, reward):
        self.rewards.append(reward)

    def finish_episode(self):
        returns = []
        G = 0
        for r in reversed(self.rewards):
            G = r + self.gamma * G
            returns.insert(0, G)
        returns = torch.tensor(returns).to(device)
        returns = (returns - returns.mean()) / (returns.std() + 1e-8)

        loss = 0
        for log_prob, G in zip(self.log_probs, returns):
            loss += -log_prob * G

        self.optimizer.zero_grad()
        loss.backward()
        self.optimizer.step()
        self.reset()

def simulate(num_episodes=500, is_training=True, render=False):
    env = gym.make('CartPole-v1', render_mode='human' if render else None)

    agent = REINFORCEAgent(env.observation_space.shape[0], env.action_space.n)
    model_file_name = 'REINFORCE_CartPole-v1.pth'
    if not is_training:
        agent.policy.load_state_dict(torch.load(model_file_name, weights_only=True))

    reward_history = []
    for ep in range(num_episodes):
        state = env.reset()[0]
        total_reward = 0
        done = False
        while not done:
            action = agent.select_action(state, is_training=is_training)
            next_state, reward, term, trunc, _ = env.step(action)
            done = term or trunc
            if is_training:
                agent.store_reward(reward)
            state = next_state
            total_reward += reward

        if is_training:
            agent.finish_episode()
        reward_history.append(total_reward)
        print(f"Episode {ep}, Total reward : {total_reward}")

    if is_training:
        torch.save(agent.policy.state_dict(), model_file_name)
        prefix = 'Training'
    else:
        prefix = 'Testing'

    plt.plot(reward_history)
    plt.xlabel('Episode')
    plt.ylabel('Episode Return')
    plt.title(prefix + ' Episode Returns')
    plt.savefig(prefix + '_episode_returns.webp')

if __name__ == '__main__':
    # mode = 'train'
    mode = 'test'
    if mode == 'train':
        simulate(500)
    else:
        simulate(10, is_training=False)
        simulate(5, is_training=False, render=True)