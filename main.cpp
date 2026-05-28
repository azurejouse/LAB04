#include <iostream>
#include "PhanSo.h"
using namespace std;
int main(){
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu 1:\n";
    cin >> ps1;
    cout << "\nNhap phan so thu 2:\n";
    cin >> ps2;
    cout << "Tong:  " << (ps1 + ps2) << endl;
    cout << "Hieu:  " << (ps1 - ps2) << endl;
    cout << "Tich:  " << (ps1 * ps2) << endl;
    cout << "Thuong: " << (ps1 / ps2) << endl;
    if (ps1 == ps2){
        cout << "Hai phan so bang nhau\n";
    }
    if (ps1 > ps2){
        cout << "Phan so 1 lon hon phan so 2\n";
    }
    if (ps1 < ps2){
        cout << "Phan so 1 nho hon phan so 2\n";
    }
    return 0;
}