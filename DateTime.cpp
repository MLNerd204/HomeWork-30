#include "DateTime.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cmath>

DateTime::DateTime(int year, int month, int day, int hours, int minutes, int seconds)
    : date(year, month, day), time(hours, minutes, seconds) {}

void DateTime::addDays(int days) {
    date.addDays(days);
}

void DateTime::subtractDays(int days) {
    date.subtractDays(days);
}

void DateTime::addMonths(int months) {
    date.addMonths(months);
}

void DateTime::subtractMonths(int months) {
    date.subtractMonths(months);
}

void DateTime::addYears(int years) {
    date.addYears(years);
}

void DateTime::subtractYears(int years) {
    date.subtractYears(years);
}

void DateTime::addSeconds(int seconds) {
    time.addSeconds(seconds);
}

void DateTime::subtractSeconds(int seconds) {
    time.subtractSeconds(seconds);
}

void DateTime::addMinutes(int minutes) {
    time.addMinutes(minutes);
}

void DateTime::subtractMinutes(int minutes) {
    time.subtractMinutes(minutes);
}

void DateTime::addHours(int hours) {
    time.addHours(hours);
}

void DateTime::subtractHours(int hours) {
    time.subtractHours(hours);
}

void DateTime::print() const {
    date.print();
    time.print();
}

std::string DateTime::format(const std::string& formatString) const {
    std::stringstream formatted;
    for (size_t i = 0; i < formatString.length(); ++i) {
        if (formatString[i] == 'Y' && formatString[i + 1] == 'Y') {
            formatted << std::setw(4) << std::setfill('0') << date.getYear();
            i++;
        } else if (formatString[i] == 'M' && formatString[i + 1] == 'M') {
            formatted << std::setw(2) << std::setfill('0') << date.getMonth();
            i++;
        } else if (formatString[i] == 'D' && formatString[i + 1] == 'D') {
            formatted << std::setw(2) << std::setfill('0') << date.getDay();
            i++;
        } else if (formatString[i] == 'H' && formatString[i + 1] == 'H') {
            formatted << std::setw(2) << std::setfill('0') << time.getHours();
            i++;
        } else if (formatString[i] == 'M' && formatString[i + 1] == 'M') {
            formatted << std::setw(2) << std::setfill('0') << time.getMinutes();
            i++;
        } else if (formatString[i] == 'S' && formatString[i + 1] == 'S') {
            formatted << std::setw(2) << std::setfill('0') << time.getSeconds();
            i++;
        } else {
            formatted << formatString[i];
        }
    }
    return formatted.str();
}

int DateTime::differenceInDays(const DateTime& other) const {
    std::tm tm1 = {0};
    tm1.tm_year = date.getYear() - 1900;
    tm1.tm_mon = date.getMonth() - 1;
    tm1.tm_mday = date.getDay();
    
    std::tm tm2 = {0};
    tm2.tm_year = other.date.getYear() - 1900;
    tm2.tm_mon = other.date.getMonth() - 1;
    tm2.tm_mday = other.date.getDay();

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);
    
    return std::difftime(time1, time2) / (60 * 60 * 24);
}

int DateTime::differenceInHours(const DateTime& other) const {
    return differenceInDays(other) * 24 + (time.getHours() - other.time.getHours());
}

int DateTime::differenceInMinutes(const DateTime& other) const {
    return differenceInHours(other) * 60 + (time.getMinutes() - other.time.getMinutes());
}

int DateTime::differenceInSeconds(const DateTime& other) const {
    return differenceInMinutes(other) * 60 + (time.getSeconds() - other.time.getSeconds());
}
