import time
import pandas as pd
from impyute.imputation.cs import mice
import numpy as np

car_data = pd.read_csv("cars_craigslist_mice_ready.csv")

for i in range(1, 11):
    start_time = time.perf_counter()
    print("starting for " + str(i))
    imputed_training = mice(car_data[0:1000*i].values)
    print("f(" + str(5000*i) + ") = " + str(time.perf_counter() - start_time))

