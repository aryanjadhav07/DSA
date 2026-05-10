import pandas as pd
import numpy as np

import matplotlib.pyplot as plt

from sklearn.model_selection import train_test_split

from sklearn.svm import SVC

from sklearn.metrics import (
    accuracy_score,
    confusion_matrix,
    classification_report,
    ConfusionMatrixDisplay
)

# Load Dataset
df = pd.read_csv("emails.csv")

print(df.head())

# Features and Target
X = df.drop(['Email No.', 'spam'], axis=1)

y = df['spam']

# Split Dataset
X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.2,
    random_state=42
)

# Create SVM Model
svm = SVC(
    kernel='linear',
    C=1.0,
    probability=True,
    random_state=42
)

# Train Model
svm.fit(X_train, y_train)

# Predictions
y_pred = svm.predict(X_test)

# Accuracy
print(
    "Accuracy:",
    accuracy_score(y_test, y_pred)
)

# Confusion Matrix
cm = confusion_matrix(y_test, y_pred)

print("\nConfusion Matrix:\n")

print(cm)

# Classification Report
print("\nClassification Report:\n")

print(
    classification_report(
        y_test,
        y_pred,
        target_names=['Not Spam', 'Spam']
    )
)

# Visualization
disp = ConfusionMatrixDisplay(
    confusion_matrix=cm,
    display_labels=['Not Spam', 'Spam']
)

disp.plot()

plt.title("SVM Confusion Matrix")

plt.show()