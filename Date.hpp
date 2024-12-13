#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <string>

class Date {
public:
    Date(int year, int month, int day);
    void addDays(int days);
    void subtractDays(int days);
    void addMonths(int months);
    void subtractMonths(int months);
    void addYears(int years);
    void subtractYears(int years);
    
    void print() const;

    int getYear() const;
    int getMonth() const;
    int getDay() const;

private:
    int year, month, day;

    bool isLeapYear(int year) const;
    int daysInMonth(int month, int year) const;
    void adjustDate();
};

#endif
