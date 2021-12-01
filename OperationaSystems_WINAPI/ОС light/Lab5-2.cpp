#include <iostream>
#include <Windows.h>

using namespace std;

DWORD WINAPI thread1(LPVOID);
DWORD WINAPI thread2(LPVOID);


int main()
{
	try {
		HANDLE ThreadOne = CreateThread(NULL, 0, thread1, NULL, 0, NULL);
		if (!ThreadOne) throw 1;
		HANDLE ThreadTwo = CreateThread(NULL, 0, thread2, NULL, 0, NULL);
		if (!ThreadTwo) throw 1;
		HANDLE threads[2] = { ThreadOne, ThreadTwo };
		if (!threads) throw 1;
		if (WaitForMultipleObjects(2, threads, TRUE, 10000) != WAIT_OBJECT_0) throw 1;
	}
	catch (...) {
		cout << "An error number " << GetLastError() << " occured. The program will be finished.";
		return 0;
	}
	return 0;
}

DWORD WINAPI thread1(LPVOID t)
{
	for (int i = 0; i < 10; i++){
		cout << "F";
		Sleep(100);
		cout << "I";
		Sleep(100);
		cout << "R";
		Sleep(100);
		cout << "S";
		Sleep(100);
		cout << "T" <<endl;
		Sleep(100);
	}
	return 0;
}

DWORD WINAPI thread2(LPVOID t)
{
	for (int i = 0; i < 10; i++) {
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
	}
	return 0;
}