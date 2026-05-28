#include "PhanSo.h"
#include <cmath>
/*
- Input:  a va b
- Output: UCLN cua a va b
- Giai thuat: Su dung thuat toan Euclid, lay tri tuyet doi truoc khi tinh. Neu ket qua ra 0 
thi ep ve 1 de tranh loi chia cho 0
*/
int PhanSo::TimUSCLN(int a, int b) const{
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a == 0 ? 1 : a;
}
/*
- Input:  int tu, int mau
- Output: Doi tuong PhanSo hoan chinh
- Giai thuat: Kiem tra loi mau = 0, neu dung thi ep mau = 1. Gan gia tri cho iTu, iMau va RutGon() 
de phan so luon o dang toi gian
*/
PhanSo::PhanSo(int tu, int mau){
    if(mau == 0){
        std::cout << "Mau so bang 0! Tu dong dua ve = 1\n";
        iTu = tu;
        iMau = 1;
    }else{
        iTu = tu;
        iMau = mau;
    }
    RutGon();
}
/*
- Input: 
- Output: gia tri iTu va iMau
- Giai thuat: Chia ca iTu va iMau cho USCLN cua chung, neu iMau am, nhan ca tu va mau voi -1 de dua dau tru len tu
*/
void PhanSo::RutGon(){
    int uscln = TimUSCLN(iTu, iMau);
    iTu /= uscln;
    iMau /= uscln;
    if(iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}
/*
- Input:  const PhanSo& ps
- Output: doi tuong PhanSo moi mang gia tri tong
- Giai thuat: quy dong va cong tu: (a/b) + (c/d) = (a*d + c*b) / (b*d)
*/
PhanSo PhanSo::operator+(const PhanSo& ps) const{
    return PhanSo(iTu * ps.iMau + ps.iTu * iMau, iMau * ps.iMau);
}
/*
- Input:  const PhanSo& ps
- Output: Doi tuong PhanSo moi mang gia tri hieu
- Giai thuat: Quy dong va tru tu: (a/b) - (c/d) = (a*d - c*b) / (b*d)
*/
PhanSo PhanSo::operator-(const PhanSo& ps) const{
    return PhanSo(iTu * ps.iMau - ps.iTu * iMau, iMau * ps.iMau);
}
/*
- Input:  const PhanSo& ps
- Output: Doi tuong PhanSo moi mang gia tri tich
- Giai thuat: Tu nhan tu, mau nhan mau: (a/b) * (c/d) = (a*c) / (b*d)
*/
PhanSo PhanSo::operator*(const PhanSo& ps) const{
    return PhanSo(iTu * ps.iTu, iMau * ps.iMau);
}
/*
- Input:  const PhanSo& ps
- Output: Doi tuong PhanSo moi mang gia tri thuong
- Giai thuat: Nhan nghich dao: (a/b) / (c/d) = (a*d) / (b*c)
Kiem tra neu tu so cua so chia bang 0 (ps.iTu == 0), thi bao loi chia cho 0 va tra ve phan so 0/1(tranh loi)
*/
PhanSo PhanSo::operator/(const PhanSo& ps) const{
    if(ps.iTu == 0){
        std::cout << "Loi chia cho 0! ";
        return PhanSo(0, 1);
    }
    return PhanSo(iTu * ps.iMau, iMau * ps.iTu);
}
/*
- Input:  const PhanSo& ps
- Output: Kieu bool
- Giai thuat: Vi cac phan so deu da duoc RutGon() toi gian, chi can so sanh (iTu == ps.iTu && iMau == ps.iMau)
*/
bool PhanSo::operator==(const PhanSo& ps) const{
    return (iTu == ps.iTu && iMau == ps.iMau);
}
/*
- Input:  const PhanSo& ps
- Output: Kieu bool
- Giai thuat: Su dung tich cheo de so sanh ma khong can doi sang so thuc: a/b > c/d <=> a*d > c*b (mau luonduong*)
*/
bool PhanSo::operator>(const PhanSo& ps) const{
    return (iTu * ps.iMau > ps.iTu * iMau);
}
/*
- Input:  const PhanSo& ps
- Output: Kieu bool
- Giai thuat: Tuong tu toan tu >, tich cheo so sanh: a*d < c*b
*/
bool PhanSo::operator<(const PhanSo& ps) const{ 
    return (iTu * ps.iMau < ps.iTu * iMau);
}
/*
- Input:  istream& in, PhanSo& ps
- Output: xu ly de cho phep nhap lien tiep
- Giai thuat: Nhap tu so sau do dung vong lap while(1) bat nguoi dung
nhap mau so cho den khi mau khac 0
*/
istream& operator>>(istream& in, PhanSo& ps){
    cout << "Nhap tu so: ";
    in >> ps.iTu;
    while(1){
        cout << "Nhap mau so: ";
        in >> ps.iMau;
        if (ps.iMau != 0) break;
        cout << "Mau so phai khac 0! Vui long nhap lai.\n";
    }
    ps.RutGon();
    return in;
}
/*
- Input:  ostream& out, const PhanSo& ps
- Output: sau xu ly va cho phep in lien tiep
- Giai thuat: Kiem tra neu mau so iMau == 1 thi chi in minh iTu. Nguoc lai in dang chuan dinh dang tu/mau
*/
std::ostream& operator<<(std::ostream& out, const PhanSo& ps){
    if(ps.iMau == 1){
        out << ps.iTu;
    }else{
        out << ps.iTu << "/" << ps.iMau;
    }
    return out;
}