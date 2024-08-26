#include "hour.h"

Hour::Hour() {

}

Hour::Hour(std::string pDate, std::string pInitialHour, std::string pFinalHour) {
    date = pDate;
    initialHour = pInitialHour;
    finalHour = pFinalHour;
}
void Hour::setDate(std::string pDate) {
    date = pDate;
}

std::string Hour::getDate() {
    return date;
}

void Hour::setInitialHour(std::string pInitialHour) {
    initialHour = pInitialHour;
}

std::string Hour::getInitialHour() {
    return initialHour;
}

void Hour::setFinalHour(std::string pFinalHour) {
    finalHour = pFinalHour;
}

std::string Hour::getFinalHour() {
    return finalHour;
}

Hour::~Hour() {

}