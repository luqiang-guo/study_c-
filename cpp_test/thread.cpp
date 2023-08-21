#include <mutex>
#include <unistd.h>
#include <thread>

int g_i = 0;
std::mutex g_i_mutex;  // protects g_i

std::mutex mtx;

void safe_increment(int threadID)
{
    for (size_t i = 0; i < 20; i++)
    {
        //std::lock_guard<std::mutex> lock(g_i_mutex);
        mtx.lock();
        ++g_i;
        printf("threadID:% d   gi : % d \n" ,  threadID, g_i);
        mtx.unlock();
        //usleep(1);
    }
    // g_i_mutex is automatically released when lock
    // goes out of scope
}

int main()
{
    int count = std::thread::hardware_concurrency();
    printf("CPU cores: %d \n", count);
    std::thread t1(safe_increment , 1);
    std::thread t2(safe_increment , 2);
    std::thread t3(safe_increment , 3);
    std::thread t4(safe_increment , 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}