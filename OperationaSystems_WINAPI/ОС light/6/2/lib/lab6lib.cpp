#include "pch.h"
#include "lab6.h"

DWORD WINAPI thread1(LPVOID t)
{
	for (int i = 0; i < 10; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "F";
		Sleep(100);
		cout << "I";
		Sleep(100);
		cout << "R";
		Sleep(100);
		cout << "S";
		Sleep(100);
		cout << "T" << endl;
		Sleep(100);
		ReleaseMutex(hMutex);
	}
	return 0;
}

DWORD WINAPI thread2(LPVOID t)
{
	for (int i = 0; i < 10; i++) {
		WaitForSingleObject(hMutex, INFINITE);
		cout << "S";
		Sleep(100);
		cout << "E";
		Sleep(100);
		cout << "C";
		Sleep(100);
		cout << "O";
		Sleep(100);
		cout << "N";
		Sleep(100);
		cout << "D" << endl;
		Sleep(100);
		ReleaseMutex(hMutex);
	}
	return 0;
}