#pragma once
#ifndef CinemaRooms_H
#define CinemaRooms_H

#include <iostream>
#include <windows.h>

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

    void setPrice(int pPrice);
    int getPrice();
    int** getChair();
    void printChairs();
    void setReserved(int row, int col);
    int getTotalOfChairs() const;
    int getActualChairs();
};

#endif