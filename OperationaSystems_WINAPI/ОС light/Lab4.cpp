#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int main()
{
	STARTUPINFOA si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	char cmdname[] = "calc.exe";
	LPSTR szCmdline = cmdname;
	if (!CreateProcessA(NULL, // Нет имени модуля (используется командная строка).

		szCmdline,     // Командная строка.

		NULL,                 // Дескриптор процесса не наследуемый.

		NULL,                 // Дескриптор потока не наследуемый.

		FALSE,                // Установим наследование дескриптора в FALSE.

		0,                    // Флажков создания нет.

		NULL,                 // Используйте блок конфигурации родителя.

		NULL,                 // Используйте стартовый каталог родителя.

		&si,                  // Указатель на структуру STARTUPINFO.

		&pi)                 // Указатель на структуру PROCESS_INFORMATION.

		)
	{
		cout << "Error creating process!";
		return 0;
	}
	else
	{
		cout << "Process ID: " << pi.hProcess << endl;
	}

	bool exitcode = false;
	while (GetAsyncKeyState(0x30) != -32767) {
		cout << "Choose your action: \n" <<
			"s - Suspend the thread \n" <<
			"r - Resume the thread \n" <<
			"t - Terminate the thread \n" <<
			"0 - Exit this menu. \n";
		int key = _getch();
		//cout << "KEY " << key << endl;
		switch (key) {
		case 115: if (!SuspendThread(pi.hProcess)) cout << "Error suspending thread!" << GetLastError() << endl;
				break;
		case 114: if (!ResumeThread(pi.hProcess)) cout << "Error resuming thread!" << GetLastError() << endl;
				break;
		case 116: 	if (!TerminateProcess(pi.hProcess, 0))	cout << "Process terminating failed! " << GetLastError() << endl;
					else exitcode = true;
				break;
		case 48: exitcode = true; break;
			default: cout << "Invalid character. Try again." << endl; break;
		}
		if (exitcode) break;
	}
		
		
	// Закроем дескрипторы процесса и потока.

	if (TerminateProcess(pi.hProcess, 0))
		cout << "Process successfully finished! \n";
	else {
		cout << "Error terminating process! " << GetLastError() << endl; return 0;
	}
	CloseHandle(pi.hProcess);

	CloseHandle(pi.hThread);
	
	
	//2 часть
	char cmdname1[] = "notepad.exe";
	szCmdline = cmdname1;
	if (!CreateProcessA(NULL, // Нет имени модуля (используется командная строка).

		szCmdline,     // Командная строка.

		NULL,                 // Дескриптор процесса не наследуемый.

		NULL,                 // Дескриптор потока не наследуемый.

		CREATE_SUSPENDED,                // Установим наследование дескриптора в FALSE.

		0,                    // Флажков создания нет.

		NULL,                 // Используйте блок конфигурации родителя.

		NULL,                 // Используйте стартовый каталог родителя.

		&si,                  // Указатель на структуру STARTUPINFO.

		&pi)                 // Указатель на структуру PROCESS_INFORMATION.

		)
	{
		cout << "Error creating process!";
		return 0;
	}
	else
	{
		cout << "Process ID: " << pi.hProcess << endl;
	}
	Sleep(10000);
	ResumeThread(pi.hProcess);
	cout << "Priority: " << GetThreadPriority(pi.hProcess) <<endl;

	if (TerminateProcess(pi.hProcess, 0))
		cout << "Process successfully finished! \n";
	else cout << "Error terminating process! " << GetLastError() << endl;

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	return 0;
}

