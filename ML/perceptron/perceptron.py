# In The Name of God
# =======================================
# [] File Name : perceptron.py
#
# [] Creation Date : 19-01-2020
#
# [] Created By : Parham Alvani <parham.alvani@gmail.com>
# =======================================

import numpy as np

class Perceptron:
    '''
    Perceptron classifier
    '''
    def __init__(self, eta: float = 0.01, n_iter: int = 50, random_state: int = 1):
        self.eta = eta
        self.n_iter = n_iter
        self.random_state = random_state
        self._w = []
        self._errors = []

    def fit(self, X, y):
        '''
        Fit training data.

        X: np.ndarray, shape = [n_examples, n_features]
        y: np.ndarray, shape = [n_examples]
        '''
        rgen = np.random.RandomState(self.random_state)
        self._w = rgen.normal(loc=0.0, scale=0.01,
                              size=1 + X.shape[1])

        for _ in range(self.n_iter):
            errors = 0
            for x_i, target in zip(X, y):
                update = self.eta * (target - self.predict(x_i))
                self._w[1:] += update * x_i
                self._w[0] += update
                errors += int(update != 0.0)
            self._errors.append(errors)
        return self

    def net_input(self, X):
        '''
        Calculate net input
        '''
        return np.dot(X, self._w[1:]) + self._w[0]

    def predict(self, X):
        '''
        Return class label
        X: np.ndarray, shape = [?, n_features]
        '''
        return np.where(self.net_input(X) >= 0.0, 1, -1)
