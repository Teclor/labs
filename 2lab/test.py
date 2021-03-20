import pandas as pd
import numpy as np
length = 10
a = np.array([
       0/3,
       1/2,
       2 if True else 3
]
)
print(np.empty(shape=[length, 8], dtype=float))
"""
import numpy as np
rng = np.random.RandomState(1)
X = rng.uniform(5, size=(6, 100))
print(type(X) == np.ndarray)
y = np.array([1, 2, 3, 4, 5, 6])
from sklearn.naive_bayes import MultinomialNB
clf = MultinomialNB()
clf.fit(X, y)
print(clf.predict(X[2:3]))
"""