#include <iostream>

using namespace std;

class Complex{
    private:
        int real, imag;
    public:
        Complex(){
            real = 0;
            imag = 0;
        }
        Complex(int r, int i){
            real = r;
            imag = i;
        }

        Complex operator + (Complex&obj){
            return Complex(this->real + obj.real, this->imag + obj.imag);
        }

        Complex operator * (Complex&obj){
            return Complex(this->real * obj.real - this->imag * obj.imag, this->real * obj.imag + this->imag * obj.real);
        }

        friend istream &operator>>(istream&CIN, Complex&obj){
            CIN >> obj.real;
            CIN >> obj.imag;
            return CIN;
        }

        friend ostream &operator<< (ostream&COUT, Complex&obj){
            COUT << obj.real << " + " << obj.imag << "i" << endl;
            return COUT;
        }        
};



int main(){
    Complex c1, c2, result;
    cout << "Enter the first complex number (real then imaginary) " << endl;
    cin >> c1;
    cout << "Enter the second complex number (real then imaginary) " << endl;
    cin >> c2;

    cout << "The first complex number is : " << c1;
    cout << "The second complex number is : " << c2;

    result = c1 + c2;
    cout << "The sum of the complex numbers is : "<< result;

    result = c1 * c2;
    cout << "The product of the complex numbers is : "<< result;
}