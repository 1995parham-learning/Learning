import itertools
import random
from typing import List


class Environment:
    def __init__(self):
        self.weights: List[int] = [1, 2, 10]
        self.costs: List[int] = [1, 1, 1]
        self.taken: List[int] = [1, 1, 1]
        self.knapsack = 10

    def get_actions(self) -> List[int]:
        actions = []
        for not_taken in itertools.compress(
            range(len(self.taken)),
            self.taken,
        ):
            if self.weights[not_taken] <= self.knapsack:
                actions.append(not_taken)

        return actions

    def is_done(self) -> bool:
        return False

    def action(self, action: int) -> int:
        self.taken[action] = 0
        self.knapsack -= self.weights[action]

        return self.costs[action]


class Agent:
    def __init__(self):
        self.local_reward = 0

    def step(self, env: Environment):
        actions = env.get_actions()
        if len(actions) == 0:
            return False
        chosen = random.choice(actions)
        print(chosen)
        reward = env.action(chosen)
        self.local_reward += reward
        return True


if __name__ == "__main__":
    a = Agent()
    env = Environment()

    while a.step(env):
        pass
