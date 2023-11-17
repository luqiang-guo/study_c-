import numpy as np


data = np.load('Input_1_tensor.npy')

with open('input.txt', 'w') as f4:
    np.savetxt(f4, data.reshape(-1), delimiter='\t', newline='\n')
f4.close()