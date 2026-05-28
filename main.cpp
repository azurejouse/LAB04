#include <iostream>
#include "CTime.h"
using namespace std;
int main(){
    CTime t1;
    cout << "Nhap thoi gian (gio phut giay): \n";
    cin >> t1;
    cout << "Thoi gian hien tai (da chuan hoa): " << t1 << "\n";
    int giayThem;
    cout << "Nhap so giay ban muon cong them: ";
    cin >> giayThem;
    cout << "Ket qua: " << t1 << " + " << giayThem << " giay = " << (t1 + giayThem) << "\n";
    int giayBot;
    cout << "Nhap so giay ban muon tru bot: ";
    cin >> giayBot;
    cout << "Ket qua: " << t1 << " - " << giayBot << " giay = " << (t1 - giayBot) << "\n";
    CTime t2 = t1;
    cout << "Thoi gian goc hien tai: " << t2 << "\n";
    cout << "Goi toan tu hau to t++: " << t2++ << " (Gia tri chua tang luc in)\n";
    cout << "Gia tri cua t luc sau : " << t2 << " (Gia tri da duoc tang)\n";
    cout << "Goi toan tu tien to ++t: " << ++t1 << " (Gia tri tang roi moi in)\n";
    cout << "Goi toan tu tien to --t: " << --t1 << " (Giam 1 giay de quay lai)";
    return 0;
}