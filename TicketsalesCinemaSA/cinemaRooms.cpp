#include "cinemaRooms.h"

CinemaRooms::CinemaRooms(float pPrice, const int pMAX_ROWS, const int pMAX_COLUMNS) {
    price = pPrice;
    MAX_COLUMNS = pMAX_COLUMNS;
    MAX_ROWS = pMAX_ROWS;

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

void CinemaRooms::setPrice(float pPrice) {
    price = pPrice;
}

float CinemaRooms::getPrice() {
    return price;
}

int** CinemaRooms::getChair() {
    return chairs;
}

void CinemaRooms::printChairs() {
    const int columnWidth = 3;
    std::cout << " ";
    for (int j = 0; j < MAX_COLUMNS; j++) {
        std::cout << std::setw(columnWidth) << j + 1;
    }
    std::cout << std::endl;

    for (int i = 0; i < MAX_ROWS; i++) {
        std::cout << i + 1;
        for (int j = 0; j < MAX_COLUMNS; j++) {
            if (chairs[i][j] == 0) {
                setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            else if (chairs[i][j] == 1) {
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            else if (chairs[i][j] == 2) {
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            }
            std::cout << std::setw(columnWidth) << char(220);
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        std::cout << std::endl;
    }
}

bool CinemaRooms::isSeatAvailable(int row, int col) {
    if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLUMNS) {
        std::cout << "Fila o columna fuera de los limites." << std::endl;
        return false;
    }
    return chairs[row][col] == 0;
}

bool CinemaRooms::isSeatReserved(int row, int col) const {
    if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLUMNS) {
        std::cout << "Fila o columna fuera de los limites." << std::endl;
        return false;
    }
    return chairs[row][col] == 1;
}

void CinemaRooms::setReserved(int row, int col) {
    if (isSeatAvailable(row, col)) {
        chairs[row][col] = 1;
    }
    else {
        std::cout << "ERROR";
    }

}

void CinemaRooms::setPucharsed(int row, int col) {
    if (chairs[row][col] == 1) {
        chairs[row][col] = 2;
    }
    else {
        std::cout << "ERROR: La silla no ha sido reservada o ya esta comprada." << std::endl;
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



