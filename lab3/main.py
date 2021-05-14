import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
from sklearn.cluster import KMeans
from sklearn.datasets import make_blobs


def prepare_housing_dataset(h, training_percent):
    """
    Подготавливает данные из датасета housing
    :param h pandas.DataFrame
    :param training_percent percent of training data
    """
    length = h.shape[1]
    var_quantity = 5
    train_quantity = int(np.round(length * (training_percent / 100)))
    h_prepared = {"train_data": np.empty(shape=[train_quantity, var_quantity], dtype=float),
                  "train_target": np.empty(shape=train_quantity, dtype=float),
                  "test_data": np.empty(shape=[length - train_quantity, var_quantity], dtype=float),
                  "test_target": np.empty(shape=length - train_quantity, dtype=float),
                  "names": np.array([
                        "income",
                        "rooms_per_house",
                        "near_ocean",
                        "near_bay",
                        "1h_ocean",
                        "new_house",
                        "people_per_house",
                        "latitude",
                        "longitude",
                  ]),
                  "target_names": np.array(
                      ["<50000$", "50 000-150 000 $", "150 000-250 000 $", "250 000-350 000 $", "350 000-450 000 $",
                       "450 000-550 000 $"])
                  }
    for i in range(train_quantity):
        row = h[i]
        h_prepared["train_target"][i] = row["median_house_value"]
        h_prepared["train_data"][i] = row.drop("median_house_value")
    for i in range(length - train_quantity):
        row = h[i]
        h_prepared["test_target"][i] = row["median_house_value"]
        h_prepared["test_data"][i] = row.drop("median_house_value")
    return h_prepared


sns.set()
plt.figure(figsize=(16, 9))
# housing = pd.read_csv("housing_new_flipped.csv", index_col=0)
# housing.columns = housing.columns.astype(int)
# prepared = prepare_housing_dataset(housing, 80)

from sklearn.datasets import load_digits
digits = load_digits()
kmeans = KMeans(n_clusters=10, random_state=0)
clusters = kmeans.fit_predict(digits.data)
fig, ax = plt.subplots(2, 5, figsize=(8, 3))
centers = kmeans.cluster_centers_.reshape(10, 8, 8)
for axi, center in zip(ax.flat, centers):
    axi.set(xticks=[], yticks=[])
    axi.imshow(center, interpolation='nearest', cmap=plt.cm.binary)
from scipy.stats import mode
labels = np.zeros_like(clusters)
for i in range(10):
    mask = (clusters == i)
    labels[mask] = mode(digits.target[mask])[0]
from sklearn.metrics import accuracy_score
print(accuracy_score(digits.target, labels))

plt.show()
