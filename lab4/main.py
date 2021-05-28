import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
from sklearn.metrics import confusion_matrix
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import PolynomialFeatures
from sklearn.metrics import r2_score

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
        row = np.ceil(row.drop("median_house_value")*10)
        h_prepared["train_data"][i] = row
    for i in range(length - train_quantity):
        row = h[i]
        h_prepared["test_target"][i] = row["median_house_value"]
        row = np.ceil(row.drop("median_house_value")*10)
        h_prepared["test_data"][i] = row
    return h_prepared


def prepare_housing(h):
    size = len(h["median_house_value"])
    new_names = {
        "income": np.zeros(shape=size, dtype=float),
        #"rooms_per_house": np.zeros(shape=size, dtype=float),
        "new_house": np.zeros(shape=size, dtype=float),
        "people_per_house": np.zeros(shape=size, dtype=float),
        "median_house_value": np.zeros(shape=size, dtype=float),
        "coords_and_ocean_proximity": np.zeros(shape=size, dtype=float),
        "bedrooms_coeff": np.zeros(shape=size, dtype=float),
        # "rooms_per_people": np.zeros(shape=size, dtype=float),
    }
    ocean_map = {"NEAR BAY": 1.0, "NEAR OCEAN": 0.0, "<1H OCEAN": 2.0, "ISLAND": 3.0, "INLAND": 4.0}
    for i in range(size):
        new_names["income"][i] = (h["median_income"][i]/1.5 if h["median_income"][i]/1.5 > 5.0 else 5.0)
        # new_names["rooms_per_house"][i] = h["total_rooms"][i] / h["households"][i] if h["total_rooms"][i] / h["households"][i] <= 8.0 else 8.1
        # new_names["near_ocean"][i] = 1.0 if h["ocean_proximity"][i] == "NEAR OCEAN" else 0.0
        # new_names["near_bay"][i] = 1.0 if h["ocean_proximity"][i] == "NEAR BAY" else 0.0
        # new_names["1h_ocean"][i] = 1.0 if h["ocean_proximity"][i] == "<1H OCEAN" else 0.0
        new_names["new_house"][i] = 1.0 if h["housing_median_age"][i] <= 8.0 else 0.0
        new_names["people_per_house"][i] = np.round(h["population"][i] / h["households"][i])
        new_names["median_house_value"][i] = h["median_house_value"][i]
        new_names["coords_and_ocean_proximity"][i] = ((h["longitude"][i] + 360 + h["latitude"][i]) * ocean_map[h["ocean_proximity"][i]])
        new_names["bedrooms_coeff"][i] = np.round(h["total_bedrooms"][i] / h["total_rooms"][i] if not np.isnan(h["total_bedrooms"][i]) else 1.0)
        # new_names["rooms_per_people"][i] = np.round(h["total_rooms"][i]/h["households"][i])

    dataset = pd.DataFrame(new_names)
    return dataset

def flip_csv(name, dataset=pd.DataFrame({})):
    """
    Меняет местами столбцы и строки в csv файле
    :param name string название файла без расширения
    :param dataset pd.DataFrame название файла без расширения
    """
    df = pd.read_csv(name + ".csv", index_col=0) if dataset.empty else dataset
    df = df.T.groupby(level=0).agg(lambda x: x.values.tolist()).stack().apply(pd.Series).unstack().sort_index(level=1,
                                                                                                              axis=1)
    df.columns = df.columns.droplevel(level=0)
    df.to_csv(path_or_buf=name + "_flipped.csv")


sns.set()
# housing_casual = pd.read_csv("../2lab/housing.csv")
# housing_casual = prepare_housing(housing_casual)
#
# flip_csv("housing_new", housing_casual)

housing = pd.read_csv("housing_new_flipped.csv", index_col=0)
housing.columns = housing.columns.astype(int)
prepared = prepare_housing_dataset(housing, 80)
x = prepared['train_data']
y = prepared['train_target']
print(y)
from sklearn.linear_model import LinearRegression
model = LinearRegression(fit_intercept=True)
model.fit(x, y)
labels = model.predict(prepared['test_data'])
print(prepared["test_target"])
print(r2_score(prepared["test_target"], labels))
# mat = confusion_matrix(prepared["test_target"], labels)
# sns.heatmap(mat.T, square=True, annot=True, fmt='d', cbar=False,
#             xticklabels=prepared["target_names"], yticklabels=prepared["target_names"])
# plt.xlabel('true median house value')
# plt.ylabel('predicted median house value')
print("Model slope: ", model.coef_)
print("Model intercept:", model.intercept_)

