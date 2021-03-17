import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import sklearn.datasets

sns.set()
plt.figure(figsize=(16, 9))
# housing2 = pd.read_csv("housing.csv")
housing = sklearn.datasets.fetch_california_housing()
from sklearn.naive_bayes import MultinomialNB
model = MultinomialNB()
for i in housing.data:
    if i[7] < 0:
        i[7] += 360
housing.target = np.round(housing.target, 0)
model.fit(housing.data, housing.target)
labels = model.predict(housing.data)
from sklearn.metrics import confusion_matrix
mat = confusion_matrix(housing.target, labels)
sns.heatmap(mat.T, square=True, annot=True, fmt='d', cbar=False,
            xticklabels=housing.target_names, yticklabels=housing.target_names)
plt.xlabel('true label')
plt.ylabel('predicted label')
# plt.show()
X_new = [[8.3252, 41, 6.98412698, 1.02380952, 322,
         2.55555556, 37.88, 237.77]]
print(model.predict(X_new)[0])
