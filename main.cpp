#include <iostream>
#include "SoPhuc.h"
using namespace std;
int main(){
    SoPhuc sp1, sp2;
    cout << "Nhap so phuc 1:\n";
    cin >> sp1;
    cout << "Nhap so phuc 2:\n";
    cin >> sp2;
    cout << "Tong:  " << (sp1 + sp2) << endl;
    cout << "Hieu:  " << (sp1 - sp2) << endl;
    cout << "Tich:  " << (sp1 * sp2) << endl;
    cout << "Thuong: " << (sp1 / sp2) << endl;
    if (sp1 == sp2) {
        cout << "Hai so phuc bang nhau.\n";
    } else {
        cout << "Hai so phuc khac nhau.\n";
    }
    return 0;
}