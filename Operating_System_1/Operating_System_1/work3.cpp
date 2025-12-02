#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
const int buffer_size = 10;
int buffer[buffer_size];
int input_idx=0;
int output_idx = 0;
int count = 0;

CRITICAL_SECTION cs;                // 临界区：保护缓冲区
HANDLE emptySemaphore;              // 空槽计数
HANDLE fullSemaphore;

int randomSleep() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(200, 600);
    return dist(gen);
}

void producer(int startvalue)
{
    while (true) {
        int data = startvalue + rand() % 1000;
        WaitForSingleObject(emptySemaphore, INFINITE);
        EnterCriticalSection(&cs);
        buffer[input_idx] = data;
        count++;
        std:: cout << " 生产数据: " << data
            << "  写入位置: " << input_idx 
            <<" 缓冲区个数:" << count<<std::endl;
        std::cout << std::endl;
        input_idx = (++input_idx) % buffer_size;

        LeaveCriticalSection(&cs);
        ReleaseSemaphore(fullSemaphore, 1, NULL);
        std::this_thread::sleep_for(std::chrono::milliseconds(randomSleep()));
    }
}

void consumer()
{
    while (true)
    {
        int data=0;
        WaitForSingleObject(fullSemaphore, INFINITE);
        EnterCriticalSection(&cs);
        data=buffer[output_idx];
        count--;

        std::cout << " 消费数据:" << data <<
            " 读取位置：" << output_idx 
            << " 缓冲区个数:" << count << std::endl;

        std::cout << std::endl;
        output_idx = (++output_idx) % buffer_size;

        LeaveCriticalSection(&cs);
        ReleaseSemaphore(emptySemaphore, 1, NULL);
        std::this_thread::sleep_for(std::chrono::milliseconds(randomSleep()));



    }
}


int main()
{
    InitializeCriticalSection(&cs);
    emptySemaphore = CreateSemaphore(NULL, buffer_size, buffer_size, NULL);
    fullSemaphore = CreateSemaphore(NULL, 0, buffer_size, NULL);
    std::thread p1(producer, 1000);
    std::thread p2(producer, 2000);
    std::thread c1(consumer);
    std::thread c2(consumer);
    std::thread c3(consumer);
    p1.join();
    p2.join();
    c1.join();
    c2.join();
    c3.join();
    DeleteCriticalSection(&cs);
    CloseHandle(emptySemaphore);
    CloseHandle(fullSemaphore);
}





