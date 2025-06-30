import gymnasium as gym
import numpy as np
import pickle
import matplotlib.pyplot as plt


def run(episodes=10000, is_training=True, render=False, np_seed=0, act_seed=42):
    model_name = "MountainCar-v0"
    env = gym.make(model_name, render_mode='human' if render else None)

    eps = 1
    eps_decay = 2/episodes #0.00008
    disc_fact = 0.9 #0.99
    lr = 0.9
    np.random.seed(seed=np_seed)
    env.action_space.seed(seed=act_seed)

    obs_space = env.observation_space
    pos_space = np.linspace(obs_space.low[0], obs_space.high[0], 20)
    vel_space = np.linspace(obs_space.low[1], obs_space.high[1], 20)

    episode_total_rewards = np.zeros(episodes)
    if is_training:
        q = np.zeros((len(pos_space), len(vel_space), env.action_space.n)) # 20x20xn
    else:
        with open(f'{model_name}.pkl','rb') as f:
            q = pickle.load(f)
        # print(q)
    num_failures = 0
    for epi in range(episodes):
        # If the seed is same, the reset will also be same.
        # Hence should be random.
        state = env.reset(seed=np.random.randint(0,100))[0]
        terminated = truncated = False
        while not terminated and not truncated:
            state_pos = np.digitize(state[0], pos_space)
            state_vel = np.digitize(state[1], vel_space)
            if is_training and eps > np.random.random():
                action = env.action_space.sample()
            else:
                action = np.argmax(q[state_pos][state_vel])
            next_state, reward, terminated, truncated, _ = env.step(action)

            episode_total_rewards[epi] += reward
            next_state_pos = np.digitize(next_state[0], pos_space)
            next_state_vel = np.digitize(next_state[1], vel_space)

            if is_training:
                target = reward + disc_fact * np.max(q[next_state_pos][next_state_vel])
                q[state_pos][state_vel][action] += lr*(target - q[state_pos][state_vel][action])

            state = next_state

        if truncated:
            num_failures += 1

        if is_training:
            eps = max(0, eps - eps_decay)

    plt.scatter(range(episodes), episode_total_rewards, marker='.')
    if is_training:
        plt.title(f'eps decay:{eps_decay} np seed:{np_seed} g:{disc_fact} lr:{lr}')
        img_name = f'{model_name}_{episodes}_np_{np_seed}_d_{eps_decay}_g_{disc_fact}_lr_{lr}.jpg'
        f = open(f'{model_name}.pkl','wb')
        pickle.dump(q, f)
        f.close()
    else:
        img_name = f'{model_name}.jpg'
    print(num_failures*100/episodes,np.average(episode_total_rewards))

    plt.savefig(img_name)

if __name__ == '__main__':
    # run(episodes=5000, is_training=True, render=False, np_seed=0)
    for i in range(10):
        run(episodes=1000, is_training=False, render=False, np_seed=i)
    # run(episodes=10, is_training=False, render=True, np_seed=None)
