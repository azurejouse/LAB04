#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
using namespace std;
class PhanSo {
private:
    int iTu;
    int iMau; 
    int TimUSCLN(int a, int b) const;
public:
    PhanSo(int tu = 0, int mau = 1);
    void RutGon();
    PhanSo operator+(const PhanSo& ps) const;
    PhanSo operator-(const PhanSo& ps) const;
    PhanSo operator*(const PhanSo& ps) const;
    PhanSo operator/(const PhanSo& ps) const;
    bool operator==(const PhanSo& ps) const;
    bool operator>(const PhanSo& ps) const;
    bool operator<(const PhanSo& ps) const;
    friend std::istream& operator>>(std::istream& in, PhanSo& ps);
    friend std::ostream& operator<<(std::ostream& out, const PhanSo& ps);
};

#endif