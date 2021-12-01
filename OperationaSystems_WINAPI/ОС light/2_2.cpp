#include <iostream>
#include <windows.h>
using namespace std;
void checkstate(DWORD state){
if(state == 0x1000) cout << "State: Memory commited." << endl;
if(state == 0x2000) cout << "State: Memory reserved."<< endl;
if(state == 0x4000) cout << "State: Memory DEcommited."<< endl;
if(state == 0x8000) cout << "State: Memory released."<< endl;
}
void checkprotect(DWORD protect){
if(protect == 0x0001) cout << "Protect: page noaccess."<< endl;
if(protect == 0x0002) cout << "Protect: page readonly."<< endl;
if(protect == 0x0004) cout << "Protect: page readwrite."<< endl;
if(protect == 0x0000) cout << "Protect: page protect is NULL"<< endl;
}
int main()
{
    bool errtest;
    SYSTEM_INFO sinf;
    GetSystemInfo(&sinf);
    DWORD pagesize=sinf.dwPageSize;
    cout << "PAGE SIZE = " << pagesize << endl;
// -----------RESERVING---------------------------------------------------
    cout << "ENTER THE NUMBER OF PAGES TO RESERVE: ";
    int pages;
    cin >> pages;
    void *p=NULL;
    p=VirtualAlloc(NULL, pages*pagesize, MEM_RESERVE, PAGE_READWRITE);
        if(p!=NULL){
              cout << "Address = " << p << endl; }
        else{ cout << "Error of reserving " << GetLastError(); return 1;}
 //-----------------------------------------COMMITING------------------------
    cout << "ENTER THE NUMBER OF PAGES TO COMMIT: ";
    int pagescommit;
    cin >> pagescommit;
    cout << "ENTER THE NUMBER OF PAGE TO START COMMITING: ";
    int comstart;
    cin >> comstart;
        void *pc=NULL;
    pc=VirtualAlloc(p+comstart*pagesize, pagescommit*pagesize, MEM_COMMIT, PAGE_READWRITE);
        if(pc!=NULL){
              cout << "Address of commited = " << pc << endl; }
        else{ cout << "Error of commiting " << GetLastError(); return 1;}


 //----------------COPYING----------------------------------------------------------
        int n=5;
        int arr[n]={5,4,3,2,1};
        int *pc1 = (int*)pc;
        errtest = memcpy(pc1,arr,n*sizeof(int));
        if(!errtest)
        {
            cout << "Error executing memcpy_s " << GetLastError() <<endl; return 1;
        }
        else
        {
            cout << "Copied successfuly - "<< *(pc1+0) << *(pc1+1) << *(pc1+2) << *(pc1+3) << *(pc1+4) <<endl;
        }
//----------------------VirtualQuery------------------------------------------------
        MEMORY_BASIC_INFORMATION info;
        cout <<"Info about commited memory: " <<endl;
        size_t err = VirtualQuery(pc,&info,sizeof(info));
        if(err==0){cout <<"Error executing virtualquery " << GetLastError(); return 1;}
        checkstate(info.State);
        checkprotect(info.Protect);

        cout <<"Info about memory after commited: " <<endl;
        err = VirtualQuery(pc+pagescommit*pagesize,&info,sizeof(info));
        if(err==0){cout <<"Error executing virtualquery " << GetLastError(); return 1;}
        checkstate(info.State);
        checkprotect(info.Protect);


//----------------------COMMITING---N2----------------------------------------------
        void *pc2=NULL;
        pc2=VirtualAlloc(p+(comstart+pagescommit)*pagesize,pagesize, MEM_COMMIT, PAGE_READONLY);
        if(pc2!=NULL){
              cout << "Address of commited 2 = " << pc2 << endl; }
        else{ cout << "Error of commiting 2 " << GetLastError(); return 1;}
//----------------------VirtualQuery---N2-------------------------------------------
        err = VirtualQuery(p+(comstart+pagescommit)*pagesize,&info,sizeof(info));
        if(err==0){cout <<"Error executing virtualquery 2 " << GetLastError(); return 1;}
        checkstate(info.State);
        checkprotect(info.Protect);
//----------------------DECOMMITING-------------------------------------------------
        SIZE_T dwSize;
        cout << "How many pages to return? ";
        cin >> dwSize;
        cout << "ENTER THE NUMBER OF PAGE TO START DECOMMITING: ";
        cin >> comstart;
        if (!VirtualFree(p+comstart*pagesize,dwSize,MEM_DECOMMIT))
        cout << "ERROR IN MEMORY RETURNING " << GetLastError();
        else{cout <<"ADDRESS "<< p+comstart*pagesize << endl;}

        err = VirtualQuery(p+comstart*pagesize,&info,sizeof(info));
        if(err==0){cout <<"Error executing virtualquery final " << GetLastError(); return 1;}
        checkstate(info.State);
        checkprotect(info.Protect);
 //------------------RELEASING------------------------------------------------------
        if (!VirtualFree(p,0,MEM_RELEASE))
        cout << "ERROR IN MEMORY RELEASING " << GetLastError();


    return 0;
}
