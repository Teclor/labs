#include "lab6.h"
int main()
	{
		try {
			hMutex = CreateMutex(NULL, FALSE, NULL);
			if (hMutex == NULL) throw 1;
			HANDLE ThreadOne = CreateThread(NULL, 0, thread1, NULL, 0, NULL);
			if (!ThreadOne) throw 1;
			HANDLE ThreadTwo = CreateThread(NULL, 0, thread2, NULL, 0, NULL);
			if (!ThreadTwo) throw 1;
			HANDLE threads[2] = { ThreadOne, ThreadTwo };
			if (!threads) throw 1;
			if (WaitForMultipleObjects(2, threads, TRUE, 100000) != WAIT_OBJECT_0) throw 1;
		}
		catch (...) {
				cout << "An error number " << GetLastError() << " occured. The program will be finished.";
				return 0;
		}
		return 0;
	}


