import os
import matplotlib.pyplot as plt

def main() :
    print('test')
    log_file = open('4core.txt')
    lines = log_file.readlines()

    core_0 = []
    core_1 = []
    core_2 = []
    core_3 = []
    core_4 = []
    core_5 = []
    core_6 = []
    core_7 = []

    for line in lines:
        cpu_id = int(line.split("cpu = ")[1].split(",")[0])
        time = float(line.split("ms")[0].split(" : ")[1])
        print(cpu_id, time)
        if cpu_id == 0 :
            core_0.append(time)
        elif cpu_id == 1 :
            core_1.append(time)
        elif cpu_id == 2 :
            core_2.append(time)
        elif cpu_id == 3 :
            core_3.append(time)
        elif cpu_id == 4 :
            core_4.append(time)
        elif cpu_id == 5 :
            core_5.append(time)
        elif cpu_id == 6 :
            core_6.append(time)
        else :
            core_7.append(time)

    plt.cla()
    plt.ylabel('t/ms')
    plt.plot(core_0, label = 'core 0')
    plt.plot(core_1, label = 'core 1')
    plt.plot(core_2, label = 'core 2')
    plt.plot(core_3, label = 'core 3')
    plt.legend()
    plt.savefig("4core.jpg", dpi=400)



if __name__ == "__main__":
    main()
