#ifndef MYCLASSES_H_INCLUDED
#define MYCLASSES_H_INCLUDED

class Complex {
    private:
    double Re, Im;
    public:
        Complex(){Re=0; Im=0;} // cout << " default \n";};
        Complex ( const double r )
        {
            Re=r;
            Im=0;
           // cout << " \n complex1 \n";
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

#endif // MYCLASSES_H_INCLUDED
