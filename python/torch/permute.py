import torch


a =  torch.arange(6).reshape(1,2,1,3)
print(a)

b = a.permute(0,2,1,3)
print(b)