#include <iostream>
#include <cmath>
#include <windows.h>
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

//COMPLEX HERE---COMPLEX HERE---COMPLEX HERE---COMPLEX HERE---COMPLEX HERE---COMPLEX HERE---COMPLEX HERE---COMPLEX HERE---COMPLEX HERE---COMPLEX HERE
class Complex {
    private:
    double Re, Im;
    public:
        Complex(){Re=0; Im=0;} // cout << " default \n";};
        Complex ( const double r )
        {
            Re=r;
            Im=0;
           // cout << " \n complex1 \n";    cout << "Subtraction " << f2 << " - " <<f1 " = " <<f4 <<endl;
        }

        Complex ( const double r, const double i )
        {
            Re=r;
            Im=i;
            //cout << " \n complex2 \n";
        }

        Complex (const Complex &c)
        {
            Re=c.Re;
            Im=c.Im;
            //cout << "\n copy constructor \n";
        }

        ~Complex(){}//cout << "\n DESTRUCTOR \n";}

        void setComplex(const double real, const double imaginary)
        {
            Re = real;
            Im = imaginary;
        }

        void getComplex()
        {
            cout << Re << " + " << Im <<"i"<<endl;
        }

          Complex operator + (const Complex &c)
        {
            return Complex (Re + c.Re, Im + c.Im);
        }

          Complex& operator += (Complex &c)
          {
            Re += c.Re;
            Im += c.Im;
            return *this;
          }

            Complex operator - (const Complex &c)
        {
            return Complex (Re - c.Re, Im - c.Im);
        }


            Complex operator *  (Complex &c)
        {
                return Complex(Re * c.Re - Im * c.Im, Re * c.Im + Im * c.Re);

        }
            Complex operator *  (double a)
        {
            return Complex(Re*a, Im*a);
        }


            Complex& operator *= (double a)
        {
            Re*=a;
            Im*=a;
            return *this;
        }

            Complex operator +  (double a)
        {
            return Complex(Re+a, Im);
        }

            Complex& operator *= (Complex &c)
          {
            Re=Re * c.Re - Im * c.Im;
            Im=Re * c.Im + Im * c.Re;
            return *this;
          }

            Complex operator / (const Complex &c)
          {
            Complex temp;

            double r = c.Re * c.Re + c.Im * c.Im;
            temp.Re = (Re * c.Re + Im * c.Im) / r;
            temp.Im = (Im * c.Re - Re * c.Im) / r;

            return temp;
          }

          Complex &operator = (const Complex &c)
          {
              Re=c.Re;
              Im=c.Im;
              return *this;
          }

          friend bool operator > (const Complex &a, const Complex &b);
          friend bool operator < (const Complex &a, const Complex &b);
          friend ostream& operator << (ostream &out, const Complex &number);
          friend istream& operator >> (istream &in, Complex &number);

          void comparison(Complex &num1, Complex &num2);

          friend Complex operator * (const double a, const Complex &c);
          friend Complex operator + (const double a, const Complex &c);
};

            bool operator > (const Complex &a, const Complex &b)
          {
              return (sqrt(a.Re*a.Re + a.Im*a.Im))>(sqrt(b.Re*b.Re + b.Im*b.Im));
          }

            bool operator < (const Complex &a, const Complex &b)
          {
              return (sqrt(a.Re*a.Re + a.Im*a.Im))<(sqrt(b.Re*b.Re + b.Im*b.Im));
          }

                    Complex operator * (const double a, const Complex &c)
                    {
                        return Complex(c.Re*a, c.Im*a);
                    }

                    Complex operator + (const double a, const Complex &c)
                    {
                        return Complex(c.Re+a, c.Im);
                    }

                        ostream& operator << (ostream &out, const Complex &number)
                  {
                      out << number.Re << " + " << number.Im << "i";
                      return out;
                  }

                        istream& operator >> (istream &in, Complex &number)
                  {
                        in >> number.Re;
                        in >> number.Im;
                        return in;
                  }

          void Complex :: comparison(Complex &num1, Complex &num2)
            {
                if(num1.Re>num2.Re) { cout << "Number 1 is to the right of Number 2" << endl;}
                if(num1.Re<num2.Re) { cout << "Number 1 is to the left of Number 2" << endl;}
                if(num1.Im>num2.Im) { cout << "Number 1 is higher in the complex system of axes than Number 2" << endl;}
                if(num1.Im<num2.Im) { cout << "Number 1 is lower in the complex system of axes than Number 2" << endl;}

            };
//COMPLEX END---COMPLEX END---COMPLEX END---COMPLEX END---COMPLEX END---COMPLEX END---COMPLEX END---COMPLEX END---COMPLEX END---COMPLEX END---COMPLEX END

//FRACTIONS---------FRACTIONS---------FRACTIONS---------FRACTIONS---------FRACTIONS---------FRACTIONS---------FRACTIONS---------FRACTIONS---------FRACTIONS
class Fractions {
    private:
    double numerator, denominator;
    public:
        Fractions(){ numerator=1; denominator=1;}
        Fractions ( const double n, const double d )
        {
            numerator=n;
            denominator=d;
            //cout << " \n fractions2 \n";
        }

