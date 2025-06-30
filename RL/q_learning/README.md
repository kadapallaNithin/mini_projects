# Q Learning Projects
## FrozenLake-v1
Done as part of Seasons of Code (SoC) at IIT Bombay during summer break of my M.Tech.
## Taxi-v3, MountainCar-v0
Done incontinuation with FrozenLake-v1

## Gym env notes
- If the seed is same, the reset will also be same. Hence should be random.

    Obeserved while working on `MountainCar-v0`

```python
    # state = env.reset(seed=seed)[0] # This produces same state
    state = env.reset(seed=np.random.randint(0,100))[0]
```