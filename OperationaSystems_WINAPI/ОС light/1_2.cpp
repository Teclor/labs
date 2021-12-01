#include <iostream>
#include <windows.h>
#include <tchar.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){

TCHAR fin[16], fout[16];
DWORD pos, fsize;
TCHAR buf[512];
DWORD bytesread, byteswritten;

cin >> fin;
cin >> fout;
cin >> pos;
HANDLE f1, f2;
bool errtest;
f1 = CreateFile(
                LPCSTR(fin),
                GENERIC_READ,
                FILE_SHARE_DELETE,
                NULL,
                OPEN_EXISTING,
                FILE_ATTRIBUTE_NORMAL,
                NULL);
    if (f1 == INVALID_HANDLE_VALUE) {
        cout << "ERROR: File creating failed." << GetLastError() <<endl;
        CloseHandle(f1);
        return 1;
    }
    else{
        fsize=GetFileSize(f1,NULL);
            if(fsize == INVALID_FILE_SIZE)
            {
                cout << "Invalid size" << endl;
                return 1;
            }
        errtest = SetFilePointer(
                       f1,
                       pos*sizeof(TCHAR),
                       NULL,
                       FILE_BEGIN
                       );
                       if (errtest==INVALID_SET_FILE_POINTER)
                       {cout << "Error of setting pointer in the file number " << GetLastError() << endl; return 1;}
        errtest = ReadFile(
                 f1,
                 buf,
                 512,
                 &bytesread,
                 NULL);
                 CloseHandle(f1);
                 if (errtest==0)
                       {cout << "Error of reading file number " << GetLastError() << endl; return 1;}
                 if(bytesread==0){cout << "Empty file!"; return 1;}
        cout <<"Text read from the file: \n" << buf << endl <<"Number of bytes successfully read = " << bytesread <<endl;
        buf[fsize]='\0';
        f2 = CreateFile(
                LPCSTR(fout),
                GENERIC_WRITE | GENERIC_READ,
                FILE_SHARE_WRITE,
                NULL,
                CREATE_ALWAYS,
                FILE_ATTRIBUTE_NORMAL,
                NULL);
        if (f2 == INVALID_HANDLE_VALUE) {
            cout << "ERROR: File creating failed." << GetLastError() <<endl;
            CloseHandle(f2);
            return 1;
            }
            else{
                       SetFilePointer(
                       f2,
                       FILE_BEGIN,
                       NULL,
                       FILE_BEGIN
                       );
                errtest=WriteFile(f2,&buf,bytesread,&byteswritten,NULL);
                CloseHandle(f2);
                if(errtest==0 || byteswritten!=bytesread){cout << "Error of writing in the file number " << GetLastError() << endl; return 1;}
                errtest = DeleteFile(fin);
                if(errtest==0){cout << "Error of deleting file number " << GetLastError() << endl; return 1;}
                }

            }

//wcin wcout
//_tscanf("%hs%hs",&fin,&fout);
//_tprintf(_T(fin));

return 0;
}
