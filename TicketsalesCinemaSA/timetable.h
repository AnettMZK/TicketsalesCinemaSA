#pragma once
#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <iostream>

class Timetable {
private:
    std::string date;
    std::string initialHour;
    std::string finalHour;

public:

    Timetable();
    Timetable(std::string pDate, std::string pInitialHour, std::string pFinalHour);

    void setDate(std::string pDate);
    std::string getDate();
    void setInitialHour(std::string pInitialHour);
    std::string getInitialHour();
    void setFinalHour(std::string pFinalHour);
    std::string getFinalHour();

    ~Timetable();

};

#endif

