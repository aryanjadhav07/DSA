import pandas as pd
import numpy as np

import matplotlib.pyplot as plt

import time

from sklearn.datasets import load_iris

from sklearn.model_selection import train_test_split

from sklearn.preprocessing import StandardScaler

from sklearn.neighbors import KNeighborsClassifier

from sklearn.metrics import accuracy_score

# Load Iris Dataset
iris = load_iris()

X = iris.data

y = iris.target

# Split Dataset
X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.3,
    random_state=42
)

# Feature Scaling
scaler = StandardScaler()

X_train = scaler.fit_transform(X_train)

X_test = scaler.transform(X_test)

# Elbow Method
error_rate = []

for k in range(1, 11):

    knn = KNeighborsClassifier(n_neighbors=k)

    knn.fit(X_train, y_train)

    y_pred = knn.predict(X_test)

    error = np.mean(y_pred != y_test)

    error_rate.append(error)

# Plot Elbow Graph
plt.plot(
    range(1, 11),
    error_rate,
    marker='o'
)

plt.xlabel("K Value")

plt.ylabel("Error Rate")

plt.title("Elbow Method for Optimal K")

plt.show()

# Optimal K
optimal_k = error_rate.index(min(error_rate)) + 1

print("Optimal K:", optimal_k)

# Train Final Model
start = time.time()

model = KNeighborsClassifier(
    n_neighbors=optimal_k
)

model.fit(X_train, y_train)

y_pred = model.predict(X_test)

end = time.time()

# Accuracy
accuracy = accuracy_score(y_test, y_pred)

print(
    "Accuracy:",
    accuracy * 100
)

# Time Taken
print(
    "Time Taken:",
    end - start,
    "seconds"
)