#include "timetable.h"

Timetable::Timetable() {

}

Timetable::Timetable(std::string pDate, std::string pInitialHour, std::string pFinalHour) {
    date = pDate;
    initialHour = pInitialHour;
    finalHour = pFinalHour;
}
void Timetable::setDate(std::string pDate) {
    date = pDate;
}

std::string Timetable::getDate() {
    return date;
}

void Timetable::setInitialHour(std::string pInitialHour) {
    initialHour = pInitialHour;
}

std::string Timetable::getInitialHour() {
    return initialHour;
}

void Timetable::setFinalHour(std::string pFinalHour) {
    finalHour = pFinalHour;
}

std::string Timetable::getFinalHour() {
    return finalHour;
}

Timetable::~Timetable() {

}