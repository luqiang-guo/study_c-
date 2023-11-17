import torch

# # 1
# a = torch.arange(4, dtype=torch.float)
# print('___________1_____________')
# print(a)
# b = torch.nn.functional.softmax(a)
# print(b)

# # 2
# a = torch.arange(4, dtype=torch.float).reshape(2,2)
# print('___________2_____________')
# print(a)
# b = torch.nn.functional.softmax(a, dim=0)
# print(b)
# b = torch.nn.functional.softmax(a, dim=1)
# print(b)

# # 3
# a = torch.arange(2*3*4, dtype=torch.float).reshape(2,3,4)
# # a = torch.tensor([0, 2, 1, 3, 5, 4, 7, 6], dtype=torch.float).reshape(2,2,2)
# print('___________3_____________')
# print(a)
# b = torch.nn.functional.softmax(a, dim=0)
# print(b.shape, b)
# b = torch.nn.functional.softmax(a, dim=1)
# print(b.shape, b)
# b = torch.nn.functional.softmax(a, dim=2)
# print(b.shape, b)

a = torch.arange(2*2*2, dtype=torch.float).reshape(2,2,2)
b = a.permute(1,2,0).contiguous()
print(a)
print(b)