#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool is_leap_year(unsigned year) {
    if(((year%4==0) && (year%100!=0)) || (year%400==0))
        return true;
    else
        return false;
}
unsigned year_to_day(unsigned year) {
    unsigned ret = 0;
    for(unsigned i=1;i<year;++i) {
        ret += 365 + (int)is_leap_year(i);
    }   
    return ret;
}
unsigned month_to_day(unsigned month,bool is_leap) {
    unsigned ret = 0;
    int day_in_month[] = {0,31,is_leap?29:28,31,30,31,30,31,31,30,31,30,31};
    for(unsigned i=0;i<month;++i) {
        ret += day_in_month[i];
    }
    return ret;
}
int main() {
    unsigned y1,m1,d1,y2,m2,d2;
    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;
    unsigned dd1 = year_to_day(y1) + month_to_day(m1,is_leap_year(y1)) + d1;
    unsigned dd2 = year_to_day(y2) + month_to_day(m2,is_leap_year(y2)) + d2;
    cout << dd2 - dd1;
    //cout << y1 % 4 << is_leap_year(y1);
    return 0;
}
