import numpy as np
from typing import List


class LogisticRegressionGD:
    '''
    Logistic Regression Classifier using gradient descent
    '''

    def __init__(self, eta: float = 0.05, n_iter: int = 50, random_state: int = 42):
        self.eta = eta
        self.n_iter = n_iter
        self.random_state = random_state
        self._w = []
        self._cost: List[float] = []

    def activation(self, z):
        '''
        Compute logistic sigmoid activation
        '''
        return 1 / (1 + np.exp(-z))

    def net_input(self, X):
        '''
        Calculate the net input
        '''
        return np.dot(X, self._w[1:]) + self._w[0]

    def fit(self, X, y):
        '''
        Fit training data.

        Parameters
        ----------
        X: {array-like}, shape = [n_examples, n_features]
        Training vectors, where n_examples is the number of
        examples and n_features is the number of features.
        Y: array-like, shape = [n_examples]
        Target values.

        '''
        rgen = np.random.RandomState(self.random_state)
        self._w = rgen.normal(loc=0.0, scale=0.01,
                              size=1 + X.shape[1])
        for _ in range(self.n_iter):
            output = self.activation(self.net_input(X))
            errors = (y - output)
            self._w[1:] += self.eta * X.T.dot(errors)
            self._w[0] += self.eta * errors.sum()

            cost = (-y.dot(np.log(output)) - ((1 - y).dot(np.log(1 - output))))
            self._cost.append(cost)

        return self

    def predict(self, X):
        '''
        Return class label after unit step
        '''
        return np.where(self.net_input(X) >= 0.0, 1, 0)
