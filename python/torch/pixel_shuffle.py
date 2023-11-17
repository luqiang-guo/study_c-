import torch
import torch.nn as nn

pixel_shuffle = nn.PixelShuffle(2)
input = torch.arange(16)
input = input.reshape(1, 4, 2, 2)
print(input)
output = pixel_shuffle(input)
print(output.size())
print(output)