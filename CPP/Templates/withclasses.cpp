#include <iostream>
#include <myclasses.h>
using namespace std;

template <class T>
class array2d{
protected:
    int rows=0;
    T **rarr;
    int *columns;
public:
    array2d(int r){
    rows=r;
    columns = new int[rows];
    rarr= new T*[rows];
    init();
    }
    ~array2d(){
        for(int i =0; i<rows; i++){
            delete [] rarr[i];
        }
        delete[] columns;
        delete[] rarr;
    }
    virtual void init();
    virtual void show();
    virtual void addrow();
};
int main()
{
    array2d <Complex> c(2);
    c.show();
    c.addrow();
    c.show();
    return 0;
}

template <class T>
void array2d<T>::init(){
        for (int i=0; i<rows; i++){
            cout << "Enter the number of elements in the row number " << i+1 << ": ";
            cin>>*(columns+i);
            rarr[i]=new T[*(columns+i)];
            cout << "Enter the elements of the row number " << i+1 << endl;
            for(int j=0; j<*(columns+i); j++){
            cin >> *(rarr[i]+j);
            }
        }
    }
template <class T>
void array2d<T>::show(){
    for (int i=0; i<rows; i++){
        for(int j=0; j<*(columns+i);j++){
                cout<<*(rarr[i]+j) << " ";
        }
        cout << endl;
    }
}
template <class T>
void array2d<T>::addrow(){
    int *tmp;
    tmp=new int[rows+1];
    for(int i=0; i<rows; i++){
        *(tmp+i) = *(columns+i);
    }
    cout << "Enter the number of elements in the row number " << rows+1 << ": ";
    cin >>*(tmp+rows);
    delete[] columns;
    columns=tmp;
    T **temp;
    temp = new T*[rows+1];
    for(int i=0; i<rows; i++){
        temp[i]=rarr[i];
    }
    temp[rows]=new T[*(columns+rows)];
    cout << "Enter the elements of the new row: " << endl;
    for(int i=0; i<*(columns+rows); i++){
        cin>>*(temp[rows]+i);
    }
    delete[] rarr;
    rarr=temp;
    rows++;
}
