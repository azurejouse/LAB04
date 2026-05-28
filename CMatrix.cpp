#include "CMatrix.h"
using namespace std;
/*
Input: Số dòng, số cột
Output: 
Hướng giải thuật: Ép dòng or cột về 0 nếu âm. Cấp phát động mảng con trỏ 2 chiều và gán toàn bộ bằng 0.
*/
CMatrix::CMatrix(int dong, int cot){
    if (dong < 0) dong = 0;
    if (cot < 0) cot = 0;
    iDong = dong;
    iCot = cot;
    aPhanTu = new double*[iDong];
    for (int i = 0; i < iDong; ++i) {
        aPhanTu[i] = new double[iCot];
        for (int j = 0; j < iCot; ++j){
            aPhanTu[i][j] = 0;
        }
    }
}
/*
Input: Ma trận
Output: 
Hướng giải thuật: Sao chép kích thước cấp phát vùng nhớ mới và copy toàn bộ các phần tử sang
*/
CMatrix::CMatrix(const CMatrix& m){
    iDong = m.iDong;
    iCot = m.iCot;

    aPhanTu = new double*[iDong];
    for (int i = 0; i < iDong; ++i){
        aPhanTu[i] = new double[iCot];
        for (int j = 0; j < iCot; ++j) {
            aPhanTu[i][j] = m.aPhanTu[i][j];
        }
    }
}
/*
Input: 
Output: 
Hướng giải thuật: Duyệt qua từng dòng để delete[] bộ nhớ của cột, sau đó delete[] con trỏ quản lý dòng
*/
CMatrix::~CMatrix(){
    for (int i = 0; i < iDong; ++i){
        delete[] aPhanTu[i];
    }
    delete[] aPhanTu;
}
/*
Input: Ma trận
Output:
Hướng giải thuật: Kiểm tra gán nếu không trùng thì xóa bộ nhớ cũ cấp phát lại và sao chép dữ liệu mới
*/
CMatrix& CMatrix::operator=(const CMatrix& m){
    if(this != &m){
        for(int i = 0; i < iDong; ++i){
            delete[] aPhanTu[i];
        }
        delete[] aPhanTu;
        iDong = m.iDong;
        iCot = m.iCot;
        aPhanTu = new double*[iDong];
        for (int i = 0; i < iDong; ++i){
            aPhanTu[i] = new double[iCot];
            for (int j = 0; j < iCot; ++j){
                aPhanTu[i][j] = m.aPhanTu[i][j];
            }
        }
    }
    return *this;
}
/*
Input: Ma trận
Output: Ma trận mới là tổng 2 ma trận.
Hướng giải thuật: Kiểm tra cùng kích thước cộng các phần tử ở vị trí tương ứng
*/
CMatrix CMatrix::operator+(const CMatrix& m) const{
    if (iDong != m.iDong || iCot != m.iCot){
        cout << "Loi khong cung kich thuoc!\n";
        return CMatrix(0, 0);
    }
    CMatrix kq(iDong, iCot);
    for(int i = 0; i < iDong; ++i) {
        for (int j = 0; j < iCot; ++j) {
            kq.aPhanTu[i][j] = aPhanTu[i][j] + m.aPhanTu[i][j];
        }
    }
    return kq;
}
/*
Input: Ma trận
Output: Ma trận mới là hiệu 2 ma trận
Hướng giải thuật: Kiểm tra cùng kích thước, lấy phần tử ma trận hiện tại trừ đi phần tử của m tại i, j
*/
CMatrix CMatrix::operator-(const CMatrix& m) const{
    if(iDong != m.iDong || iCot != m.iCot) {
        cout << "Loi khong cung kich thuoc!\n";
        return CMatrix(0, 0);
    }
    CMatrix kq(iDong, iCot);
    for (int i = 0; i < iDong; ++i){
        for (int j = 0; j < iCot; ++j){
            kq.aPhanTu[i][j] = aPhanTu[i][j] - m.aPhanTu[i][j];
        }
    }
    return kq;
}
/*
Input: Ma trận
Output: Ma trận kết quả mới
Hướng giải thuật: Check số cột ma trận trước = Số dòng ma trận sau rồi dùng 3 vòng lặp lồng nhau tính tổng tích hàng nhân cột
*/
CMatrix CMatrix::operator*(const CMatrix& m) const{
    if (iCot != m.iDong) {
        cout << "Loi khong cung kich thuoc!\n";
        return CMatrix(0, 0);
    }
    CMatrix kq(iDong, m.iCot);
    for(int i = 0; i < iDong; ++i){
        for (int j = 0; j < m.iCot; ++j) {
            for (int k = 0; k < iCot; ++k){
                kq.aPhanTu[i][j] += aPhanTu[i][k] * m.aPhanTu[k][j];
            }
        }
    }
    return kq;
}
/*
Input: Vector
Output: Vector kết quả mới.
Hướng giải thuật: Điều kiện: Số cột ma trận = Số chiều vector, kết quả thu được là một Vector mới có số chiều bằng số dòng của ma trận
*/
CVector CMatrix::operator*(const CVector& v) const{
    if (iCot != v.GetSoChieu()){
        std::cout << "Loi kich thuoc khong hop le de nhan!\n";
        return CVector(0);
    }
    CVector kq(iDong); 
    for(int i = 0; i < iDong; ++i){
        double tong = 0;
        for (int j = 0; j < iCot; ++j) {
            tong += aPhanTu[i][j] * v[j]; 
        }
        kq[i] = tong;
    }
    return kq; 
}
/*
Output: Trả về số chiều của vector
*/
int CVector::GetSoChieu() const{
    return iSoChieu;
}
/*
Input: Chỉ số phần tử i
Output: Tham chiếu đến phần tử thứ i để có thể gán giá trị
*/
double& CVector::operator[](int i){
    return aThanhPhan[i];
}
/*
Input: Chỉ số phần tử i (int).
Output: Giá trị của phần tử thứ i.
*/
double CVector::operator[](int i) const{
    return aThanhPhan[i];
}
/*
Input: Ma trận
Output: true (nếu bằng nhau), false (nếu khác nhau)
Hướng giải thuật: Kiểm tra kích thước trước, nếu lệch là false ngay. Sau đó duyệt từng phần tử, chỉ cần 1 cặp lệch nhau là trả về false.
*/
bool CMatrix::operator==(const CMatrix& m) const{
    if (iDong != m.iDong || iCot != m.iCot){
        return false; 
    }
    for(int i = 0; i < iDong; ++i) {
        for (int j = 0; j < iCot; ++j) {
            if (aPhanTu[i][j] != m.aPhanTu[i][j]){
                return false;
            }
        }
    }
    return true;
}
/*
Hàm: LayMaTranCon
Input: Vị trí dòng và cột cần loại bỏ
Output: Một ma trận mới có kích thước giảm đi 1 cấơ
*/
CMatrix CMatrix::LayMaTranCon(int dongBo, int cotBo) const{
    CMatrix kq(iDong - 1, iCot - 1);
    int r = 0;
    for (int i = 0; i < iDong; ++i){
        if (i == dongBo) continue;
        int c = 0;
        for (int j = 0; j < iCot; ++j){
            if (j == cotBo) continue;
            kq.aPhanTu[r][c] = aPhanTu[i][j];
            c++;
        }
        r++;
    }
    return kq;
}
/*
Output: Giá trị định thức
Hướng giải thuật: Kiểm tra ma trận vuông. Dùng đệ quy khai triển Laplace theo dong 0
*/
double CMatrix::TinhDeterminant() const{
    if (iDong != iCot){
        std::cout << "Loi ma tran tinh det phai vuong!\n";
        return 0;
    }
    if (iDong == 1) return aPhanTu[0][0];
    if (iDong == 2) return aPhanTu[0][0] * aPhanTu[1][1] - aPhanTu[0][1] * aPhanTu[1][0];
    double det = 0;
    int dau = 1;
    for (int j = 0; j < iCot; ++j){
        CMatrix maTranCon = LayMaTranCon(0, j);
        det += dau * aPhanTu[0][j] * maTranCon.TinhDeterminant();
        dau = -dau;
    }
    return det;
}
/*
Input: Luồng nhập ,  ma tran can luu
Output:
Hướng giải thuật: Xóa bộ nhớ cũ nhập số dòng và số cột mới, cấp phát lại rồi dùng 2 vòng lặp để nhập từng phần tử.
*/
istream& operator>>(istream& in, CMatrix& m){
    int d, c;
    cout << "Nhap so dong: "; in >> d;
    cout << "Nhap so cot: "; in >> c;
    if (d < 0) d = 0;
    if(c < 0) c = 0;
    for(int i = 0; i < m.iDong; ++i) delete[] m.aPhanTu[i];
    delete[] m.aPhanTu;
    m.iDong = d; m.iCot = c;
    m.aPhanTu = new double*[m.iDong];
    for (int i = 0; i < m.iDong; ++i) {
        m.aPhanTu[i] = new double[m.iCot];
        for (int j = 0; j < m.iCot; ++j) {
            cout << "  + Phan tu [" << i << "][" << j << "]: ";
            in >> m.aPhanTu[i][j];
        }
    }
    return in;
}
/*
Input: Luồng xuất , ma trận cần in
Output: in ma trận
Hướng giải thuật: Duyệt qua từng dòng và cột để in phần tử ra màn hình theo dạng bảng
*/
ostream& operator<<(ostream& out, const CMatrix& m){
    for (int i = 0; i < m.iDong; ++i){
        for (int j = 0; j < m.iCot; ++j){
            out << m.aPhanTu[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}