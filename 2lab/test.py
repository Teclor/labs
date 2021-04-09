import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
from sklearn.model_selection import cross_val_score
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import confusion_matrix
import random
import sys


def remove_key(d, key):
    r = dict(d)
    del r[key]
    return r


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


def prepare_row(row):
    """
    returns a row with needed values
    :param row: row of data
    :return: np.array of data
    """
    return np.array([
        row["median_income"] if row["median_income"] > 5.0 else 5.0,
        # row["housing_median_age"],
        row["total_rooms"] / row["households"] if row["total_rooms"] / row["households"] <= 8.0 else 8.1,
        # row["population"] / row["total_rooms"],
        # row["total_bedrooms"] / row["total_rooms"],
        # row["population"] / row["households"],
        # row["latitude"],
        # row["longitude"] + 360,
        # row["ocean_proximity"],
        1.0 if row["ocean_proximity"] == 0.0 else 0.0,
        1.0 if row["ocean_proximity"] == 1.0 else 0.0,
        1.0 if row["ocean_proximity"] == 2.0 else 0.0,

        1.0 if row["housing_median_age"] <= 10.0 else 0.0,
        # 1.0 if (10.0 < row["housing_median_age"] <= 25.0) else 0.0,
    ], dtype=float)


def get_prepared_row(row):
    """
    returns a row with needed values
    :param row: row of data
    :return: np.array of data
    """
    return np.array([

    ], dtype=float)


def prepare_housing_dataset(h, training_percent):
    """
    Подготавливает данные из датасета housing
    :param h pandas.DataFrame
    :param training_percent percent of training data
    """
    length = h.shape[1]
    var_quantity = 6
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


def calculate_accuracy(predicted, real):
    """
    calculates accuracy
    :param predicted: predicted values
    :param real: real values
    :return: count predicted==true divided by count real
    """
    arr_len = len(predicted)
    correct = 0
    for i in range(arr_len):
        if predicted[i] == real[i]:
            correct += 1
    return correct / arr_len


def calculate_houses_in_price_range(res):
    """
    calculates number of data in each price
    :param res: array of prices
    :return: array of number of prices presented
    """
    vals = {0.0: 0, 1.0: 0, 2.0: 0, 3.0: 0, 4.0: 0, 5.0: 0}
    for val in res:
        vals[val] += + 1
    return vals


def addrow(h):
    length = len(h["ocean_proximity"])
    tmp = np.zeros(shape=length)
    near_bay_tmp = {"NEAR BAY": 1.0, "NEAR OCEAN": 0.0, "<1H OCEAN": 2.0, "ISLAND": 4.0, "INLAND": 5.0}
    for i in range(length):
        tmp[i] = near_bay_tmp[h["ocean_proximity"][i]]
    h["ocean_proximity"] = tmp
    return h


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
        "rooms_per_people": np.zeros(shape=size, dtype=float),
    }
    ocean_map = {"NEAR BAY": 1.0, "NEAR OCEAN": 0.0, "<1H OCEAN": 2.0, "ISLAND": 3.0, "INLAND": 4.0}
    for i in range(size):
        new_names["income"][i] = h["median_income"][i]/1.5 if h["median_income"][i]/1.5 > 5.0 else 5.0
        # new_names["rooms_per_house"][i] = h["total_rooms"][i] / h["households"][i] if h["total_rooms"][i] / h["households"][i] <= 8.0 else 8.1
        # new_names["near_ocean"][i] = 1.0 if h["ocean_proximity"][i] == "NEAR OCEAN" else 0.0
        # new_names["near_bay"][i] = 1.0 if h["ocean_proximity"][i] == "NEAR BAY" else 0.0
        # new_names["1h_ocean"][i] = 1.0 if h["ocean_proximity"][i] == "<1H OCEAN" else 0.0
        new_names["new_house"][i] = 1.0 if h["housing_median_age"][i] <= 8.0 else 0.0
        new_names["people_per_house"][i] = np.round(h["population"][i] / h["households"][i])
        new_names["median_house_value"][i] = np.round(h["median_house_value"][i] / 100000)
        new_names["coords_and_ocean_proximity"][i] = (h["longitude"][i] + 360 + h["latitude"][i]) * ocean_map[h["ocean_proximity"][i]]
        new_names["bedrooms_coeff"][i] = np.round(h["total_bedrooms"][i] / h["total_rooms"][i] if not np.isnan(h["total_bedrooms"][i]) else 1.0)
        new_names["rooms_per_people"][i] = np.round(h["total_rooms"][i]/h["households"][i])

    dataset = pd.DataFrame(new_names)
    return dataset


