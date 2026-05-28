#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>
class DaThuc{
private:
    int iBac;          
    double* aHeSo;     
    void ChuanHoa();
public:
    DaThuc(int bac = 0);
    DaThuc(const DaThuc& dt);
    ~DaThuc();
    DaThuc& operator=(const DaThuc& dt);
    DaThuc operator+(const DaThuc& dt) const;
    DaThuc operator-(const DaThuc& dt) const;
    DaThuc operator*(const DaThuc& dt) const;
    double TinhGiaTri(double x) const;
    friend std::istream& operator>>(std::istream& in, DaThuc& dt);
    friend std::ostream& operator<<(std::ostream& out, const DaThuc& dt);
};
#endif