import os
import signal
import time

def signal_handler(signal, frame):
    print('You pressed Ctrl+C!')
    exit(0)

signal.signal(signal.SIGINT, signal_handler)

# 运行命令
# time.sleep(10)
os.system('echo "Command 1" && sleep 5')  # 第一个命令
os.system('echo "Command 2" && sleep 5')  # 第二个命令
os.system('echo "Command 3" && sleep 5')  # 第三个命令

print('Press Ctrl+C')
signal.pause()