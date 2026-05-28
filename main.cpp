#include <iostream>
#include <iomanip>
#include "CDate.h"
using namespace std;
int main(){
    CDate d1;
    cout << "Nhap ngay hien tai (ngay thang nam):\n";
    cin >> d1;
    int soNgay;
    cout << "Nhap so ngay muon cong: "; cin >> soNgay;
    cout << d1 << " cong " << soNgay << " ngay la: " << (d1 + soNgay) << endl;
    cout << "Nhap so ngay muon tru: "; cin >> soNgay;
    cout << d1 << " tru " << soNgay << " ngay la: " << (d1 - soNgay) << endl;
    CDate d2 = d1;
    cout << "Hien tai: " << d2 << endl;
    cout << "Goi ++d : " << ++d2 << endl;
    cout << "Goi --d2: " << --d2 << endl;
    double tienGoc, laiSuatNam;
    CDate ngayGui, ngayRut;
    cout << "Nhap so tien goc gui vao : "; 
    cin >> tienGoc;
    cout << "Nhap lai suat nam (%/nam): "; 
    cin >> laiSuatNam;
    cout << "Nhap ngay bat dau gui tien:\n";
    cin >> ngayGui;
    cout << "Nhap ngay rut tien:\n";
    cin >> ngayRut;
    int khoangCachNgay = ngayRut - ngayGui;
    if (khoangCachNgay < 0){
        cout << "Loi Ngay rut tien khong the nho hon ngay gui\n";
    }else{
        double tienLai = tienGoc * (laiSuatNam / 100.0) * ((double)khoangCachNgay / 365.0);
        double tongTienNhan = tienGoc + tienLai;
        cout << "Tu ngay " << ngayGui << " den " << ngayRut << endl;
        cout << "Tong thoi gian gui : " << khoangCachNgay << " ngay.\n";
        cout << fixed << setprecision(0);
        cout << "Tien lai phat sinh : " << tienLai << " VND\n";
        cout << "Tong tien thuc nhan: " << tongTienNhan << " VND\n";
    }
    return 0;
}