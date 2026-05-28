#include <iostream>
#include "CMatrix.h"
#include "CVector.h"
using namespace std;
int main(){
    CMatrix A, B;
    CVector v;
    cout << "Nhap du lieu: " << "\n";
    cout << "1. Nhap Ma tran A:\n"; cin >> A;
    cout << "2. Nhap Ma tran B:\n"; cin >> B;
    cout << "3. Nhap Vector v:\n";  cin >> v;

    cout << "Data: " << "\n";
    cout << "Ma tran A:\n" << A;
    cout << "Ma tran B:\n" << B;
    cout << "Vector v: " << v << "\n";

    cout << "Ket qua: " << "\n";
    cout << "-> Kiem tra A == B: " << ((A == B) ? "DUNG (Hai ma tran bang nhau)" : "SAI (Hai ma tran khac nhau)") << "\n\n";
    cout << "-> Tinh dinh thuc det(A): " << A.TinhDeterminant() << "\n";
    cout << "-> Tinh dinh thuc det(B): " << B.TinhDeterminant() << "\n\n";
    cout << "-> Phep cong (A + B):\n" << (A + B);
    cout << "-> Phep tru (A - B):\n" << (A - B);
    cout << "-> Phep nhan hai ma tran (A * B):\n" << (A * B);
    cout << "-> Phep nhan Ma tran x Vector (A * v): " << (A * v) << "\n";
    return 0;
}