import torch

y_kown = torch.Tensor([10, 20])

x = torch.Tensor([[2, 4], [6, 8]])
m = torch.randn(2, requires_grad=True)
b = torch.randn(1, requires_grad=True)

y = m * x + b

loss = (torch.sum(y_kown - y)) ** 2
loss.backward()

print(m.grad)
