#ifndef CTIME_H
#define CTIME_H
#include <iostream>
using namespace std;
class CTime{
private:
    int iGio;
    int iPhut;
    int iGiay;
    void ChuanHoa();
public:
    CTime(int gio = 0, int phut = 0, int giay = 0);
    CTime operator+(int giay_them) const;
    CTime operator-(int giay_bot) const;
    CTime& operator++();
    CTime& operator--();
    CTime operator++(int);
    CTime operator--(int);
    friend istream& operator>>(istream& in, CTime& t);
    friend ostream& operator<<(ostream& out, const CTime& t);
};
#endif