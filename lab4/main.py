import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics import confusion_matrix
from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import PolynomialFeatures
from sklearn.metrics import r2_score
import re
from sklearn.model_selection import train_test_split


def prepare_cars_dataset(ds):
    length = ds.shape[0]
    strLength = ds.shape[1]
    prepared = {
        "year": np.empty(shape=length, dtype=int),
        "selling_price": np.empty(shape=length, dtype=int),
        "km_driven": np.empty(shape=length, dtype=int),
        "fuel": np.empty(shape=length, dtype=int),
        "seller_type": np.empty(shape=length, dtype=int),
        "transmission": np.empty(shape=length, dtype=int),
        "owner": np.empty(shape=length, dtype=int),
        "mileage": np.empty(shape=length, dtype=float),
        "engine": np.empty(shape=length, dtype=int),
        "max_power": np.empty(shape=length, dtype=int),
        "torque": np.empty(shape=length, dtype=int),
        "seats": np.empty(shape=length, dtype=int),
    }
    for i in range(length):
        row = ds.iloc[i]
        print(row)
        vectorizer = TfidfVectorizer()

        # vectorizer.fit(ds["name"].tolist())
        # print(vectorizer.vocabulary)
        # print(vectorizer.idf_)
        # vector = vectorizer.transform(ds["name"].tolist())
        # # summarize encoded vector
        # print(vector.shape)
        # print(vector.toarray()[0])
        break


def show_corr_matrix(ds, corr_val):
    corr_matrix = ds.corr()
    corr_matrix[corr_val].sort_values(ascending=False)
    print(corr_matrix[corr_val])
    corr_matrix.plot()
    plt.show()


def show_scatter_matrix(ds):
    from pandas.plotting import scatter_matrix
    attributes = ["year", "km_driven", "seats"]
    scatter_matrix(ds[attributes], figsize=(12,8))
    ds.plot(kind="scatter", x="year", y="selling_price", alpha=0.1)
    plt.show()


def show_confusion_matrix(ds):
    mat = confusion_matrix(ds.select_dtypes(['number']), ds.select_dtypes(['number']))
    sns.heatmap(mat.T, square=True, annot=True, fmt='d', cbar=False, xticklabels='data', yticklabels='data')
    plt.show()


def get_values_as_numbers(col):
    unique = col.unique()
    unique_indices = {}
    for i, v in enumerate(unique):
        unique_indices[v] = i+1  # присваиваем уникальные ключи

    return list(map(lambda x: unique_indices[x], col.tolist()))


def get_num_from_string(in_str, get_first=True):
    num = 0
    for n in in_str.split():
        try:
            num += float(n)
            if get_first:
                break
        except ValueError:
            continue
    return num


def get_torque(in_str):
    num = 0
    matches = re.findall('\d+', in_str)
    if len(matches) == 3:
        try:
            num = float(matches[0]) * (float(matches[1]) + float(matches[2])) / 2
        except ValueError:
            return num
    elif len(matches) == 2:
        try:
            num = float(matches[0]) * float(matches[1])
        except ValueError:
            return num
    else:
        try:
            num = float(matches[0])
        except ValueError:
            return num
    return num


def clean_dataset(ds):
    ds = ds.drop(columns=['name'])
    ds = ds[~pd.isnull(ds).any(axis=1)]  # очищаем датасет от пустых значений

    ds['fuel'] = get_values_as_numbers(ds['fuel'])
    ds['owner'] = get_values_as_numbers(ds['owner'])
    ds['seller_type'] = get_values_as_numbers(ds['seller_type'])
    ds['transmission'] = get_values_as_numbers(ds['transmission'])
    ds['mileage'] = [get_num_from_string(s) for s in ds['mileage']]
    ds['engine'] = [get_num_from_string(s) for s in ds['engine']]
    ds['max_power'] = [get_num_from_string(s) for s in ds['max_power']]
    ds['torque'] = [get_torque(s) for s in ds['torque']]

    return ds


sns.set()

pd.set_option('display.max_columns', None)
pd.set_option('display.max_rows', None)

cars = pd.read_csv("Car_details_v3.csv")



cars = clean_dataset(cars)
# show_corr_matrix(cars, 'selling_price')
# show_confusion_matrix(cars)

y = cars['selling_price']
x = cars.drop(columns='selling_price')

X_train, X_test, y_train, y_test = train_test_split(x, y, test_size=0.2, random_state=45)


from sklearn.linear_model import LinearRegression
# model = LinearRegression(fit_intercept=True)
#
# model.fit(X_train, y_train)
# # print("Model slope: ", model.coef_[0])
# # print("Model intercept:", model.intercept_)
#
# y_predicted = model.predict(X_test)
#
#
# print("SCORE casual:")
# print(r2_score(y_test, y_predicted))

poly_model = make_pipeline(PolynomialFeatures(2), LinearRegression())

poly_model.fit(X_train, y_train)

y_poly = poly_model.predict(X_test)

print("SCORE:")
print(r2_score(y_test, y_poly))

poly_model = make_pipeline(PolynomialFeatures(2), LinearRegression())

poly_model.fit(X_train, y_train)

y_poly = poly_model.predict(X_test)