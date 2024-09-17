#pragma once
#ifndef CinemaRooms_H
#define CinemaRooms_H

#include <iostream>
#include <windows.h>
#include <iomanip>
class CinemaRooms
{
private:
    int MAX_ROWS;
    int MAX_COLUMNS;
    float price;
    int** chairs;

    void setConsoleColor(WORD color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

public:
    CinemaRooms(float pPrice, const int pMAX_ROWS, const int pMAX_COLUMNS);
    ~CinemaRooms();

    void setPrice(float pPrice);
    float getPrice();
    int** getChair();
    void printChairs();
    bool isSeatAvailable(int row, int col);
    bool isSeatReserved(int row, int col) const;
    void setReserved(int row, int col);
    void setPucharsed(int row, int col);
    int getTotalOfChairs() const;
    int getActualChairs();
};

#endif