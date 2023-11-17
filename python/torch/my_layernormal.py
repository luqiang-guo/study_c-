import numpy as np


def welford_update(count, mean, M2, currValue):
    count += 1
    delta = currValue - mean
    mean += delta / count
    delta2 = currValue - mean
    M2 += delta * delta2
    return (count, mean, M2)


def naive_update(sum, sum_square, currValue):
    sum = sum + currValue
    sum_square = sum_square + currValue * currValue
    return (sum, sum_square)


x_arr = np.random.randn(100000).astype(np.float32)

welford_mean = 0
welford_m2 = 0
welford_count = 0
for i in range(len(x_arr)):
    new_val = x_arr[i]
    welford_count, welford_mean, welford_m2 = welford_update(welford_count, welford_mean, welford_m2, new_val)
print(type(welford_mean))
print(type(welford_m2))
print("Welford mean: ", welford_mean)
print("Welford var: ", welford_m2 / welford_count)

naive_sum = 0
naive_sum_square = 0
for i in range(len(x_arr)):
    new_val = x_arr[i]
    naive_sum, naive_sum_square = naive_update(naive_sum, naive_sum_square, new_val)
naive_mean = naive_sum / len(x_arr)
naive_var = naive_sum_square/ len(x_arr) - naive_mean*naive_mean
print(type(naive_mean))
print(type(naive_var))
print("Naive mean: ", naive_mean)
print("Naive var: ", naive_var)
