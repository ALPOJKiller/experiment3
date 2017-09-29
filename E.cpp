#include <iostream>

using namespace std;

/**
 * 判断是否是闰年
 * @param year 年份
 * @return 是闰年返回true，否则返回false
 */
bool is_leap_year(unsigned year) {
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    else
        return false;
}

/**
 * 将年份转换为自1年1月1日以来的日数
 * @param year 年份
 * @return 转换结果，即1年1月1日～ @arg year 年1月1日的日数
 */
unsigned year_to_day(unsigned year) {
    unsigned ret = 0;
    //循环累加，如果是闰年就再多加1
    //记得true会被转换为1，false转换为0
    for (unsigned i = 1; i < year; ++i) {
        ret += 365 + (int) is_leap_year(i);
    }
    return ret;
}

/**
 * 将月份转换为
 * @param month 月份
 * @param is_leap 这一年是否是闰年
 * @return 转换结果，即这一年1月1日～ 这一年 @arg month 月1日的日数
 */
unsigned month_to_day(unsigned month, bool is_leap) {
    unsigned ret = 0;
    int day_in_month[] = {0, 31, is_leap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (unsigned i = 0; i < month; ++i) {
        ret += day_in_month[i];
    }
    return ret;
}

int main() {
    unsigned y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1;
    cin >> y2 >> m2 >> d2;
    // 将每个日期都转换成相对于1年1月1日的日数
    unsigned dd1 = year_to_day(y1) + month_to_day(m1, is_leap_year(y1)) + d1;
    unsigned dd2 = year_to_day(y2) + month_to_day(m2, is_leap_year(y2)) + d2;
    cout << dd2 - dd1;
    return 0;
}
