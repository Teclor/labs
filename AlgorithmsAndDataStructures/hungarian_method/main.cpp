#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <vector>

#define MUTE 1
#define MAT_SIZE 4
#define INF 100000
#define
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
            init();
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
    void initFromFile(ifstream& F){
        for(int i=0; i< rows; i++)
        for(int j=0; j<columns; j++){
            if(!MUTE)cout << "Element ["<<i<<"]["<<j<<"] :";
            char tmp[255];
            F >> tmp;
            Mat[i][j] = atoi(tmp);
        }
    }
    void init(){
        int k;
        if(!MUTE)cout << "Choose matrix input method: \n" <<
        "From file - 1 \n"
        "From console - 2 \n"
        "Exit - 0 \n";
        if(MUTE)k = 1;
        else cin >> k;
        switch(k){
        case 1:
            {
            ifstream inF;
            char fname[255] = "input.txt";
            if(!MUTE) {cout << "Enter file name: "; cin >> fname; }
            inF.open(fname);
            initFromFile(inF);
            inF.close();
            break;
            }
        case 2: getMatrix(); break;
        case 0: return; break;
        default: cout << "Error"; break;
        }
    }
    void Hungarian(bool goal_is_max){
    if(goal_is_max){
        int maxElement=0;
        for(int i = 0; i < MAT_SIZE; i++)
            for(int j=0; j <MAT_SIZE; j++)
                if(Mat[i][j]>maxElement) maxElement = Mat[i][j];
        for(int i = 0; i < MAT_SIZE; i++)
            for(int j=0; j <MAT_SIZE; j++)
                Mat[i][j]=(Mat[i][j]*(-1))+maxElement;
    }
   // Значения, вычитаемые из строк (u) и столбцов (v)
   vector<int> u(MAT_SIZE, 0), v(MAT_SIZE, 0);
   vector<int> markIndices(MAT_SIZE, -1);
   // Будем добавлять строки матрицы одну за другой
   for(int i = 0; i < MAT_SIZE; i++) {
      vector<int> links(MAT_SIZE, -1), mins(MAT_SIZE, INF), visited(MAT_SIZE, 0);
      // Разрешение коллизий (создание "чередующейся цепочки" из нулевых элементов)
      int markedI = i, markedJ = -1, j;
      while(markedI != -1) {
         // Обновим информацию о минимумах в посещенных строках непосещенных столбцов
         // Заодно поместим в j индекс непосещенного столбца с самым маленьким из них
         j = -1;
         for(int j1 = 0; j1 < MAT_SIZE; j1++)
            if(!visited[j1]) {
               if(Mat[markedI][j1] - u[markedI] - v[j1] < mins[j1]) {
                  mins[j1] = Mat[markedI][j1] - u[markedI] - v[j1];
                  links[j1] = markedJ;
               }
               if(j==-1 || mins[j1] < mins[j])
                  j = j1;
            }

         // Теперь нас интересует элемент с индексами (markIndices[links[j]], j)
         // Произведем манипуляции со строками и столбцами так, чтобы он обнулился
         int delta = mins[j];
         for(int j1 = 0; j1 < MAT_SIZE; j1++)
            if(visited[j1]) {
               u[markIndices[j1]] += delta;
               v[j1] -= delta;
            } else {
               mins[j1] -= delta;
            }
         u[i] += delta;

         // Если коллизия не разрешена - перейдем к следующей итерации
         visited[j] = 1;
         markedJ = j;
         markedI = markIndices[j];
      }

      // Пройдем по найденной чередующейся цепочке клеток, снимем отметки с
      // отмеченных клеток и поставим отметки на неотмеченные
      for(; links[j] != -1; j = links[j])
         markIndices[j] = markIndices[links[j]];
      markIndices[j] = i;
   }

   // Вернем результат в естественной форме
   vector<pair<int, int> > result;
   for(int j = 0; j < MAT_SIZE; j++)
      if(markIndices[j] != -1)
         result.push_back(pair<int, int>(markIndices[j], j));
    for(int i = 0; i < result.size(); i++)
        cout << "Row "<<result[i].first+1 << " Col " << result[i].second+1 <<"\n";
    }

    ~Matrix(){
        for(int i=0; i<rows; i++)
        delete []Mat[i];
    }
};

int main(){
    int r=MAT_SIZE,c=MAT_SIZE;
    if(!MUTE){cout << "Rows = ";
    cin >> r;
    cout << "Columns = ";
    cin >> c;
    }
    Matrix A(r,c);
    A.show();
    A.Hungarian(true);
return 0;
}
