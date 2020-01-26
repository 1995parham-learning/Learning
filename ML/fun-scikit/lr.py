import numpy as np

class LogisticRegressionGD:
    def __init__(self, eta: float, n_iter: int, random_state: int = 42):
        self.eta = eta
        self.n_iter = n_iter
        self.random_state = random_state
        self._w = []

    def activation(self, X):
        return 1 / (1 + np.exp(X))

    def net_input(self, X):
        return np.dot(X, self._w[1:]) + self._w[0]

    def fit(self, X, y):
        rgen = np.random.RandomState(self.random_state)
        self._w = rgen.normal(loc=0.0, scale=1.0,
                              size=1 + X.shape[1])
        for _ in range(self.n_iter):
            output = self.activation(self.net_input(X))
            errors = output - y
            self._w[1:] += self.eta * X.T.dot(errors)
            self._w[0] = self.eta * errors.sum()
        return self

    def predict(self, X):
        print(self.net_input(X))
        return np.where(self.net_input(X) > 0, 1, 0)


if __name__ == '__main__':
    X = np.array([[1, 2], [1, 3], [1, 4]])
    y = np.array([1, 1, 0])

    print(LogisticRegressionGD(0.1, 10).fit(X, y).predict([[1, 1], [1, 5], [-1, -1], [10, 10]]))
