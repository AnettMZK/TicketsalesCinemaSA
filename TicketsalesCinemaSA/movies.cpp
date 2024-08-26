#include "movies.h"

Movies::Movies(std::string pName, int pYear, std::string pDuration, std::string pCountry, std::string pReview) {
    name = pName;
    year = pYear;
    duration = pDuration;
    country = pCountry;
    review = pReview;
}

void Movies::setName(std::string pName) {
    name = pName;
}

std::string Movies::getName() {
    return name;
}

void Movies::setYear(int pYear) {
    year = pYear;
}

int Movies::getYear() {
    return year;
}

void Movies::setDuration(std::string pDuration) {
    duration = pDuration;
}

std::string Movies::getDuration() {
    return duration;
}

void Movies::setCountry(std::string pCountry) {
    country = pCountry;
}

std::string Movies::getCountry() {
    return country;
}

void Movies::setReview(std::string pReview) {
    review = pReview;
}

std::string Movies::getReview() {
    return review;
}

Movies::~Movies() {

}
