import numpy as np


x1 = np.random.normal(176.4, 6, 110)
x2 = np.random.normal(164, 5, 90)

x3 = np.append(x1, x2)

np.random.shuffle(x3)
print(x3)