import numpy as np

alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя "
alphLen = len(alphabet)
arr = dict()
for i in alphabet:
    arr[i] = alphabet.index(i)
f = open("input.txt", "r")
fileCont = f.read()
matDef = np.array([[3, 18], [29, 27]])
matElem = np.array([[0, ], [0, ]])
step = 0
letters = []
for i in fileCont:
    matElem[step, 0] = arr[i]
    step += 1
    if step == 2:
        res = matDef.dot(matElem)
        letters.append(alphabet[(res[0, 0] % alphLen)])
        letters.append(alphabet[(res[1, 0] % alphLen)])
        step = 0
f.close()
f = open("output.txt", "w")
for letter in letters:
    f.write(letter)
f.close()


