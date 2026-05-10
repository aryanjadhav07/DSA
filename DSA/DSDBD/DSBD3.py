import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import PCA
from sklearn.datasets import load_iris

iris = load_iris()

X = pd.DataFrame(
    iris.data,
    columns=iris.feature_names
)

y = iris.target

print("Original Shape:", X.shape)

scaler = StandardScaler()

X_scaled = scaler.fit_transform(X)

pca = PCA(n_components=2)

X_pca = pca.fit_transform(X_scaled)

print("Reduced Shape:", X_pca.shape)

print(
    "Explained Variance Ratio:",
    pca.explained_variance_ratio_
)

print(
    "Total Variance Explained:",
    sum(pca.explained_variance_ratio_) * 100
)


plt.scatter(X_pca[:,0], X_pca[:,1], c=y)

plt.xlabel("PC1")
plt.ylabel("PC2")

plt.title("PCA - Iris Dataset")

plt.show()