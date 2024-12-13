#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "Date.hpp"
#include "Time.hpp"
#include <string>

class DateTime {
public:
    DateTime(int year, int month, int day, int hours, int minutes, int seconds);
    
    void addDays(int days);
    void subtractDays(int days);
    void addMonths(int months);
    void subtractMonths(int months);
    void addYears(int years);
    void subtractYears(int years);
    
    void addSeconds(int seconds);
    void subtractSeconds(int seconds);
    void addMinutes(int minutes);
    void subtractMinutes(int minutes);
    void addHours(int hours);
    void subtractHours(int hours);

    void print() const;
    
    std::string format(const std::string& formatString) const;

    int differenceInDays(const DateTime& other) const;
    int differenceInHours(const DateTime& other) const;
    int differenceInMinutes(const DateTime& other) const;
    int differenceInSeconds(const DateTime& other) const;

private:
    Date date;
    Time time;
};

#endif
