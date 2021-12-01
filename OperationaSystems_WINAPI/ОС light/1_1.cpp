#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    char n=65;
    bool trigger=false;
    char disk;
    cin >> disk;
    DWORD check = GetLogicalDrives();
            char mas[4];
            mas[0]=disk;
            mas[1]=':';
            mas[2]='\\';
            mas[3]='\0';
    for(int i =0; i<26; i++){
        if(((check>>i)&1) && n==disk){
            UINT type = GetDriveTypeA(LPCSTR(mas)); trigger=true;
        if( type == DRIVE_UNKNOWN ) cout << " UNKNOWN" << endl;
        if( type == DRIVE_NO_ROOT_DIR ) cout << " DRIVE NO ROOT DIR" << endl;
        if( type == DRIVE_REMOVABLE ) cout << " REMOVABLE" << endl;
        if( type == DRIVE_FIXED ) cout << " FIXED" << endl;
        if( type == DRIVE_REMOTE ) cout << " REMOTE" << endl;
        if( type == DRIVE_CDROM ) cout << " CDROM" << endl;
        if( type == DRIVE_RAMDISK ) cout << " RAMDISK" << endl;
        }
        n++;
    }
        if(trigger==false){cout << "No disk named " << disk;}
        else {

            char NameBuf[20];
            char FileSystem[10];
            unsigned long SerialNum;

            BOOL GFlag = GetVolumeInformationA(
                mas,
                NameBuf,
                100,
                &SerialNum,
                NULL, //&MaximumComponentLength,
                NULL, //&FileSystemFlags,
                FileSystem,
                100
                );

            if(GFlag != 0){
                cout << " Volume Name is " << NameBuf << endl;
                cout << " Volume Serial Number is " << SerialNum << endl;
                cout << " File System is " << FileSystem << endl;
                }
                else cout << " No info " << endl;

                ULARGE_INTEGER CallerFreeBytes;
                ULARGE_INTEGER TotalBytes;
                ULARGE_INTEGER TotalFreeBytes;
				WCHAR mas2[4] = L"C:\\";
				mas2[0]=mas[0];
                BOOL SpaceFlag = GetDiskFreeSpaceEx(
                mas2,
                (PULARGE_INTEGER)&CallerFreeBytes,
                (PULARGE_INTEGER)&TotalBytes,
                (PULARGE_INTEGER)&TotalFreeBytes
                );

                if(SpaceFlag != 0){
                cout << " Total Number Of Free Bytes = " << TotalFreeBytes.QuadPart << "( " << TotalFreeBytes.QuadPart/1024.0/1024 << " Mb )" << endl;
                cout << " Total Number Of Bytes = " << TotalBytes.QuadPart << "( " << TotalBytes.QuadPart/1024.0/1024 << " Mb )" << endl;
                }
                else cout << " No info " << endl;

        }

    return 0;
}

