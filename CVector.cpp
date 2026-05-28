#include "CVector.h"
#include <cmath>
using namespace std;
/*
Input: Số chiều của vector
Output: 
Hướng giải thuật: Ép số chiều về 0 nếu âm, cấp phát mảng tọa độ mới và gán tất cả về 0.
*/
CVector::CVector(int soChieu){
    if (soChieu < 0) soChieu = 0;
    iSoChieu = soChieu;
    aThanhPhan = new double[iSoChieu];
    for (int i = 0; i < iSoChieu; ++i){
        aThanhPhan[i] = 0;
    }
}
/*
Input: Vector
Output: 
Hướng giải thuật: Sao chép số chiều, cấp phát vùng nhớ và copy từng tọa độ.
*/
CVector::CVector(const CVector& v){
    iSoChieu = v.iSoChieu;
    aThanhPhan = new double[iSoChieu];
    for (int i = 0; i < iSoChieu; ++i) {
        aThanhPhan[i] = v.aThanhPhan[i];
    }
}
/*
Input: 
Output: 
Hướng giải thuật: Giải phóng vùng nhớ bằng delete[].
*/
CVector::~CVector(){
    delete[] aThanhPhan;
}
/*
Input: Vector
Output:
Hướng giải thuật: Kiểm tra tự gán nếu không trùng thì giải phóng bộ nhớ cũ, cấp phát lại và copy dữ liệu
*/
CVector& CVector::operator=(const CVector& v){
    if (this != &v) {
        delete[] aThanhPhan;
        iSoChieu = v.iSoChieu;
        aThanhPhan = new double[iSoChieu];
        for (int i = 0; i < iSoChieu; ++i){
            aThanhPhan[i] = v.aThanhPhan[i];
        }
    }
    return *this;
}
/*
Input: Vector
Output: Vector mới là tổng hai vector
Hướng giải thuật: Nếu cùng số chiều, tạo vector mới và cộng lần lượt từng tọa độ tương ứng của 2 vector
*/
CVector CVector::operator+(const CVector& v) const{
    if (iSoChieu != v.iSoChieu) {
        cout << "Loi khong the tinh vi cung so chieu!\n";
        return CVector(0);
    }
    CVector kq(iSoChieu);
    for (int i = 0; i < iSoChieu; ++i){
        kq.aThanhPhan[i] = aThanhPhan[i] + v.aThanhPhan[i];
    }
    return kq;
}
/*
Input: Vector
Output: Vector mới là hiệu hai vector
Hướng giải thuật: Nếu cùng số chiều, tạo vector mới và lấy tọa độ vector hiện tại trừ đi tọa độ của v
*/
CVector CVector::operator-(const CVector& v) const{
    if (iSoChieu != v.iSoChieu){
        cout << "Loi khong the tinh vi cung so chieu!\n";
        return CVector(0);
    }
    CVector kq(iSoChieu);
    for (int i = 0; i < iSoChieu; ++i){
        kq.aThanhPhan[i] = aThanhPhan[i] - v.aThanhPhan[i];
    }
    return kq;
}
/*
Input: Vector
Output: Giá trị tích vô hướng
Hướng giải thuật: Nhân từng tọa độ tương ứng của hai vector rồi cộng dồn tất cả lại thành một số thực
*/
double CVector::operator*(const CVector& v) const{
    if (iSoChieu != v.iSoChieu) {
        cout << "Loi khong the tinh vi cung so chieu!\n";
        return 0;
    }
    double tichVoHuong = 0;
    for (int i = 0; i < iSoChieu; ++i){
        tichVoHuong += aThanhPhan[i] * v.aThanhPhan[i];
    }
    return tichVoHuong;
}
/*
Input: Số thực k.
Output: Vector mới đã được tỷ lệ
Hướng giải thuật: Nhân hệ số k vào tất cả các thành phần tọa độ của vector hiện tại
*/
CVector CVector::operator*(double k) const{
    CVector kq(iSoChieu);
    for (int i = 0; i < iSoChieu; ++i){
        kq.aThanhPhan[i] = aThanhPhan[i] * k;
    }
    return kq;
}
/*
Input: 
Output: Độ dài của vector
Hướng giải thuật: Tính tổng bình phương các tọa độ rồi lấy căn bậc hai
*/
double CVector::TinhDoDai() const{
    double tongBinhPhuong = 0;
    for (int i = 0; i < iSoChieu; ++i){
        tongBinhPhuong += aThanhPhan[i] * aThanhPhan[i];
    }
    return sqrt(tongBinhPhuong);
}
/*
Input: Luồng nhập, Vector cần lưu
Output: 
Hướng giải thuật: Nhập số chiều mới roiof cấp phát lại mảng và lần lượt nhập các thành phần tọa độ
*/
istream& operator>>(istream& in, CVector& v){
    int n;
    cout << "Nhap so chieu cua vector: ";
    in >> n;
    if (n < 0) n = 0;
    delete[] v.aThanhPhan;
    v.iSoChieu = n;
    v.aThanhPhan = new double[v.iSoChieu];
    for (int i = 0; i < v.iSoChieu; ++i){
        cout << "  + Thanh phan thu " << i + 1 << ": ";
        in >> v.aThanhPhan[i];
    }
    return in;
}
/* 
Input: Vector cần in
Output: các Vector cần in
Hướng giải thuật: In tọa độ theo dạng chuẩn
*/
ostream& operator<<(ostream& out, const CVector& v){
    out << "(";
    for (int i = 0; i < v.iSoChieu; ++i){
        out << v.aThanhPhan[i];
        if (i < v.iSoChieu - 1){
            out << ", ";
        }
    }
    out << ")";
    return out;
}