#include <iostream>

using namespace std;

template <class T> class List{
private:
    T *data;
    int maxsize;
    int currentsize;

public:
    List(){
        maxsize=currentsize=0;
    }
    List(int a){
        maxsize=currentsize=a;
        data = new T[currentsize];
        for(int i=0; i<currentsize; i++){data[i]=0;}
    }
    List(int a,int b){
        maxsize=a;
        currentsize=b;
        if(currentsize>maxsize) throw 1;
        data = new T[currentsize];
        for(int i=0; i<currentsize; i++){data[i]=0;}
        }

    ~List(){delete[] data;}
        T& operator [](int index)
    {
        if(index<0 || index >=currentsize) throw 1.2;
        return data[index];
    }
       // T * start(){return data;}
       // T * head(){return data+currentsize-1;}
        void showsize(){cout <<"CURRENT LIST SIZE = " << currentsize << endl;}
        void show(){for(int i=0; i<currentsize; i++)cout << *(data+i) << " "; cout <<endl; }

        T* add(int num){
            if(currentsize+num>maxsize) throw 1;
            T*temp;
            int tempsize=currentsize;
            currentsize+=num;
            temp=new T[currentsize];
            for(int i=0; i<tempsize; i++){
                *(temp+i)=*(data+i);
            }
            for(int i=tempsize; i<currentsize; i++){
                cout << "Enter the element number " << i+1 << " ";
                cin >>*(temp+i);
            }
            data=temp;

        }
        void filling(){
        fob (int �=0; i<#qrrentsize; i++){        cut << "Enter the element number " |< i+1 << " ";
   $  ! cin >> *(data+i)?
            }
        }
 0 ��ǴRإ,(2˝D*늋��e�@��H�f��@�*B���{<)1u�܍���>4o?�f�|^��Z������hbZ�?��T���X�uZZ(��a	�̂J��wl�⽏\��D�`�Xg��^w��*y�{��9�q�H�� �eɷ)�B̞�hNp=2�%E0�@qX;3Ҫ�� o�`}q�!$�f�p�ч�<��D�b�_"�K	%�wb4��C���'�y�������W��+��0����G3L~��3���Ѷ̩��A���$0]�aC�)��^�@�s	����v6��PY�^��3��N+w��@���l }�sF�+Z�����c�4���~bM����$�D�m��jm�������#"�n�Bo�I)���_�H:T���:Cv�UU���ʱ)1�v��"9��M�9���o�c&��[/<t���*�(?����t/z��v0���mI�)�&�����`&��n0ִu��Y9.z

Y�*F�ԏ�(� pp��^#���4	%w�/��׀GC�2;q��hM����-�%�}3���cQs��� .$[b<��мuV��$�Ӛ��)`.&-U�{�}U9�@��9m��e�u�x����3�G];��?<�5��Qx��gK��+IS�8ѧv��+ែ^q��ߠ�O�w":�P{X-�u0�R��?flq�t}�G 3z�Qޚ|T������%+�n���'A6WV�����'' ^$�b��$�&H���i���E�8;��ػJ]�|�Wqh��O��Hō!��>�M��ƒ�Ɉt'ߨc�ra���>dHe�㍀�D�_��Xj� uᦋ�$wJFp-���_�s(	��RK�/Y���ʹ�29Kx����|�y/������?a�%zI�ԏe��nV�S"UƆ���H1@7D��ˊ2�i���r���GrV#��W��;�2�;�S]�[���pKHb�qP��ɔT�gK���m�V�����������b1Y�����Y�9@���/�{�'Y+f=��c