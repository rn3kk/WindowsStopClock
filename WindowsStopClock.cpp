// WindowsStopClock.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <sysinfoapi.h>

SYSTEMTIME currentTime;
LPSYSTEMTIME lpTime;

void stopTime()
{
    while (true)
    {
      SetSystemTime(lpTime);
      std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }
}

int main()
{
    lpTime = &currentTime;
    GetSystemTime(lpTime);
   
    std::thread th(&stopTime);
    th.join();
}
