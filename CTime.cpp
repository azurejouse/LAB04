#include "CTime.h"
#include <iomanip>
using namespace std;
/*
- Input:
- Output: gio phut giay theo dong ho 24h
- Giai thuat: 
  1. Quy doi tat ca ra tong so giay
  2. Loai bo cac ngay thua bang phep chia lay du cho so giay trong 1 ngay
  3. Neu tong giay bi am, cong them 86400 de vong nguoc ve full ngay.
  4. Quy doi nguoc lai ra gio, phut, giay
*/
void CTime::ChuanHoa(){
    long long tongGiay = (long long)iGio * 3600 + iPhut * 60 + iGiay;
    tongGiay = tongGiay % 86400; 
    if (tongGiay < 0){
        tongGiay += 86400; 
    }
    iGio = tongGiay / 3600;
    iPhut = (tongGiay % 3600)/60;
    iGiay = tongGiay % 60;
}
/*
- Input: gio, phut, giay
- Output: khoi tao duoc CTime
- Giai thuat: Gan gia tri truyen vao sau do goi ChuanHoa() de chuan hoa
*/
CTime::CTime(int gio, int phut, int giay){
    iGio = gio;
    iPhut = phut;
    iGiay = giay;
    ChuanHoa();
}
/*
- Input: giay_them
- Output: CTime moi
- Giai thuat: Tao mot CTime moi voi so giay hien tai + giay_them
*/
CTime CTime::operator+(int giay_them) const{
    return CTime(iGio, iPhut, iGiay + giay_them);
}
/*
- Input: giay_bot
- Output: CTime moi
- Giai thuat: Truyen iGiay - giay_bot vao constructor de tra ve CTime moi
*/
CTime CTime::operator-(int giay_bot) const{
    return CTime(iGio, iPhut, iGiay - giay_bot);
}
/*
- Input:
- Output: CTime hien tai sau khi da tang 1 giay
- Giai thuat: Tang iGiay len 1, goi ChuanHoa(), va tra ve chinh no (*this).
*/
CTime& CTime::operator++(){
    iGiay++;
    ChuanHoa();
    return *this;
}
/*
- Input:
- Output: CTime hien tai sau khi da giam 1 giay
- Giai thuat: Giam iGiay xuong 1, goi ChuanHoa(), va tra ve chinh no (*this).
*/
CTime& CTime::operator--(){
    iGiay--;
    ChuanHoa();
    return *this;
}
/*
- Input: Doi so ao
- Output: Ban sao CTime truoc khi tang 1 giay
- Giai thuat: Tao mot ban sao CTime (temp), tang giay cua doi tuong goc len 1, ChuanHoa(). Roi tra ve ban sao temp kia
*/
CTime CTime::operator++(int) {
    CTime temp = *this;
    iGiay++;
    ChuanHoa();
    return temp;
}
/*
- Input: Doi so ao
- Output: Ban sao CTime truoc khi giam 1 giay
- Giai thuat: Tao mot ban sao CTime (temp), giam giay cua doi tuong goc xuong 1, ChuanHoa(). Roi tra ve ban sao temp kia
*/
CTime CTime::operator--(int){
    CTime temp = *this;
    iGiay--;
    ChuanHoa();
    return temp;
}
/*
- Input:  istream& in, CTime& t
- Output:
- Giai thuat: Nhap lan luot gio, phut, giay
*/
istream& operator>>(istream& in, CTime& t) {
    cout << "Nhap Gio: ";   in >> t.iGio;
    cout << "Nhap Phut: ";  in >> t.iPhut;
    cout << "Nhap Giay: ";  in >> t.iGiay;
    t.ChuanHoa();
    return in;
}
/*
- Input:  ostream& out, const CTime& t
- Output: chuoi thoi gian
- Giai thuat: Su dung setfill('0') va setw(2) de ep in ra 2 chu so
*/
ostream& operator<<(ostream& out, const CTime& t){
    out << setfill('0') << setw(2) << t.iGio << ":"
        << setfill('0') << setw(2) << t.iPhut << ":"
        << setfill('0') << setw(2) << t.iGiay;
    return out;
}