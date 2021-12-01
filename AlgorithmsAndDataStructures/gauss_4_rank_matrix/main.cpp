#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;


class Matrix{
private:
    int rows =0, columns = 0;
    double **Mat;

public:
    Matrix(int r, int c){
        rows=r;
        columns=c;
        Mat = new double*[rows];
        for(int i=0; i<rows; i++)
            Mat[i]=new double[columns];
        getMatrix();
    }
    void show(){
        for (int i=0; i<rows; i++){
            cout << "{   ";
            for (int j=0; j< columns; j++)
                cout << setw(3) << left <<Mat[i][j] <<" ";
            cout << "}"  << endl;
        }
    }
    void getMatrix(){
        for(int i=0; i< rows; i++)
            for(int j=0; j<columns; j++){
                cout << "Element ["<<i<<"]["<<j<<"] :";
                cin >> Mat[i][j];
            }
    }

    int rankOfMatrix()
        {
            const double eps = 0.00000001;
            int i,j,k,l;
            double r;
            i=0; j=0;
            while(i<rows && j <columns){
                r = 0.0;
                for(k=i; k<rows; ++k){
                    if(fabs(Mat[k][j])>r){
                        l=k;
                        r=fabs(Mat[k][j]);
                    }
                }
                if(r<=eps){
                    for(k=i; k<rows; ++k){
                        Mat[k][j] = 0.0;
                    }
                    ++j;
                    continue;
                }
                if(l != i){
                    for(k=j; k<columns; ++k){
                        r = Mat[i][k];
                        Mat[i][k]=Mat[l][k];
                        Mat[l][k]=(-r);
                    }
                }
                r = Mat[i][j];
                assert(fabs(r)>eps);

                for(k = i +1; k<rows; ++k){
                    double c = (-Mat[k][j])/r;

                    Mat[k][j] = 0.0;
                    for(l =j+1; l<columns; ++l){
                        Mat[k][l] += c * Mat[i][l];
                    }
                }
                ++i; ++j;
            }
            return i;
        }


    ~Matrix(){
        for(int i=0; i<rows; i++)
        delete []Mat[columns];
    }
};


int main(){
    int r,c;
    cout << "Rows = ";
    cin >> r;
    cout << "Columns = ";
    cin >> c;
    Matrix A(r,c);
    A.show();
    cout <<"Rank of matrix = "<< A.rankOfMatrix() << endl;
    A.show();
return 0;
}
