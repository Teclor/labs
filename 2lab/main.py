import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import sklearn.datasets
import pandas as pd

# sns.set()
# plt.figure(figsize=(16, 9))


def flip_dataframe(df):
    df = df.T.groupby(level=0).agg(lambda x: x.values.tolist()).stack().apply(pd.Series).unstack().sort_index(level=1, axis=1)
    df.columns = df.columns.droplevel(level=0)


def prepare_housing_dataset(h):
    h = h.drop("ocean_proximity")
    length = h.shape[1]
    h_prepared = np.ndarray([
        ["data", np.empty(shape=[length, 8], dtype=float)],
        ["target", np.empty(shape=length, dtype=float)],
        ["names", np.array([
            "median_income",
            "housing_median_age",
            "average_room_count",
            "average_bedroom_count",
            "population",
            "average_occupation",
            "latitude",
            "longitude",
        ])
        ]
    ])
    for i in range(length):
        row = h[i].astype(float)
        h_prepared["target"][i] = row["median_house_value"] / 100000
        h_prepared["data"][i] = np.array([
            row["median_income"],
            row["housing_median_age"],
            row["total_rooms"] / row["households"],
            row["total_bedrooms"] / row["households"],
            row["population"],
            row["population"] / row["households"],
            row["latitude"],
            row["longitude"] if (row["longitude"] >= 0) else (row["longitude"] + 360),
        ], dtype=float)
    return h_prepared

housing2 = sklearn.datasets.fetch_california_housing()
housing = pd.read_csv("housing_flipped.csv", index_col=0)
# housing = housing.T.groupby(level=0).agg(lambda x: x.values.tolist()).stack().apply(pd.Series).unstack().sort_index(level=1, axis=1)
# housing.columns = housing.columns.droplevel(level=0)
# housing.to_csv(path_or_buf="housing_flipped.csv")
print(housing2.feature_names)
print(housing2.data[0])
print(housing2.target[0])

housing.columns = housing.columns.astype(int)
prepare_housing_dataset(housing)
print(housing.names)
print(housing.data[0])
print(housing.target[0])


"""
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
"""