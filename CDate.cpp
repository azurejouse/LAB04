#include "CDate.h"
#include <iomanip>
#include <cmath>
using namespace std;
/*
- Input: nam
- Output: true neu la nam nhuan, nguoc lai la false
- Giai thuat: Nam nhuan la nam chia het cho 400, hoac chia het cho 4 nhung khong chia het cho 100.
*/
bool CDate::KiemTraNamNhuan(int nam) const{
    return (nam % 400 == 0) || ((nam % 4 == 0) && (nam % 100 != 0));
}
/*
- Input: thang, nam
- Output: So ngay toi da cua thang do trong nam do
- Giai thuat: Dung mang luu so ngay cua 12 thang. Rieng thang 2 neu la nam nhuan thi tra ve 29
*/
int CDate::SoNgayTrongThang(int thang, int nam) const{
    int ngayThang[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && KiemTraNamNhuan(nam)) return 29;
    return ngayThang[thang - 1];
}
/*
- Input:
- Output: Tong so ngay dem tu 01/01/0001
- Giai thuat: Cong don so ngay cua cac nam da qua, cong don so ngay cua cac thang da qua, sau do cong them ngay hien tai.
*/
int CDate::ChuyenSangTongNgay() const{
    int tong = iNgay;
    for (int y = 1; y < iNam; ++y){
        tong += KiemTraNamNhuan(y) ? 366 : 365;
    }
    for (int m = 1; m < iThang; ++m){
        tong += SoNgayTrongThang(m, iNam);
    }
    return tong;
}
/*
- Input: tongNgay
- Output: Cap nhat lai iNgay, iThang, iNam tuong ung
- Giai thuat: 
  - Tru dan so ngay cua nam tiep theo cho den khi tongNgay khong du 1 nam nua.
  - Tru dan so ngay cua thang tiep theo cho den khi khong du 1 thang.
  - Phan du con lai chinh la ngay hien tai.
*/
void CDate::ChuyenTuTongNgay(int tongNgay){
    if(tongNgay < 1)tongNgay = 1;
    int y = 1;
    while(tongNgay > (KiemTraNamNhuan(y) ? 366 : 365)){
        tongNgay = tongNgay - (KiemTraNamNhuan(y) ? 366 : 365);
        y++;
    }
    int m = 1;
    while (tongNgay > SoNgayTrongThang(m, y)){
        tongNgay = tongNgay - SoNgayTrongThang(m, y);
        m++;
    }
    iNam = y;
    iThang = m;
    iNgay = tongNgay;
}
CDate::CDate(int ngay, int thang, int nam) : iNgay(ngay), iThang(thang), iNam(nam) {}
/*
- Input: soNgay
- Output: CDate moi
- Giai thuat: Chuyen ngay hien tai ve TongNgay sau do cong them soNgay sau do chuyen nguoc lai thanh CDate.
*/
CDate CDate::operator+(int soNgay) const{
    CDate kq;
    kq.ChuyenTuTongNgay(this->ChuyenSangTongNgay() + soNgay);
    return kq;
}
/*
- Input: soNgay
- Output: CDate moi
- Giai thuat: Chuyen ve TongNgay sau do tru di soNgay chuyen nguoc lai thanh CDate.
*/
CDate CDate::operator-(int soNgay) const{
    CDate kq;
    kq.ChuyenTuTongNgay(this->ChuyenSangTongNgay() - soNgay);
    return kq;
}
/*
- Input: date (ngay can tinh chenh lech)
- Output: so ngay chenh lech
- Giai thuat: Lay TongNgay cua doi tuong hien tai tru di TongNgay cua date truyen vao
*/
int CDate::operator-(const CDate& date) const{
    return this->ChuyenSangTongNgay() - date.ChuyenSangTongNgay();
}
CDate& CDate::operator++(){
    this->ChuyenTuTongNgay(this->ChuyenSangTongNgay() + 1);
    return *this;
}
CDate& CDate::operator--(){
    this->ChuyenTuTongNgay(this->ChuyenSangTongNgay() - 1);
    return *this;
}
CDate CDate::operator++(int){
    CDate temp = *this;
    this->ChuyenTuTongNgay(this->ChuyenSangTongNgay() + 1);
    return temp;
}
CDate CDate::operator--(int){
    CDate temp = *this;
    this->ChuyenTuTongNgay(this->ChuyenSangTongNgay() - 1);
    return temp;
}
/*
- Input:  istream& in, CDate& date
- Giai thuat: Nhap lan luot ngay thang nam va kiem tra tinh hop le
*/
istream& operator>>(istream& in, CDate& date){
    do { cout << "  + Nhap nam (>= 1): "; in >> date.iNam; } while (date.iNam < 1);
    do { cout << "  + Nhap thang (1-12): "; in >> date.iThang; } while (date.iThang < 1 || date.iThang > 12);
    do { cout << "  + Nhap ngay: "; in >> date.iNgay; } while (date.iNgay < 1 || date.iNgay > date.SoNgayTrongThang(date.iThang, date.iNam));
    return in;
}
ostream& operator<<(ostream& out, const CDate& date){
    out << setfill('0') << setw(2) << date.iNgay << "/" << setfill('0') << setw(2) << date.iThang << "/"
    << setfill('0') << setw(4) << date.iNam;
    return out;
}