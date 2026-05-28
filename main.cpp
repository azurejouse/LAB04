#include <iostream>
#include "DaThuc.h"
using namespace std;
int main(){
    DaThuc f1, f2;
    cout << "Nhap f1: \n";
    cin >> f1;
    cout << "-> Da thuc f1: " << f1 << "\n";
    cout << "Nhap f2: \n";
    cin >> f2;
    cout << "-> Da thuc f2: " << f2 << "\n";
    cout << "Ket qua: \n";
    cout << "f1 + f2 = " << (f1 + f2) << endl;
    cout << "f1 - f2 = " << (f1 - f2) << endl;
    cout << "f1 * f2 = " << (f1 * f2) << endl;
    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    cout << "Gia tri f1(" << x << ") = " << f1.TinhGiaTri(x) << endl;
    cout << "Gia tri f2(" << x << ") = " << f2.TinhGiaTri(x) << endl;
    return 0;
}