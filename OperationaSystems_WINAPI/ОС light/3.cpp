#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

void fsort(int *arr[],int asize, HANDLE h){
bool check = true;
while(check){
    check=false;
    for(int i=0; i<asize-1; i++)
        if(HeapSize(h, 0,arr[i]) > HeapSize(h, 0, arr[i+1])){
            int *tmp;
            tmp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=tmp;
            check=true;
        }
    }
}
void checkerr(void *ptr)
{
    if (ptr==NULL) throw 1;
}
int main()
{   try{
    cout << sizeof(int) << endl << sizeof(int*) << endl;
    HANDLE hp=NULL;
    hp = HeapCreate(0,0x1000,0);
    checkerr(hp);
    //if(hp==NULL){cout << "ERROR CREATING HEAP " << GetLastError(); return 1; }
    srand(time(0));
    int arrsize;
    cout << "Enter the size of your two-dimensional array (5 or more): ";
    cin >> arrsize;
    int **arrptr = (int**)HeapAlloc(hp, 0, arrsize*sizeof(int*));
    for(int i=0; i<arrsize; i++){
        arrptr[i]=(int*)HeapAlloc(hp,0,10*sizeof(int));
        checkerr(arrptr[i]);
        int len = rand()% 10 +1;
        arrptr[i]=(int*)HeapReAlloc(hp,0,arrptr[i], len*sizeof(int));
        checkerr(arrptr[i]);
        for(int j=0; j<len; j++){
            cout.fill(' ');
            cout.width(3);
            *(arrptr[i]+j)=rand() %10 +1;
            cout << *(arrptr[i]+j);
        }
    cout <<endl;
    }
    for(int i=0; i<arrsize; i++)
    {
        SIZE_T n;
        n = HeapSize(hp,0,arrptr[i]);
        checkerr(&n);
        //if(n==0){cout << "ERROR EXECUTING HEAPSIZE " << GetLastError(); return 1;}
        cout << "Size of a line number (in HeapSize/sizeof(int)) " << i+1 << " = " << n/sizeof(int)<<endl;
    }
    fsort(arrptr, arrsize, hp);
    for(int i=0; i <arrsize; i++){
        for(int j=0; j<(int)HeapSize(hp,0,arrptr[i])/sizeof(int); j++){
            cout.fill(' ');
            cout.width(3);
            cout << *(arrptr[i]+j);
        }
    cout << endl;
    }
    if (HeapDestroy(hp)==0)
    cout << "ERROR DELETING HEAP" << endl;
    }
    catch(int){cout << "Error number " << GetLastError(); return 1;}
}
