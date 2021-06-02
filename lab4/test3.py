import numpy as np

data = np.array( [[ 0.,   1.,  2.,  3., 0.],])

key = np.array([[ 0., 'S'],
                [ 1., 'S'],
                [ 2., 'S'],
                [ 3., 'M'],])

idx = np.array(key[:,0], dtype=float).astype(int)
n = idx.max()+1
keyarray = np.empty(n, dtype=key[:,1].dtype)
keyarray[:] = ''
keyarray[idx] = key[:,1]
print(keyarray)

data = data.astype('int')
print(data)
print(keyarray[data])