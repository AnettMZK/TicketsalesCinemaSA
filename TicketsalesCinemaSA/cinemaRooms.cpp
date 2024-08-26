#include "cinemaRooms.h"



CinemaRooms::CinemaRooms(float pPrice, const int pMAX_ROWS, const int pMAX_COLUMNS) {
    price = pPrice;
    MAX_COLUMNS = pMAX_COLUMNS;
    MAX_ROWS = pMAX_ROWS;

    chairs = new int* [MAX_ROWS];
    chairs = new int* [MAX_ROWS];
    for (int i = 0; i < MAX_ROWS; i++) {
        chairs[i] = new int[MAX_COLUMNS];
        for (int j = 0; j < MAX_COLUMNS; j++) {
            chairs[i][j] = 0;
        }
    }
}

CinemaRooms::~CinemaRooms() {
    for (int i = 0; i < MAX_ROWS; i++) {
        delete[]chairs[i];
    }
    delete[]chairs;
}

void CinemaRooms::setPrice(int pPrice) {
    price = pPrice;
}

int CinemaRooms::getPrice() {
    return price;
}

int** CinemaRooms::getChair() {
    return chairs;
}

void CinemaRooms::printChairs() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            std::cout << chairs[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void CinemaRooms::setReserved(int row, int col) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            chairs[row][col] = 1;
        }
        std::cout << std::endl;
    }

}

int CinemaRooms::getTotalOfChairs() const {
    return MAX_ROWS * MAX_COLUMNS;
}

int CinemaRooms::getActualChairs() {
    int availableChairs = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (chairs[i][j] == 0) {
                availableChairs++;
            }
        }
    }
    return availableChairs;
}



