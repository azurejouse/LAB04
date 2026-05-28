#include "SoPhuc.h"
#include <cmath>
/*
- Input:  double thuc, double ao
- Output: doi tuong SoPhuc duoc khoi tao gia tri
- Giai thuat: su dung khoi tao danh sanh thanh vien de gan truc tiep gia tri vao bien private.
*/
SoPhuc::SoPhuc(double thuc, double ao) : iThuc(thuc), iAo(ao) {}
/*
- Input:  const SoPhuc& sp
- Output: doi tuong SoPhuc moi gia tri tong
- Giai thuat: cong thuc: (a + bi) + (c + di) = (a+c) + (b+d)i
*/
SoPhuc SoPhuc::operator+(const SoPhuc& sp) const{
    return SoPhuc(iThuc + sp.iThuc, iAo + sp.iAo);
}
/*
- Input:  const SoPhuc& sp
- Output: Doi tuong SoPhuc moi gia tri hieu
- Giai thuat: cong thuc: (a + bi) - (c + di) = (a-c) + (b-d)i
*/
SoPhuc SoPhuc::operator-(const SoPhuc& sp) const{
    return SoPhuc(iThuc - sp.iThuc, iAo - sp.iAo);
}
/*
- Input:  const SoPhuc& sp
- Output: Doi tuong SoPhuc moi gia tri tich
- Giai thuat: cong thuc: (a + bi)*(c + di) = (ac - bd) + (ad + bc)i
*/
SoPhuc SoPhuc::operator*(const SoPhuc& sp) const{
    return SoPhuc(iThuc * sp.iThuc - iAo * sp.iAo, iThuc * sp.iAo + iAo * sp.iThuc);
}
/*
- Input:  const SoPhuc& sp
- Output: Doi tuong SoPhuc moi gia tri thuong
- Giai thuat: cong thuc: (a+bi)/(c+di) = [(ac+bd) + (bc-ad)i] / (c^2+d^2)
*/
SoPhuc SoPhuc::operator/(const SoPhuc& sp) const{
    double mauSo = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
    if (std::abs(mauSo) < 1e-9){    // 1e-9 giúp tránh chia cho zero và làm đẹp số thực
        std::cout << "Loi chia cho so phuc zero" << std::endl;
        return SoPhuc(0, 0);
    }
    double thuc = (iThuc * sp.iThuc + iAo * sp.iAo)/mauSo;
    double ao = (iAo * sp.iThuc - iThuc * sp.iAo)/mauSo;
    return SoPhuc(thuc, ao);
}
/*
- Input:  const SoPhuc& sp
- Output: Kieu bool (true neu bang, false neu khac)
- Giai thuat: Vi kieu double luon co sai so lam tron, ta khong dung == truc tiep ma tinh tri tuyet doi hieu phan thuc va phan ao. 
neu deu nho hon 1e-9 thi ket luan la bang nhau.
*/
bool SoPhuc::operator==(const SoPhuc& sp) const{
    return (abs(iThuc - sp.iThuc) < 1e-9 && abs(iAo - sp.iAo) < 1e-9);
}
/*
- Input:  const SoPhuc& sp
- Output: Kieu bool
- Giai thuat: Phu dinh lai ket qua cua toan tu == va goi cau lenh !(*this == sp) de tai su dung code.
*/
bool SoPhuc::operator!=(const SoPhuc& sp) const{
    return !(*this == sp);
}
/*
- Input:  istream& in, SoPhuc& sp 
- Output: istream& in sau khi da nhap du lieu vao sp
- Giai thuat: Dung vong lap vo han while(1), dung in.fail() kiem tra xem co bi nhap loi chu hay khong, neu loi,
goi in.clear() xoa dong co loi va in.ignore() xoa loi
*/
istream& operator>>(istream& in, SoPhuc& sp){
    while(1){
        cout << "Phan thuc: ";
        in >> sp.iThuc;
        if(!in.fail()){
            cout << "Phan ao: ";
            in >> sp.iAo;
            if(!in.fail()){
                break; 
            }
        }
        cout << "Du lieu nhap vao khong phai la so!\n";
        in.clear();
        in.ignore(10000, '\n');
    }
    return in;
}
/*
- Input:  ostream& out, const SoPhuc& sp
- Output: ostream& out
- Giai thuat: chia cac truong hop de hien thi dep nhat:
              - Ao = 0: Chi in phan Thuc.
              - Thuc = 0: Chi in phan Ao dinh kem chu 'i'.
              - Co ca Thuc va Ao: Kiem tra dau cua Ao de in ra dang 
                "a + bi" hoac "a - bi" (su dung abs de xoa dau tru trung).
*/
ostream& operator<<(ostream& out, const SoPhuc& sp){
    if(abs(sp.iAo) < 1e-9){
        out << sp.iThuc;
    } 
    else if(abs(sp.iThuc) < 1e-9){
        out << sp.iAo << "i";
    }else{
        if(sp.iAo > 0){
            out << sp.iThuc << " + " << sp.iAo << "i";
        }else{
            out << sp.iThuc << " - " << abs(sp.iAo) << "i";
        }
    }
    return out;
}