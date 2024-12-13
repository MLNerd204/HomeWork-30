#include "Date.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
    adjustDate();
}

bool Date::isLeapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int Date::daysInMonth(int month, int year) const {
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

void Date::adjustDate() {
    if (month < 1) {
        month = 1;
    } else if (month > 12) {
        month = 12;
    }
    int daysInCurrentMonth = daysInMonth(month, year);
    if (day < 1) {
        day = 1;
    } else if (day > daysInCurrentMonth) {
        day = daysInCurrentMonth;
    }
}

void Date::addDays(int days) {
    day += days;
    while (day > daysInMonth(month, year)) {
        day -= daysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    adjustDate();
}

void Date::subtractDays(int days) {
    day -= days;
    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += daysInMonth(month, year);
    }
    adjustDate();
}

void Date::addMonths(int months) {
    month += months;
    while (month > 12) {
        month -= 12;
        year++;
    }
    adjustDate();
}

void Date::subtractMonths(int months) {
    month -= months;
    while (month < 1) {
        month += 12;
        year--;
    }
    adjustDate();
}

void Date::addYears(int years) {
    year += years;
    adjustDate();
}

void Date::subtractYears(int years) {
    year -= years;
    adjustDate();
}

void Date::print() const {
    std::cout << year << "-" << std::setw(2) << std::setfill('0') << month << "-" << std::setw(2) << std::setfill('0') << day << std::endl;
}

int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }

