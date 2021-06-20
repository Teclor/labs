import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
from pandas import DataFrame
from sklearn.cluster import KMeans
from sklearn.datasets import make_blobs
from sklearn.manifold import TSNE
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import PolynomialFeatures


def prepare_housing_dataset(h, training_percent):
    """
    Подготавливает данные из датасета housing
    :param h pandas.DataFrame
    :param training_percent percent of training data
    """
    length = h.shape[1]
    var_quantity = 5
    train_quantity = int(np.round(length * (training_percent / 100)))
    h_prepared = {"train_data": np.empty(shape=[train_quantity, var_quantity], dtype=int),
                  "train_target": np.empty(shape=train_quantity, dtype=int),
                  "test_data": np.empty(shape=[length - train_quantity, var_quantity], dtype=int),
                  "test_target": np.empty(shape=length - train_quantity, dtype=int),
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
        h_prepared["train_data"][i] = np.ceil(row.drop("median_house_value")*10)
    for i in range(length - train_quantity):
        row = h[i]
        h_prepared["test_target"][i] = row["median_house_value"]
        h_prepared["test_data"][i] = np.ceil(row.drop("median_house_value")*10)
    return h_prepared


def get_start_points(data):
    length = len(data)
    lengthElement = len(data[0])
    minArr = np.ndarray(shape=[lengthElement, 2], dtype=int)
    maxArr = np.ndarray(shape=[lengthElement, 2], dtype=int)
    for it in range(lengthElement):
        minArr[it][0] = 0
        minArr[it][1] = 0
    for it in range(lengthElement):
        maxArr[it][0] = 0
        maxArr[it][1] = 0

    for it in range(length):
        for j in range(lengthElement):
            if data[it][j] < data[minArr[j][0]][minArr[j][1]]:
                minArr[j] = [it, j]
            if data[it][j] > data[maxArr[j][0]][maxArr[j][1]]:
                maxArr[j] = [it, j]

    return {"min": minArr, "max": maxArr}



sns.set()
housing = pd.read_csv("housing_3_flipped.csv", index_col=0)
housing.columns = housing.columns.astype(int)
prepared = prepare_housing_dataset(housing, 100)
print([np.min(prepared["train_target"]), np.max(prepared["train_target"])])

# from sklearn.preprocessing import StandardScaler
# scaler = StandardScaler()# Fit on training set only.
# scaler.fit(prepared["train_data"])# Apply transform to both the training set and the test set.
# train_scaled = scaler.transform(prepared["train_data"])

# from sklearn.decomposition import PCA# Make an instance of the Model
# pca = PCA(.95)
# pca.fit(train_scaled)
# train_scaled = pca.transform(train_scaled)

# tsne = TSNE(n_components=2, init='pca', random_state=0)
# train_scaled = tsne.fit_transform(prepared["train_data"])
# prepared['train_data'] = train_scaled
# print(prepared['train_data'])

# borders = get_start_points(prepared['train_data'])
# print(borders['min'])
# print(borders['max'])

kmeans = KMeans(n_clusters=6, random_state=45)
clusters = kmeans.fit_predict(prepared['train_data'])



from scipy.stats import mode
labels = np.zeros_like(clusters)

for i in range(6):
    mask = (clusters == i)
    labels[mask] = mode(prepared['train_target'][mask])[0]

from sklearn.metrics import accuracy_score, confusion_matrix

print([np.min(labels), np.max(labels)])
print(accuracy_score(prepared['train_target'], labels))
mat = confusion_matrix(prepared["train_target"], labels)
sns.heatmap(mat.T, square=True, annot=True, fmt='d', cbar=False,
            xticklabels=prepared["target_names"], yticklabels=prepared["target_names"])
plt.xlabel('true median house value')
plt.ylabel('predicted median house value')
plt.show()

