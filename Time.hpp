#ifndef TIME_HPP
#define TIME_HPP

#include <iostream>

class Time {
public:
    Time(int hours, int minutes, int seconds);
    
    void addSeconds(int seconds);
    void subtractSeconds(int seconds);
    void addMinutes(int minutes);
    void subtractMinutes(int minutes);
    void addHours(int hours);
    void subtractHours(int hours);
    
    void print() const;

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

private:
    int hours, minutes, seconds;

    void adjustTime();
};

#endif
