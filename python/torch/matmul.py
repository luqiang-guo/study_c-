import torch

m = 8
n = 12
k = 2

# a = torch.ones(m, k, dtype=torch.float32) * 2

# a = torch.arange(m*k, dtype=torch.float32).reshape(m,k)

a = torch.arange(m*k, dtype=torch.float32).reshape(k,m)
a = a.permute(1,0).contiguous().reshape(m,k)

b = torch.arange(k*n, dtype=torch.float32).reshape(k,n)
print('a : ', a.dtype)
print(a)
print('b : ', b.dtype)
print(b)

c = torch.mm(a,b)

print(c)