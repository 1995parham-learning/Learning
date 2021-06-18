import torch

# create a random 4x4 tensor.
a = torch.rand(4, 4)

# print the tensor values.
print(a)
# print the tensor shape.
print(a.shape)
# keep the first dimension and remove the other dimensions.
print(a.flatten())
# keep first and second dimensions and remove the otherones.
print(a.flatten(start_dim=1))

# create a view from tensor.
print(a.view(2, -1))

# create a 2x2 tensor with all elements equal to one.
b = torch.ones(2, 2)
print(b)
c = torch.ones(2, 2)
print(c)

# matrix multiplication which its result depends to the inputs dimension.
r = b @ c
print(r)
print(r.shape)
