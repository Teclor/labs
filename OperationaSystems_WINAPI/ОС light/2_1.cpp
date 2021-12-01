
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    MEMORYSTATUS ms;
    setlocale(LC_ALL, "rus");
    while(GetAsyncKeyState(0x51) != -32767){
    GlobalMemoryStatus(&ms);
    cout << "Всего памяти: " << ms.dwTotalPhys/(1024*1024) << endl;
    cout << "Загружено: " << ms.dwMemoryLoad << endl;
    cout << "Доступно: " << ms.dwAvailPhys/(1024*1024)<< endl;
    cout <<"\n\n";
    for(int i=0; i<100; i++){
            if(GetAsyncKeyState(0x51) != -32767){Sleep(10);}else{return 0;}
    }
    }

    return 0;
}
