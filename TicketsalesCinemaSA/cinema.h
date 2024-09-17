#pragma once
#ifndef Cinema_H
#define Cinema_H

#include <iostream>
#include <string>
#include <windows.h>
#include "movies.h"
#include "timetable.h"
#include "cinemaRooms.h"
#include "client.h"

class Cinema
{
private:
    static const int MAX_SIZE = 100;
    Movies movie[MAX_SIZE];
    Timetable timetable[MAX_SIZE];
    CinemaRooms* rooms[MAX_SIZE];
    Client client[MAX_SIZE];
    int movieSize;
    int roomSize;
    int roomCount;
    int movieAssignments[MAX_SIZE];

    void setConsoleColor(WORD color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

public:
    Cinema();
    void setRoomSize(int mSize);
    void setMovieSize(int pSize);
    int getMovieSize();
    int getRoomSize();
    void clearScreen();

    void aboutCinema();

    void addMovies();

    void addRoom(float pPrice, int pMAX_ROWS, int pMAX_COLUMNS);

    void addHour();

    void printHourInformation();

    void distributeRooms();

    void reservation();

    void purchase();

    void addRoomInformation();

    void printRoomInformation();

    void printMoviesInformation();

    void menu();
    ~Cinema();
};

#endif

