#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

template <typename T>
class Polynomial {
protected:
	unsigned int degree;
	vector <T> pol;
public:
	Polynomial(const int pdegree) {
		degree = pdegree;
		pol.resize(degree+1);
	}
	T showmember(int a) { return pol.at(a); }
	T showdegree() { return degree; }
	void putadd(unsigned int b, T value) { pol.at(b)+= value; }
	void pfill();
	void elemfill(T value, int i);
	void show();
	void showpolynomial();
	Polynomial<T> operator *(Polynomial<T> & factor);
	~Polynomial(){}
};

int main()
{
	ifstream fin1("1.txt");
	ifstream fin2("2.txt");
	char* context = NULL;
	char tempbuf[127];
	int deg1;
	fin1.getline(tempbuf, 127);
	char *a = strtok_s(tempbuf, " ", &context);
	deg1 = atoi(a);
	Polynomial <int> P1(deg1);
	cout << "Degree of the first = "<<deg1 << endl;
	int i = 0;
	while (i <= deg1) {
		P1.elemfill(atoi(strtok_s(NULL, " ", &context)), i);
		i++;
	}
	P1.show();
	fin1.close();
// THE SECOND ONE
	fin2.getline(tempbuf, 127);
	a = strtok_s(tempbuf, " ", &context);
	int deg2 = atoi(a);
	Polynomial <int> P2(deg2);
	cout << "Degree of the second = " << deg2 << endl;
	i = 0;
	while (i <= deg2) {
		P2.elemfill(atoi(strtok_s(NULL, " ", &context)), i);
		i++;
	}
	P2.show();
	fin2.close();
	Polynomial <int> Presult(deg1+deg2);
	Presult = P1 * P2;
	Presult.show();
	/*Polynomial <int> pol1(5);
	pol1.pfill();
	pol1.show();
	Polynomial <int> pol2(3);
	pol2.pfill();
	pol2.show();
	Polynomial <int> polresult(8);
	polresult = pol1 * pol2;
	polresult.show();*/
}

template <typename T>
void Polynomial<T>::pfill(){
	for (int i = degree; i >= 0; i--) {
		cout << "Enter the coefficient of the polynomial's member of " << i << " degree: " << endl;
		cin >> pol.at(i);
	}
}
template <typename T>
void Polynomial<T>::elemfill(T value, int i) {
	pol.at(i) = value;
}
template <typename T>
void Polynomial<T>::showpolynomial() {
	for (int i = degree; i >= 0; i--) {
		if (i != 0)
			cout << pol.at(i) << "x^" << i << '+';
		else cout << pol.at(i) << endl;
	}
}
template <typename T>
void Polynomial<T>::show() {
	for (int i = degree; i >= 0; i--) {
		cout << "The coefficient of the member of degree " << i << " is " << pol.at(i) << endl;
	}
}
template <typename T>
Polynomial<T> Polynomial<T>::operator * (Polynomial<T>& factor) {
	unsigned int n = degree + factor.showdegree();
	Polynomial<T> result(n);
	unsigned int degleft = degree;
	unsigned int degright = factor.showdegree();
	cout << degleft << " " << degright << endl;
	for (int i = degleft; i >= 0; i--){
		for (int j = degright; j >= 0; j--) {
			T temp = pol.at(i) * factor.showmember(j);
			result.putadd(i + j, temp);
		}
	}
	return result;
}
