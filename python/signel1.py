import signal
import sys
import os
 
flags = 0
# 定义处理Control-C信号的函数
def signal_handler(sig, frame):
    flags = 1

# 注册信号处理程序
signal.signal(signal.SIGINT, signal_handler)
 
# 进入死循环，等待接收Control-C信号
print('Press Ctrl+C to exit')
while True:
    if flags == 1:
        os.exit(-1)
    os.system('echo "Command" && sleep 5')  # 第一个命令
