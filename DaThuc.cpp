#include "DaThuc.h"
#include <cmath>
#include <algorithm>
using namespace std;
/*
Input: 
Output: Thuộc tính iBac được update
Hướng giải thuật: Giảm dần iBac nếu hệ số =  0 cho tới khi gặp hệ số khác 0 hoặc đạt bậc 0.
*/
void DaThuc::ChuanHoa(){
    while (iBac > 0 && aHeSo[iBac] == 0){
        iBac--;
    }
}
/*
Input: Bậc của đa thức
Output: 
Hướng giải thuật: Ép bậc về 0 nếu âm, cấp phát mảng hệ số mới và gán tất cả về 0.
*/
DaThuc::DaThuc(int bac){
    if (bac < 0) bac = 0;
    iBac = bac;
    aHeSo = new double[iBac + 1];
    for (int i = 0; i <= iBac; ++i){
        aHeSo[i] = 0;
    }
}
/*
Input: Đa thức
Output: 
Hướng giải thuật: Tạo một bản sao bằng cách sao chép bậc và cấp phát vùng nhớ mới để copy từng hệ số.
*/
DaThuc::DaThuc(const DaThuc& dt){
    iBac = dt.iBac;
    aHeSo = new double[iBac + 1];
    for (int i = 0; i <= iBac; ++i){
        aHeSo[i] = dt.aHeSo[i];
    }
}

/*
Input: 
Output: 
Hướng giải thuật: Giải phóng vùng nhớ cấp phát động bằng delete[].
*/
DaThuc::~DaThuc() {
    delete[] aHeSo;
}

/*
Input: Đa thức
Output: Tham chiếu tới chính đối tượng vế trái (*this).
Hướng giải thuật: Kiểm tra tự gán nếu không trùng thì xóa bộ nhớ cũ, cấp phát lại và sao chép dữ liệu mới.
*/
DaThuc& DaThuc::operator=(const DaThuc& dt){
    if (this != &dt) {
        delete[] aHeSo; 
        iBac = dt.iBac;
        aHeSo = new double[iBac + 1];
        for (int i = 0; i <= iBac; ++i){
            aHeSo[i] = dt.aHeSo[i];
        }
    }
    return *this;
}
/*
Input: Đa thức
Output: Tổng của hai đa thức
Hướng giải thuật: Tạo đa thức mới có bậc bằng max của hai đa thức, cộng các hệ số tương ứng rồi chuẩn hóa.
*/
DaThuc DaThuc::operator+(const DaThuc& dt) const{
    int maxBac = max(iBac, dt.iBac);
    DaThuc kq(maxBac);
    for (int i = 0; i <= maxBac; ++i) {
        double h1 = (i <= iBac) ? aHeSo[i] : 0;
        double h2 = (i <= dt.iBac) ? dt.aHeSo[i] : 0;
        kq.aHeSo[i] = h1 + h2;
    }
    kq.ChuanHoa();
    return kq;
}
/*
Input: Đa thức
Output: Hiệu của hai đa thức
Hướng giải thuật: Tạo đa thức mới có bậc bằng max của hai đa thức, trừ các hệ số tương ứng rồi chuẩn hóa.
*/
DaThuc DaThuc::operator-(const DaThuc& dt) const{
    int maxBac = max(iBac, dt.iBac);
    DaThuc kq(maxBac);
    for (int i = 0; i <= maxBac; ++i) {
        double h1 = (i <= iBac) ? aHeSo[i] : 0;
        double h2 = (i <= dt.iBac) ? dt.aHeSo[i] : 0;
        kq.aHeSo[i] = h1 - h2;
    }
    kq.ChuanHoa();
    return kq;
}
/*
Input: Đa thức
Output: Đa thức mới là tích của hai đa thức.
Hướng giải thuật: Tạo đa thức mới có bậc bằng tổng hai bậc, dùng 2 vòng lặp lồng nhau nhân hệ số rồi cộng dồn vào bậc tương ứng.
*/
DaThuc DaThuc::operator*(const DaThuc& dt) const{
    int bacTich = iBac + dt.iBac;
    DaThuc kq(bacTich);
    for (int i = 0; i <= iBac; ++i){
        for (int j = 0; j <= dt.iBac; ++j){
            kq.aHeSo[i + j] += aHeSo[i] * dt.aHeSo[j];
        }
    }
    kq.ChuanHoa();
    return kq;
}
/*
Input: Giá trị x
Output: Giá trị của đa thức voi x
Hướng giải thuật: Nhân từ hệ số bậc cao nhất xuống bậc 0
*/
double DaThuc::TinhGiaTri(double x) const {
    double kq = aHeSo[iBac];
    for (int i = iBac - 1; i >= 0; --i) {
        kq = kq * x + aHeSo[i];
    }
    return kq;
}
/*
Input: Luồng nhập,, đa thức cần lưu
Output: 
Hướng giải thuật: Nhập bậc mới, giải phóng mảng cũ, cấp phát mảng mới rồi cho nhập hệ số từ bậc cao về 0 và chuẩn hóa.
*/
istream& operator>>(istream& in, DaThuc& dt){
    int bac;
    cout << "Nhap bac cua da thuc (>=0): ";
    in >> bac;
    if (bac < 0) bac = 0;
    delete[] dt.aHeSo; 
    dt.iBac = bac;
    dt.aHeSo = new double[dt.iBac + 1];
    
    for (int i = dt.iBac; i >= 0; --i) {
        cout << "  + He so cua x^" << i << ": ";
        in >> dt.aHeSo[i];
    }
    dt.ChuanHoa();
    return in;
}
/*
Input: Luồng xuất (out), Đa thức cần in (dt).
Output: Luồng xuất (out).
Hướng giải thuật: Duyệt từ bậc cao về 0, xét các điều kiện để in dấu (+/-), in hệ số và biến x sao cho đẹp mắt.
*/
ostream& operator<<(ostream& out, const DaThuc& dt){
    bool checkDauTien = true; 
    if (dt.iBac == 0 && dt.aHeSo[0] == 0){
        out << "0";
        return out;
    }
    for (int i = dt.iBac; i >= 0; --i){
        if (dt.aHeSo[i] == 0) continue; 
        if (dt.aHeSo[i] > 0){
            if (!checkDauTien) out << " + ";
        }else {
            if (checkDauTien) out << "-";
            else out << " - ";
        }
        double triTuyetDoi = abs(dt.aHeSo[i]);
        if (triTuyetDoi != 1 || i == 0) {
            out << triTuyetDoi;
        }
        if (i > 1){
            out << "x^" << i;
        }else if (i == 1){
            out << "x";
        }
        checkDauTien = false;
    }
    return out;
}