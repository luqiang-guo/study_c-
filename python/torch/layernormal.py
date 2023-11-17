import torch
import torch.nn as nn

# # NLP Example
# batch, sentence_length, embedding_dim = 2, 3, 4
# embedding = torch.randn(batch, sentence_length, embedding_dim)
# print('embedding : ')
# print(embedding)

# layer_norm = nn.LayerNorm(embedding_dim)
# # Activate module
# out = layer_norm(embedding)
# print('out : ')
# print(out)

# Image Example
N, C, H, W = 2, 3, 4, 4
input = torch.randn(N, C, H, W)
print(input)
# Normalize over the last three dimensions (i.e. the channel and spatial dimensions)
# as shown in the image below
layer_norm = nn.LayerNorm([C, H, W])
output = layer_norm(input)
print(output)
