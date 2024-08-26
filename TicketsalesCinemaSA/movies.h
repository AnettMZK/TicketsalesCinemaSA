#pragma once
#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>

class Movies
{
private:
	std::string name;
	int year;
	std::string duration;
	std::string country;
	std::string review;

public:
	Movies() : year(0) {};
	Movies(std::string pName, int pYear, std::string pDuration, std::string pCountry, std::string pReview);

	void setName(std::string pName);
	std::string getName();

	void setYear(int pYear);
	int getYear();

	void setDuration(std::string pDuration);
	std::string getDuration();

	void setCountry(std::string pCountry);
	std::string getCountry();

	void setReview(std::string pReview);
	std::string getReview();

	~Movies();
};

#endif

