#ifndef PHANSO_H
#define PHANSO_H
using namespace std;
#include <iostream>
class SoPhuc{
private:
    double iThuc;
    double iAo;
public:
    SoPhuc(double thuc = 0.0, double ao = 0.0);
    SoPhuc operator+(const SoPhuc& sp) const;
    SoPhuc operator-(const SoPhuc& sp) const;
    SoPhuc operator*(const SoPhuc& sp) const;
    SoPhuc operator/(const SoPhuc& sp) const;
    bool operator==(const SoPhuc& sp) const;
    bool operator!=(const SoPhuc& sp) const;
    friend std::istream& operator>>(std::istream& in, SoPhuc& sp);
    friend std::ostream& operator<<(std::ostream& out, const SoPhuc& sp);
};
#endif