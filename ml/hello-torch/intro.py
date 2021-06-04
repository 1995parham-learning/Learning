import torch

a = torch.rand(4, 4)

print(a)
print(a.shape)
print(a.flatten())
print(a.flatten(start_dim=1))

print(a.view(2, -1))
