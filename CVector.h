#ifndef CVECTOR_H
#define CVECTOR_H
#include <iostream>
class CVector{
private:
    int iSoChieu;
    double* aThanhPhan;
public:
    CVector(int soChieu = 0);
    CVector(const CVector& v);
    ~CVector();
    CVector& operator=(const CVector& v);
    CVector operator+(const CVector& v) const;
    CVector operator-(const CVector& v) const;
    double operator*(const CVector& v) const;
    CVector operator*(double k) const;
    double TinhDoDai() const;
    friend std::istream& operator>>(std::istream& in, CVector& v);
    friend std::ostream& operator<<(std::ostream& out, const CVector& v);
};
#endif