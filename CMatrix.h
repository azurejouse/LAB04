#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include "CVector.h"
class CMatrix{
private:
    int iDong;
    int iCot;
    double** aPhanTu;
public:
    CMatrix(int dong = 0, int cot = 0);
    CMatrix(const CMatrix& m);
    ~CMatrix();
    CMatrix& operator=(const CMatrix& m);
    CMatrix operator+(const CMatrix& m) const;
    CMatrix operator-(const CMatrix& m) const;
    CMatrix operator*(const CMatrix& m) const;
    CVector operator*(const CVector& v) const;
    bool operator==(const CMatrix& m) const;
    double TinhDeterminant() const;
    CMatrix LayMaTranCon(int dongBo, int cotBo) const;
    friend std::istream& operator>>(std::istream& in, CMatrix& m);
    friend std::ostream& operator<<(std::ostream& out, const CMatrix& m);
};
#endif