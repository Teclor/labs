import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np



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


sns.set()
# housing = pd.read_csv("housing_new_flipped.csv", index_col=0)
# housing.columns = housing.columns.astype(int)
# prepared = prepare_housing_dataset(housing, 80)

rng = np.random.RandomState(1)
x = 10 * rng.rand(50)
y = 2 * x - 5 + rng.randn(50)
plt.scatter(x, y)

from sklearn.linear_model import LinearRegression
model = LinearRegression(fit_intercept=True)
model.fit(x[:, np.newaxis], y)
xfit = np.linspace(0, 10, 1000)
yfit = model.predict(xfit[:, np.newaxis])
plt.scatter(x, y)
plt.plot(xfit, yfit)
print("Model slope: ", model.coef_[0])
print("Model intercept:", model.intercept_)

from sklearn.linear_model import LinearRegression
model = LinearRegression(fit_intercept=True)
rng = np.random.RandomState(1)
X = 10 * rng.rand(100, 3)
y = 0.5 + np.dot(X, [1.5, -2., 1.])
model.fit(X, y)
print(model.intercept_)
print(model.coef_)

from sklearn.preprocessing import PolynomialFeatures
x = np.array([2, 3, 4])
poly = PolynomialFeatures(5, include_bias=False)
print(poly.fit_transform(x[:, None]))

from sklearn.pipeline import make_pipeline
poly_model = make_pipeline(PolynomialFeatures(7), LinearRegression())


rng = np.random.RandomState(1)
x = 10 * rng.rand(50)
y = np.sin(x) + 0.1 * rng.randn(50)
print(x[:, np.newaxis])
poly_model.fit(x[:, np.newaxis], y)
yfit = poly_model.predict(xfit[:, np.newaxis])
plt.scatter(x, y)
plt.plot(xfit, yfit)


