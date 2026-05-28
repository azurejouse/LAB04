#ifndef CDATE_H
#define CDATE_H
#include <iostream>
using namespace std;
class CDate{
private:
    int iNgay;
    int iThang;
    int iNam;
    bool KiemTraNamNhuan(int nam) const;
    int SoNgayTrongThang(int thang, int nam) const;
    int ChuyenSangTongNgay() const;
    void ChuyenTuTongNgay(int tongNgay);
public:
    CDate(int ngay = 1, int thang = 1, int nam = 1);
    CDate operator+(int soNgay) const;
    CDate operator-(int soNgay) const;
    int operator-(const CDate& date) const;
    CDate& operator++();
    CDate& operator--();
    CDate operator++(int);
    CDate operator--(int);
    friend istream& operator>>(istream& in, CDate& date);
    friend ostream& operator<<(ostream& out, const CDate& date);
};
#endif