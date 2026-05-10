import pandas as pd
import numpy as np
import warnings

from sklearn.preprocessing import LabelEncoder, StandardScaler
from scipy import stats

warnings.filterwarnings('ignore')

url = 'https://raw.githubusercontent.com/datasciencedojo/datasets/master/titanic.csv'

df = pd.read_csv(url)

print(df.head())

print(df.isnull().sum())

df['Age'].fillna(df['Age'].median(), inplace=True)

df['Embarked'].fillna(df['Embarked'].mode()[0], inplace=True)

df.drop(columns=['Cabin'], inplace=True)

Q1 = df['Fare'].quantile(0.25)
Q3 = df['Fare'].quantile(0.75)

IQR = Q3 - Q1

df = df[
    (df['Fare'] >= Q1 - 1.5*IQR) &
    (df['Fare'] <= Q3 + 1.5*IQR)
]

df['Fare_log'] = np.log1p(df['Fare'])

df['Age_scaled'] = StandardScaler().fit_transform(df[['Age']])

le = LabelEncoder()

df['Sex_encoded'] = le.fit_transform(df['Sex'])

df['Embarked_encoded'] = le.fit_transform(df['Embarked'])

print(df.head())