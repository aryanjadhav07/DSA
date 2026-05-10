import pandas as pd

from sklearn.datasets import load_iris
from sklearn.preprocessing import LabelEncoder

# 1. Load Dataset into pandas DataFrame
iris = load_iris()

df = pd.DataFrame(
    iris.data,
    columns=iris.feature_names
)

# Add target column
df['species'] = iris.target

print("Dataset Loaded Successfully\n")

# 2. Display Missing Values
print("Missing Values:\n")
print(df.isnull().sum())

# 3. Display Initial Statistics
print("\nInitial Statistics:\n")
print(df.describe())

# 4. Check Dimensions
print("\nShape of Dataset:")
print(df.shape)

# 5. Display Data Types
print("\nData Types:\n")
print(df.dtypes)

# 6. Apply Data Type Conversion
df['species'] = df['species'].astype('float')

print("\nAfter Data Type Conversion:\n")
print(df.dtypes)

# Convert numeric target into species names
species_names = {
    0.0: 'setosa',
    1.0: 'versicolor',
    2.0: 'virginica'
}

df['species'] = df['species'].map(species_names)

# 7A. Label Encoding
le = LabelEncoder()

df['species_label'] = le.fit_transform(df['species'])

print("\nLabel Encoding:\n")
print(df[['species', 'species_label']].head())

# 7B. One Hot Encoding
one_hot = pd.get_dummies(df['species'])

print("\nOne Hot Encoding:\n")
print(one_hot.head())   