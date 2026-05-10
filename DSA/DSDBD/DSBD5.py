import pandas as pd
import numpy as np

import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.model_selection import train_test_split

from sklearn.preprocessing import StandardScaler

from sklearn.linear_model import LogisticRegression

from sklearn.metrics import (
    confusion_matrix,
    classification_report,
    accuracy_score
)

df = pd.read_csv("Social_Network_Ads.csv")

X = df[['Age', 'EstimatedSalary']]

y = df['Purchased']

X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.25,
    random_state=0
)

sc = StandardScaler()

X_train = sc.fit_transform(X_train)

X_test = sc.transform(X_test)

classifier = LogisticRegression()

classifier.fit(X_train, y_train)

y_pred = classifier.predict(X_test)

print(
    "Accuracy:",
    accuracy_score(y_test, y_pred)
)

cm = confusion_matrix(y_test, y_pred)

print(cm)

print(
    classification_report(
        y_test,
        y_pred
    )
)

sns.heatmap(cm, annot=True)

plt.title("Confusion Matrix")

plt.show()