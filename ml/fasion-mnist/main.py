import tensorflow as tf
from tensorflow import keras

print(tf.__version__)
print(keras.__version__)

fasion_mnist = keras.datasets.fashion_mnist

(X_train_full, y_train_full), (X_test, y_test) = fasion_mnist.load_data()

# pixel 0-255
# 28 x 28 images
print(X_train_full.shape)
print(X_train_full.dtype)

# create validation set
X_valid, X_train = X_train_full[:5000] / 255.0, X_train_full[5000:] / 255.0
y_valid, y_train = y_train_full[:5000], y_train_full[5000:]

class_names = [
    "T-shirt/top",
    "Trouser",
    "Pullover",
    "Dress",
    "Coat",
    "Sandal",
    "Shirt",
    "Sneaker",
    "Bag",
    "Ankle boot",
]

model = keras.models.Sequential()
model.add(keras.layers.Flatten(input_shape=[28, 28]))
model.add(keras.layers.Dense(300, activation="relu"))
model.add(keras.layers.Dense(100, activation="relu"))
# because we have 10 exclusive classes
model.add(keras.layers.Dense(10, activation="softmax"))

print(model.summary())

model.compile(
    loss="sparse_categorical_crossentropy",
    optimizer="sgd",
    metrics=["accuracy"],
)

history = model.fit(
    X_train, y_train, epochs=30, validation_data=(X_valid, y_valid)
)
print(history)
