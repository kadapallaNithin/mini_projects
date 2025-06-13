# Reference https://youtu.be/9fAnzZ6xzhA?si=Uw25gUSCJ9DD9qph
# and https://www.cse.iitb.ac.in/~shivaram/teaching/cs747-s2025/index.html
import gymnasium as gym
import random
import numpy as np
import pickle
import matplotlib.pyplot as plt

def run(episodes=10000, is_training=True, render=False):
    env_name = 'Taxi-v3'
    env = gym.make(env_name, render_mode='human' if render else None)
    model_file_name = f'models/{env_name}.pkl'
    num_actions = env.action_space.n
    num_states = env.observation_space.n

    eps = 1
    eps_decay = 0.0001
    dis_fact = 0.99
    lr = 0.8

    if is_training:
        q = np.zeros((num_states,num_actions))
    else:
        f = open(model_file_name, 'rb')
        q = pickle.load(f)
        f.close()

    episode_total_reward = np.zeros(episodes)
    num_truncated = 0
    for i in range(episodes):
        state = env.reset()[0]
        terminated = False
        truncated = False
        while not terminated and not truncated:
            if is_training and eps > random.random():
                action = env.action_space.sample()
            else:
                action = np.argmax(q[state])

            new_state, reward, terminated, truncated, _ = env.step(action)

            episode_total_reward[i] += reward
            if is_training:
                target = reward + dis_fact * np.max(q[new_state])
                q[state][action] += lr * (target - q[state][action])
            state = new_state

            eps = max(0, eps - eps_decay)
        if truncated:
            print(i,'truncated')
            num_truncated += 1
            episode_total_reward[i] = 0

    plt.plot(episode_total_reward)
    plt.savefig(f'{env_name}_{is_training}.jpg')
    print('num_truncated',num_truncated)
    if is_training:
        f = open(model_file_name, 'wb')
        pickle.dump(q,f)
        f.close()


if __name__ == '__main__':
    # run(episodes=10000, is_training=True)
    # run(episodes=100, is_training=False, render=False)
    run(episodes=10, is_training=False, render=True)

