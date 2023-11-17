import torch

a = torch.arange(2*2*3)
a = a.reshape(2,2,3)
print(a)
a = a.transpose(0, 1)
print(a)