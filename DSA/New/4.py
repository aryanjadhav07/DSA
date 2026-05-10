import pandas as pd
import numpy as np

import matplotlib.pyplot as plt

from sklearn.datasets import fetch_california_housing

from sklearn.preprocessing import StandardScaler

from sklearn.decomposition import PCA

# Load California Housing Dataset
housing = fetch_california_housing()

X = pd.DataFrame(
    housing.data,
    columns=housing.feature_names
)

print("Original Shape:", X.shape)

# Standardization
scaler = StandardScaler()

X_scaled = scaler.fit_transform(X)

# Apply PCA
pca = PCA(n_components=2)

X_pca = pca.fit_transform(X_scaled)

print("Reduced Shape:", X_pca.shape)

# Explained Variance
print(
    "Explained Variance Ratio:",
    pca.explained_variance_ratio_
)

print(
    "Total Variance Explained:",
    sum(pca.explained_variance_ratio_) * 100
)

# Visualization
plt.scatter(
    X_pca[:,0],
    X_pca[:,1]
)

plt.xlabel("Principal Component 1")

plt.ylabel("Principal Component 2")

plt.title("PCA - California Housing Dataset")

plt.show()