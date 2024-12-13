#include "Time.hpp"
#include <iostream>
#include <iomanip>

Time::Time(int hours, int minutes, int seconds)
    : hours(hours), minutes(minutes), seconds(seconds) {
    adjustTime();
}

void Time::adjustTime() {
    if (seconds < 0) {
        seconds += 60;
        minutes--;
    }
    if (minutes < 0) {
        minutes += 60;
        hours--;
    }
    if (hours < 0) {
        hours += 24;
    }
}

void Time::addSeconds(int seconds) {
    this->seconds += seconds;
    while (this->seconds >= 60) {
        this->seconds -= 60;
        minutes++;
    }
    adjustTime();
}

void Time::subtractSeconds(int seconds) {
    this->seconds -= seconds;
    while (this->seconds < 0) {
        this->seconds += 60;
        minutes--;
    }
    adjustTime();
}

void Time::addMinutes(int minutes) {
    this->minutes += minutes;
    while (this->minutes >= 60) {
        this->minutes -= 60;
        hours++;
    }
    adjustTime();
}

void Time::subtractMinutes(int minutes) {
    this->minutes -= minutes;
    while (this->minutes < 0) {
        this->minutes += 60;
        hours--;
    }
    adjustTime();
}

void Time::addHours(int hours) {
    this->hours += hours;
    while (this->hours >= 24) {
        this->hours -= 24;
    }
    adjustTime();
}

void Time::subtractHours(int hours) {
    this->hours -= hours;
    while (this->hours < 0) {
        this->hours += 24;
    }
    adjustTime();
}

void Time::print() const {
    std::cout << std::setw(2) << std::setfill('0') << hours << ":"
              << std::setw(2) << std::setfill('0') << minutes << ":"
              << std::setw(2) << std::setfill('0') << seconds << std::endl;
}

int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }
