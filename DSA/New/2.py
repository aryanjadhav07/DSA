import pandas as pd
import numpy as np

import matplotlib.pyplot as plt

from sklearn.preprocessing import MinMaxScaler
from sklearn.preprocessing import StandardScaler

# Create Student Performance Dataset
data = {
    'Marks': [45, 50, 78, 90, 35, 67, 120, np.nan, 56, 48],
    'Attendance': [80, 85, 90, 95, 70, 88, 92, 85, np.nan, 75]
}

df = pd.DataFrame(data)

print("Original Dataset:\n")
print(df)

# 1. Display Missing Values
print("\nMissing Values:\n")
print(df.isnull().sum())

# 2. Drop Missing Values
df = df.dropna()

print("\nDataset After Dropping Missing Values:\n")
print(df)

# 3A. Box Plot for Outlier Detection
plt.boxplot(df['Marks'])

plt.title("Box Plot - Marks")

plt.show()

# 3B. Scatter Plot for Outlier Detection
plt.scatter(range(len(df)), df['Marks'])

plt.title("Scatter Plot - Marks")

plt.xlabel("Index")
plt.ylabel("Marks")

plt.show()

# 4. Handle Outlier using IQR Method
Q1 = df['Marks'].quantile(0.25)
Q3 = df['Marks'].quantile(0.75)

IQR = Q3 - Q1

lower = Q1 - 1.5 * IQR
upper = Q3 + 1.5 * IQR

df = df[
    (df['Marks'] >= lower) &
    (df['Marks'] <= upper)
]

print("\nDataset After Outlier Removal:\n")
print(df)

# 5A. Min-Max Normalization
minmax = MinMaxScaler()

df['Marks_MinMax'] = minmax.fit_transform(df[['Marks']])

# 5B. Standardization
standard = StandardScaler()

df['Marks_Standard'] = standard.fit_transform(df[['Marks']])

print("\nDataset After Normalization:\n")
print(df)