import math

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sklearn
import sklearn.linear_model
import sklearn.neighbors


# Загрузить данные
oecd_bli = pd.read_csv("oecd_bli_2015.csv", thousands=',')
gdp_per_capita = pd.read_csv("gdp_per_capita.csv", thousands=',', delimiter='\t', encoding='latin1', na_values="n/a")

def prepare_country_stats(oecd_bli, gdp_per_capita):
    oecd_bli = oecd_bli[oecd_bli["INEQUALITY"] == "TOT"]
    oecd_bli = oecd_bli.pivot(index="Country", columns="Indicator", values="Value")
    gdp_per_capita.rename(columns={"2015": "GDP per capita"}, inplace=True)
    gdp_per_capita.set_index("Country", inplace=True)
    full_country_stats = pd.merge(left=oecd_bli, right=gdp_per_capita,
                                  left_index=True, right_index=True)
    full_country_stats.sort_values(by="GDP per capita", inplace=True)
    remove_indices = [0, 1, 6, 8, 33, 34, 35]
    keep_indices = list(set(range(36)) - set(remove_indices))
    return full_country_stats[["GDP per capita", 'Life satisfaction']].iloc[keep_indices]


def estimate_coef(x, y):
    n = np.size(x)
    mid_x, mid_y = np.mean(x), np.mean(y)
    # перекрёстное отклонение
    SS_xy = np.sum(y * x) - n * mid_y * mid_x
    # отклонение по x
    SS_xx = np.sum(x * x) - n * mid_x * mid_x
    # вычисление коэффициентов регрессии
    B1 = SS_xy / SS_xx
    B0 = mid_y - B1 * mid_x

    return B0, B1


def custom_regression_predict(X, Y, x_new):
    b = estimate_coef(X, Y)
    res = b[0] + b[1] * x_new
    return res


def custom_neighbors(X, Y, x_new, k):
    x_len = np.zeros((len(X), 2))

    for i in range(len(X)):
        x_len[i][0] = abs(x_new - X[i][0])
        x_len[i][1] = i
    x_len = sorted(x_len, key=lambda x: x[0])

    res_arr = np.zeros(k)
    for i in range(k):
        res_arr[i] = Y[int(round(x_len[i][1]))]
    res = np.mean(res_arr)

    return res



# Подготовить данные
country_stats = prepare_country_stats(oecd_bli, gdp_per_capita)
X = np.c_[country_stats["GDP per capita"]]
y = np.c_[country_stats["Life satisfaction"]]
# Визуализировать данные
# country_stats.plot(kind='scatter', x="GDP per capita", y='Life satisfaction')
#plt.show()

# Выработать прогноз для КИпра
X_new = [[22587]]

print("Sklearn linear regression result:")
model = sklearn.linear_model.LinearRegression()
model.fit(X, y)
print(model.predict(X_new)[0][0])

print("Custom linear regression result:")
print(custom_regression_predict(X, y, X_new[0][0]))

print("Sklearn k-neighbours result:")
model = sklearn.neighbors.KNeighborsRegressor(n_neighbors=3)
model.fit(X, y)
print(model.predict(X_new)[0][0])

print("Custom k-neighbours result:")
print(custom_neighbors(X, y, X_new[0][0], 3))

# ВВП на душу населения Кипра
# выводит [[5.96242338]]