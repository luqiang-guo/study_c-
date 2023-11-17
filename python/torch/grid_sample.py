import torch
import numpy as np
 
def grid_sample(input, grid):
    N, C, H_in, W_in = input.shape
    N, H_out, W_out, _ = grid.shape
    output = np.random.random((N, C, H_out, W_out))
    for i in range(N):
        for j in range(C):
            for k in range(H_out):
                for l in range(W_out):
                    x, y = grid[i][k][l][0], grid[i][k][l][1]
                    param = [0.0, 0.0]
                    param[0] = (W_in - 1) * (x + 1) / 2
                    param[1] = (H_in - 1) * (y + 1) / 2
                    x1 = int(param[0] + 1)
                    x0 = x1 - 1
                    y1 = int(param[1] + 1)
                    y0 = y1 - 1
                    param[0] = abs(param[0] - x0)
                    param[1] = abs(param[1] - y0)
                    left_top_value, left_bottom_value, right_top_value, right_bottom_value = 0, 0, 0, 0
                    if 0 <= x0 < W_in and 0 <= y0 < H_in:
                        left_top_value = input[i][j][y0][x0]
                    if 0 <= x1 < W_in and 0 <= y0 < H_in:
                        right_top_value = input[i][j][y0][x1]
                    if 0 <= x0 < W_in and 0 <= y1 < H_in:
                        left_bottom_value = input[i][j][y1][x0]
                    if 0 <= x1 < W_in and 0 <= y1 < H_in:
                        right_bottom_value = input[i][j][y1][x1]
                    left_top = left_top_value * (1 - param[0]) * (1 - param[1])
                    left_bottom = left_bottom_value * (1 - param[0]) * param[1]
                    right_top = right_top_value * param[0] * (1 - param[1])
                    right_bottom = right_bottom_value * param[0] * param[1]
                    result = left_bottom + left_top + right_bottom + right_top
                    output[i][j][k][l] = result
    return output
 
 
N, C, H_in, W_in = 1, 1, 6, 6
H_out, W_out = 4, 4
input = np.random.random((N, C, H_in, W_in))
grid = np.random.random((N, H_out, W_out, 2))
grid[0][0][0] = [-1.2, 1.3]
out = grid_sample(input, grid)
print(f'自定义实现输出结果: \n{out}')
input = torch.from_numpy(input)
grid = torch.from_numpy(grid)
output = torch.nn.functional.grid_sample(input, grid, mode='bilinear', padding_mode='zeros', align_corners=True)
print(f'grid_sample输出结果:\n{output}')
 