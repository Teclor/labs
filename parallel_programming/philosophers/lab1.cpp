#include <iostream>
#include <fstream>
#include <omp.h>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

ofstream stream("philosophers.txt");

const int philCount = 5;
bool forks[philCount];

string getTime() 
{
    SYSTEMTIME timeStamp;
    GetLocalTime(&timeStamp);
    return to_string(timeStamp.wHour) + ":" + to_string(timeStamp.wMinute) + ":" + to_string(timeStamp.wSecond) + ":" + to_string(timeStamp.wMilliseconds);
}


void changeForksAvailability(int forkLeft, bool newValue) 
{
#pragma omp critical(forks)
    {
        forks[forkLeft] = newValue;
        forks[forkLeft + 1] = newValue;
    }
}

bool checkForks(int forkLeft)
{
    bool isFree = false;
#pragma omp critical(check)
    {
#pragma omp flush(forks)
        isFree = forks[forkLeft] && forks[forkLeft + 1];
        if (isFree) changeForksAvailability(forkLeft, false);
    }
    return isFree;
}

void writeAndDump(string txt) 
{
#pragma omp critical(out)
    {
        cout << txt;
        stream << txt;
    }
}

class Philosopher {
    int pNum;
    bool thinking;
public:
    Philosopher() {
       pNum = 0;
    }
    Philosopher(int num) {
        pNum = num;
        for (int i = 0; i < philCount; i++)
        {
            forks[i] = true; //вилка свободна
        }
    }
    void eat() {
            int forkLeft = pNum - 1;
            int forkRight = forkLeft < philCount ? forkLeft + 1 : 0;
            bool check = checkForks(forkLeft);
            if (check) {
                    thinking = false;
                    string time = getTime();
                    string strOut = "Философ " + to_string(pNum) + " трапезничает c " + time + " вилками " + to_string(forkLeft) + " и " + to_string(forkRight) +"\n";
                    writeAndDump(strOut);
                    int timeWait = rand() * pNum % 9000 + 1000;
                    Sleep(timeWait);
                    time = getTime();
                    strOut = "Философ " + to_string(pNum) + " закончил трапезу в " + time + " спустя " + to_string(timeWait / 1000) + "с" + "\n";
                    writeAndDump(strOut);
                    changeForksAvailability(forkLeft, true);
                }
            else { 
                if (!thinking) {
                    string strOut = "Философ " + to_string(pNum) + " в раздумьях" + "\n";
                    writeAndDump(strOut);
                    thinking = true;
                }
            }

        }
};
int main(void) {
    setlocale(LC_ALL, "Russian");
    Philosopher ph[philCount+1];
    for (int i = 1; i <= philCount; i++) {
        ph[i] = Philosopher(i);
    }
    time_t timeStamp;
    time_t timeStampTmp;
    time(&timeStamp);
    time(&timeStampTmp);
    while ((timeStampTmp - timeStamp) < 10)
    {
        time(&timeStampTmp);
#pragma omp parallel num_threads(philCount)
        {
            int num = omp_get_thread_num();
            //while (true)
                ph[num + 1].eat();
        }
        cout << "Конец очередной итерации\n";
        stream << "-----------------------\nКонец очередной итерации\n-----------------------\n";
    }
    stream.close();
    return 0;
}