#include <iostream>
#include "CVector.h"
using namespace std;
int main(){
    CVector v1, v2;
    cout << "Nhap vector thu 1: \n";
    cin >> v1;
    cout << "-> Vector v1: " << v1 << " | Do dai = " << v1.TinhDoDai() << "\n\n";
    cout << "Nhap vector thu 2: \n";
    cin >> v2;
    cout << "-> Vector v2: " << v2 << " | Do dai = " << v2.TinhDoDai() << "\n\n";
    cout << "Ket qua: \n";
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 * v2 (Tich vo huong) = " << (v1 * v2) << endl;
    double k;
    cout << "\nNhap mot so thuc k de nhan voi v1: ";
    cin >> k;
    cout << "v1 * " << k << " = " << (v1 * k) << endl;
    return 0;
}