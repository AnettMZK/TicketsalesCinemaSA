#pragma once
#ifndef HOUR_H
#define HOUR_H

#include <iostream>

class Hour {
private:
    std::string date;
    std::string initialHour;
    std::string finalHour;

public:

    Hour();
    Hour(std::string pDate, std::string pInitialHour, std::string pFinalHour);

    void setDate(std::string pDate);
    std::string getDate();
    void setInitialHour(std::string pInitialHour);
    std::string getInitialHour();
    void setFinalHour(std::string pFinalHour);
    std::string getFinalHour();

    ~Hour();

};

#endif

