#include "lab6.h"


int main()
{
	try {
		HINSTANCE hDLL = NULL;
		hDLL = LoadLibraryA("lab6lib.dll");
		LPTHREAD_START_ROUTINE Thread1 = (LPTHREAD_START_ROUTINE)GetProcAddress(hDLL, "?thread1@@YGKPAX@Z");
		LPTHREAD_START_ROUTINE Thread2  = (LPTHREAD_START_ROUTINE)GetProcAddress(hDLL, "?thread2@@YGKPAX@Z");

		hMutex = CreateMutex(NULL, FALSE, NULL);
		if (hMutex == NULL) throw 1;
		HANDLE ThreadOne = CreateThread(NULL, 0, Thread1, NULL, 0, NULL);
		if (!ThreadOne) throw 1;
		HANDLE ThreadTwo = CreateThread(NULL, 0, Thread2, NULL, 0, NULL);
		if (!ThreadTwo) throw 1;
		HANDLE threads[2] = { ThreadOne, ThreadTwo };
		if (!threads) throw 1;
		if (WaitForMultipleObjects(2, threads, TRUE, 100000) != WAIT_OBJECT_0) throw 1;
		FreeLibrary(hDLL);
	}
	catch (...) {
		cout << "An error number " << GetLastError() << " occured. The program will be finished.";
		return 0;
	}
	return 0;
}

