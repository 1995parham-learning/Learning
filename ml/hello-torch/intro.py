import torch

a = torch.rand(4, 4)

print(a)
print(a.shape)
print(a.flatten())
print(a.flatten(start_dim=1))

print(a.view(2, -1))

print("\n===\n")

b = torch.ones(2, 2)
print(b)
c = torch.ones(2, 2)
print(c)

r = b @ c
print(r)
print(r.shape)
