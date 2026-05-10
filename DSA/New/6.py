import pandas as pd
import numpy as np

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

# Different K values
k_values = [3, 4, 5]

for k in k_values:

    # Create KNN Model
    knn = KNeighborsClassifier(n_neighbors=k)

    # Train Model
    knn.fit(X_train, y_train)

    # Predictions
    y_pred = knn.predict(X_test)

    # Accuracy
    accuracy = accuracy_score(y_test, y_pred)

    print(f"K = {k}")

    print(f"Accuracy = {accuracy * 100:.2f}%")

    print("----------------------")