     /*   Fractions (const Fractions &c)
        {
            numerator=c.Re;
            denominator=c.Im;
            //cout << "\n copy constructor \n";
        }
*/
        ~Fractions(){}//cout << "\n DESTRUCTOR \n";}

        void setFraction(const double numer, const double denom)
        {
            numerator = numer;
            denominator = denom;
        }

        void getFraction()
        {
            cout << numerator << "/" << denominator <<endl;
        }

          Fractions operator + (const Fractions &c)
        {
            if(denominator==c.denominator){
            return Fractions (numerator + c.numerator,denominator);
            }
            else
            {
                double newdem=denominator*c.denominator;
                double newnum=(numerator*c.denominator)+(denominator*c.numerator);
                return Fractions(newnum,newdem);
            }
        }

    /*      Fractions& operator += (Fractions &c)
          {
            Re += c.Re;
            Im += c.Im;
            return *this;
          }
*/
            Fractions operator - (const Fractions &c)
        {
            if(denominator==c.denominator){
            return Fractions (numerator - c.numerator, denominator);
            }
            else
            {
                double newdem=denominator*c.denominator;
                double newnum=(numerator*c.denominator)-(denominator*c.numerator);
                return Fractions(newnum,newdem);
            }
        }


         Fractions operator *  (Fractions &c)
        {
                return Fractions(numerator * c.numerator,denominator*c.denominator);

        }
            /*Complex operator *  (double a)
        {
            return Complex(Re*a, Im*a);
        }


            Complex& operator *= (double a)
        {
            Re*=a;
            Im*=a;
            return *this;
        }

            Complex operator +  (double a)
        {
            return Complex(Re+a, Im);
        }

            Complex& operator *= (Complex &c)
          {
            Re=Re * c.Re - Im * c.Im;
            Im=Re * c.Im + Im * c.Re;
            return *this;
          }

          */  Fractions operator / (const Fractions &c)
          {
            return Fractions(numerator*c.denominator,denominator*c.numerator);

          }

          Fractions &operator = (const Fractions &c)
          {
              numerator=c.numerator;
              denominator=c.denominator;
              return *this;
          }

          friend bool operator > (const Fractions &a, const Fractions &b);
          friend bool operator < (const Fractions &a, const Fractions &b);
          friend ostream& operator << (ostream &out, const Fractions &number);
          friend istream& operator >> (istream &in, Fractions &number);

       //   friend Complex operator * (const double a, const Complex &c);
      //    friend Complex operator + (const double a, const Complex &c);
};

            bool operator > (const Fractions &a, const Fractions &b)
          {
            if(a.denominator==b.denominator){
            return a.numerator>b.numerator;
            }
            else
            {
                double newnum1=a.numerator*b.denominator;
                double newnum2=b.numerator*a.denominator;
                return newnum1>newnum2;
            }

          }

            bool operator < (const Fractions &a, const Fractions &b)
          {
            if(a.denominator==b.denominator){
            return a.numerator<b.numerator;
            }
            else
            {
                double newnum1=a.numerator*b.denominator;
                double newnum2=b.numerator*a.denominator;
                return newnum1<newnum2;
            }

          }

                 /*  Complex operator * (const double a, const Complex &c)
                    {
                        return Complex(c.Re*a, c.Im*a);
                             bool operator > (const Fractions &a, const Fractions &b)
          {   }

                    Complex operator + (const double a, const Complex &c)
                    {
                        return Complex(c.Re+a, c.Im);
                    }
                    */

                        ostream& operator << (ostream &out, const Fractions &number)
                  {
                      out << number.numerator << "/" << number.denominator;
                      return out;
                  }

                        istream& operator >> (istream &in, Fractions &number)
                  {
                        in >> number.numerator;
                        in >> number.denominator;
                        return in;
                  }

     /*     void Complex :: comparison(Complex &num1, Complex &num2)
            {
                if(num1.Re>num2.Re) { cout << "Number 1 is to the right of Number 2" << endl;}
                if(num1.Re<num2.Re) { cout << "Number 1 is to the left of Number 2" << endl;}
                if(num1.Im>num2.Im) { cout << "Number 1 is higher in the complex system of axes than Number 2" << endl;}
                if(num1.Im<num2.Im) { cout << "Number 1 is lower in the complex system of axes than Number 2" << endl;}

            };
            */
// FRACTIONS END-----FRACTIONS END-----FRACTIONS END-----FRACTIONS END-----FRACTIONS END-----FRACTIONS END-----FRACTIONS END-----FRACTIONS END-----FRACTIONS END

int main()
{
    array2d <Complex> myclass(2);
    myclass.show();
   /* Fractions f1,f2;
    cin>>f1;
    cin>>f2;
    cout << "Multiplication " << f1 << " * " <<f2<< " = " <<f1*f2 <<endl;
    cout << "Division " << f1 << " DIVIDED BY " <<f2 <<" = " <<f1/f2 <<endl;
    Fractions f3,f4;
    f3=f1+f2;
    f4=f2-f1;
    cout << "Addition " << f2 << " + " <<f1 <<" = " <<f3 <<endl;
    cout << "Subtraction " << f2 << " - " <<f1 <<" = " <<f4 <<endl;
    return 0; */
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