def main():
    sns.set()
    fig, ax = plt.subplots(figsize=(16, 9))
    ax.xaxis.set_tick_params(labeltop='on', labelbottom=False)
    sns.set_theme(style="white")
    housing_casual = pd.read_csv("housing.csv")
    # housing_casual = addrow(housing_casual)
    housing_casual = prepare_housing(housing_casual)
    corr = housing_casual.drop("median_house_value", axis=1).corr()
    sns.heatmap(corr, linewidths=.5, cbar_kws={"shrink": .5}, annot=True)

    plt.show()

    # flip_csv("housing_new", housing_casual)


    # housing_casual = addrow(housing_casual)
    # # housing_casual = prepare_housing(hoлажноusing_casual)
    # descr = housing_casual.describe()
    # pd.set_option('display.max_rows', None)
    # pd.set_option('display.max_columns', None)
    # pd.set_option('display.width', None)
    # pd.set_option('display.max_colwidth', None)
    # print(descr)

    # ocean_values = {"NEAR BAY": float(1.0), "<1H OCEAN": float(2.0), "NEAR OCEAN": float(0.0), "ISLAND": float(3.0), "INLAND": float(4.0)}
    # length = len(housing_casual["ocean_proximity"])
    # tmpArr = np.zeros(length)
    # for i in range(length):
    #     tmpArr[i] = ocean_values[housing_casual["ocean_proximity"][i]]
    # housing_casual["ocean_proximity"] = tmpArr

    # corr_matrix = housing_casual.corr()
    # corr_matrix["median_house_value"].sort_values(ascending=False)
    # print(corr_matrix["median_house_value"])

    # sns.heatmap(mat.T, square=True, annot=True, fmt='d', cbar=False,
    # xticklabels=prepared["target_names"], yticklabels=prepared["target_names"])

    # from pandas.plotting import scatter_matrix
    # attributes = ["median_house_value", "median_income", "total_rooms", "housing_median_age"]
    # scatter_matrix(housing_casual[attributes], figsize=(12,8))
    # housing_casual.plot(kind="scatter", x="rooms_per_house", y="median_house_value", alpha=0.1)
    # plt.show()

    plt.figure(figsize=(16, 9))
    housing = pd.read_csv("housing_new_flipped.csv", index_col=0)
    housing.columns = housing.columns.astype(int)
    prepared = prepare_housing_dataset(housing, 80)

    # обучение модели и вывод

    model = MultinomialNB()
    model.fit(prepared["train_data"], prepared["train_target"])

    labels = model.predict(prepared["test_data"])
    accuracy = calculate_accuracy(labels, prepared["test_target"]) * 100
    print("Accuracy: " + format(accuracy, '.2f') + "%")

    mat = confusion_matrix(prepared["test_target"], labels)
    sns.heatmap(mat.T, square=True, annot=True, fmt='d', cbar=False,
    xticklabels=prepared["target_names"], yticklabels=prepared["target_names"])
    plt.xlabel('true median house value')
    plt.ylabel('predicted median house value')
    plt.show()

    # house_params = [[8.3252, 41, 6.98412698, 1.02380952, 322,
    # 2.55555556, 37.88, 237.77, 4.0]]
    # print(model.predict(house_params)[0])


if __name__ == "__main__":
    main()

    # print(calculate_houses_in_price_range(prepared["train_target"]))
    # {0.0: 160, 1.0: 6112, 2.0: 6025, 3.0: 2208, 4.0: 1042, 5.0: 965}
    # print(calculate_houses_in_price_range(prepared["test_target"]))
    # {0.0: 111, 1.0: 1990, 2.0: 1280, 3.0: 445, 4.0: 197, 5.0: 105}