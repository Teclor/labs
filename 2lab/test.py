import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import confusion_matrix
import random


def flip_csv(name):
    """
    Меняет местами столбцы и строки в csv файле
    :param name string название файла без расширения
    """
    df = pd.read_csv(name + ".csv", index_col=0)
    df = df.T.groupby(level=0).agg(lambda x: x.values.tolist()).stack().apply(pd.Series).unstack().sort_index(level=1,
                                                                                                              axis=1)
    df.columns = df.columns.droplevel(level=0)
    df.to_csv(path_or_buf=name + "_flipped.csv")


def prepare_housing_dataset(h, training_percent):
    """
    Подготавливает данные из датасета housing
    :param h pandas.DataFrame
    :param training_percent percent of training data
    """
    ocean_values = {"NEAR BAY": float(10000.0), "<1H OCEAN": float(20000.0), "NEAR OCEAN": float(0.0), "ISLAND": float(30000.0), "INLAND": float(40000.0)}
    length = h.shape[1]
    for i in range(length):
        h[i]["ocean_proximity"] = ocean_values[h[i]["ocean_proximity"]]

    var_quantity = 4
    train_quantity = int(np.round(length * (training_percent / 100)))
    h_prepared = {"train_data": np.empty(shape=[train_quantity, var_quantity], dtype=float),
                  "train_target": np.empty(shape=train_quantity, dtype=float),
                  "test_data": np.empty(shape=[length-train_quantity, var_quantity], dtype=float),
                  "test_target": np.empty(shape=length-train_quantity, dtype=float),
                  "names": np.array([
                      "rooms_per_household",
                      "people_per_room",
                      "ocean_proximity",
                  ]),
                  "target_names": np.array(
                      ["<50000$", "50 000-150 000 $", "150 000-250 000 $", "250 000-350 000 $", "350 000-450 000 $",
                       "450 000-550 000 $"])
                  }
    for i in range(train_quantity):
        row = h[i].astype(float)
        if np.isnan(row["total_bedrooms"]):
            row["total_bedrooms"] = 0
        h_prepared["train_target"][i] = np.round(row["median_house_value"] / 100000)
        h_prepared["train_data"][i] = get_prepared_row(row)
    for i in range(length-train_quantity):
        row = h[i].astype(float)
        if np.isnan(row["total_bedrooms"]):
            row["total_bedrooms"] = 0
        h_prepared["test_target"][i] = np.round(row["median_house_value"] / 100000)
        h_prepared["test_data"][i] = get_prepared_row(row)
    return h_prepared


def get_prepared_row(row):
    """
    returns a row with needed values
    :param row: row of data
    :return: np.array of data
    """
    return np.array([
            # row["median_income"],
            # row["housing_median_age"],
            row["total_rooms"] / row["households"],
            row["population"] / row["total_rooms"],
            row["total_bedrooms"] / row["total_rooms"],
            # row["latitude"],
            # row["longitude"] + 360,
            row["ocean_proximity"],
        ], dtype=float)


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


def main():
    res = 0.0
    for i in range(100):
        res += 1/(2**i)
    print(res)


if __name__ == "__main__":
    main()
