import numpy as np
import struct

# a = torch.ones(5, dtype= torch.bfloat16, device='cpu')

LOG2EF = 1.44269504088896341
LN2 = 0.69314718056

F_MASK = 0x807FFFFF


def float_to_uint32(num):
    bytes_obj = struct.pack('<f', num)
    uint32 = int.from_bytes(bytes_obj, byteorder='little', signed=False)
    return uint32


def bf16_exp_int(x):

    #  e^x = 2^i * 2^f, f in [-½, ½],
    #  e^x = 2^i * e^f, f in [-½log 2, ½log 2]
    #  i = floor (log2(e) * x),  f = i 
    #  e^f => x + 1

    i = LOG2EF * x
    int_i = int(i + 0.5)

    f = x - int_i * LN2
    ef = f + 1

    ef = ef & F_MASK
    int_i = ((int_i + 127) << 23) & (~F_MASK)
    
    v = ef | int_i

    return v

def main():
    v = 2.5
    tmp = float_to_uint32(v)
    print(tmp)

if __name__ == "__main__":
    main()


