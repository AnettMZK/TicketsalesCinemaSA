#include "cinema.h"

Cinema::Cinema() : movieSize(0), roomCount(0), roomSize(0) {
    for (int i = 0; i < MAX_SIZE; i++) {
        rooms[i] = nullptr;
        movieAssignments[i] = 0;
    }
}

void Cinema::setRoomSize(int mSize)
{
    roomSize = mSize;
}

void Cinema::setMovieSize(int pSize) {
    movieSize = pSize;
}

int Cinema::getMovieSize() {
    return movieSize;
}

int Cinema::getRoomSize()
{
    return roomSize;
}

void Cinema::clearScreen() {
    system("cls");
}

void Cinema::aboutCinema() {
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
    std::cout << "\n     QUIENES SOMOS     \n";
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    std::cout << "Con mas de 20 anios de experiencia en la industria del entretenimiento,Nueva Cinema S.A. \n";
    std::cout << "se ha consolidado como un referente en la comunidad costarricense, proyectando peliculas\n";
    std::cout << "de todos los generos y para todas las edades. Contamos con un equipo apasionado por el  \n";
    std::cout << "cine y nos esforzamos por ofrecer un servicio excepcional, asegurando que cada cliente  \n";
    std::cout << "disfrute de una experiencia inolvidable.\n";

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
    std::cout << "\n     DONDE ENCONTRARNOS     \n";
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    std::cout << "Direccion: Centro Comercial Montegeneral, San Jose, San Isidro de El General\n";
    std::cout << "Telefono: +506 4568 7890\n";
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
    std::cout << "Encuentranos en nuestras redes sociales como @Nueva.CinemaS.A\n";
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << "\n     Anett Rodriguez Vega     \n";
    std::cout << "       community manager";
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << std::endl;
}

void Cinema::addMovies() {
    std::string name, duration, country, review;
    int year;

    std::cout << "\nDigite cuantas peliculas desea agregar: ";
    std::cin >> movieSize;
    this->setMovieSize(movieSize);
    std::cout << std::endl;

    for (int i = 0; i < getMovieSize(); i++) {

        std::cout << "Nombre de la pelicula: ";
        std::getline(std::cin >> std::ws, name);
        this->movie[i].setName(name);

        std::cout << "Anio de creacion de la pelicula: ";
        std::cin >> year;
        this->movie[i].setYear(year);

        std::cin.ignore();

        std::cout << "Digite la duracion en minutos de la pelicula: ";
        std::cin >> duration;
        this->movie[i].setDuration(duration);

        std::cout << "Pais de origen la pelicula: ";
        std::getline(std::cin >> std::ws, country);
        this->movie[i].setCountry(country);

        std::cout << "Resenia de la pelicula: ";
        std::getline(std::cin >> std::ws, review);
        this->movie[i].setReview(review);

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << "\nPELICULA " << i + 1 << " REGISTRADA CORRECTAMENTE" << std::endl;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        std::cout << std::endl;
    }
}

void Cinema::printMoviesInformation() {
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << "\n---- PELICULAS REGISTRADAS ---- " << std::endl;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < getMovieSize(); i++) {

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << "\nPELICULA " << i + 1 << std::endl;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        std::cout << "Nombre: " << this->movie[i].getName() << std::endl;
        std::cout << "Anio: " << this->movie[i].getYear() << std::endl;
        std::cout << "Duracion: " << this->movie[i].getDuration() << std::endl;
        std::cout << "Pais de origen: " << this->movie[i].getCountry() << std::endl;
        std::cout << "Resenia: " << this->movie[i].getReview() << std::endl;
    }

}

void Cinema::addRoom(float pPrice, int pMAX_ROWS, int pMAX_COLUMNS) {
    if (roomCount < MAX_SIZE) {
        rooms[roomCount] = new CinemaRooms(pPrice, pMAX_ROWS, pMAX_COLUMNS);
        roomCount++;
    }
    else {
        std::cout << "No se pueden agregar mas salas." << std::endl;
    }
}

void Cinema::addRoomInformation() {
    int maxRows, maxColumns;
    float price;

    std::cout << "\nDigite cuantas salas desea agregar: ";
    std::cin >> roomSize;
    this->setRoomSize(roomSize);

    for (int i = 0; i < getRoomSize(); i++) {
        std::cout << std::endl;
        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << "REGISTRAR SALA " << i + 1 << std::endl;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cout << "Digite el precio: ";
        std::cin >> price;
        std::cout << "Digite el numero de filas: ";
        std::cin >> maxRows;
        std::cout << "Digite el numero de columnas: ";
        std::cin >> maxColumns;

        addRoom(price, maxRows, maxColumns);

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << "\nSALA " << i + 1 << " REGISTRADA CORRECTAMENTE" << std::endl;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    }
}

void Cinema::printRoomInformation() {
    int row = 0, col = 0;
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << "\n---- SALAS REGISTRADAS ---- " << std::endl;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    for (int i = 0; i < roomCount; i++) {
        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << "Sala " << i + 1 << std::endl;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cout << "Precio: " << rooms[i]->getPrice() << std::endl;
        std::cout << "Numero de butacas: " << rooms[i]->getTotalOfChairs() << std::endl;
    }
    std::cout << std::endl;
}

void Cinema::addHour() {
    std::string date, initialHour, finalHour;
    std::cout << std::endl;
    for (int i = 0; i < getMovieSize(); i++) {
        std::cout << "Agregue el horario para la pelicula: ";
        setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cout << this->movie[i].getName() << std::endl;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


        std::cout << "Agregue el dia que sera emitida: ";
        std::getline(std::cin >> std::ws, date);
        this->timetable[i].setDate(date);

        std::cout << "Agregue la hora inicial: ";
        std::getline(std::cin >> std::ws, initialHour);
        this->timetable[i].setInitialHour(initialHour);

        std::cout << "Agregue la hora de finalizacion: ";
        std::getline(std::cin >> std::ws, finalHour);
        this->timetable[i].setFinalHour(finalHour);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Cinema::printHourInformation() {
    for (int i = 0; i < getMovieSize(); i++) {

        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << "Pelicula: " << this->movie[i].getName() << std::endl;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        std::cout << "Dia: " << this->timetable[i].getDate() << std::endl;
        std::cout << "Hora de comienzo: " << this->timetable[i].getInitialHour() << std::endl;
        std::cout << "Hora de finalizacion: " << this->timetable[i].getFinalHour() << std::endl;
    }

}

void Cinema::distributeRooms() {
    std::cout << std::endl;

    if (roomCount > 0 && getMovieSize() > 0) {
        for (int i = 0; i < roomCount; i++) {
            int randomMovieIndex = rand() % getMovieSize();
            movieAssignments[i] = randomMovieIndex;
            std::cout << "La pelicula ";
            setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
            std::cout << movie[randomMovieIndex].getName();
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << " ha sido asignada a la ";
            setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
            std::cout << "Sala " << i + 1 << std::endl;
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

            std::cout << "El dia: " << timetable[randomMovieIndex].getDate() << std::endl;
            std::cout << "Comienza: " << timetable[randomMovieIndex].getInitialHour() << std::endl;
            std::cout << "Finaliza: " << timetable[randomMovieIndex].getFinalHour() << std::endl;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Debe haber al menos una pelicula y una sala registrada para poder distribuir." << std::endl;
    }
}

void Cinema::reservation() {
    int roomNumber;
    int reserve, row = 0, col = 0;
    int spaceForText = 12;

    for (int i = 0; i < roomCount; i++) {
        int assignedMovieIndex = movieAssignments[i];
        std::cout << "La pelicula ";
        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
        std::cout << movie[assignedMovieIndex].getName() << " en la sala " << i + 1 << std::endl;
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        std::cout << "El dia: " << timetable[assignedMovieIndex].getDate() << std::endl;
        std::cout << "Comienza: " << timetable[assignedMovieIndex].getInitialHour() << std::endl;
        std::cout << "Finaliza: " << timetable[assignedMovieIndex].getFinalHour() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Digite la sala que desea reservar: ";
    std::cin >> roomNumber;
    int assignedMovieIndex = movieAssignments[roomNumber - 1];

    std::cout << std::endl;

    std::cout << "\n------------------------------------\n";
    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
    std::cout << "     INFORMACION DE LA SALA     " << std::endl;
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << std::endl;

    setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << char(220) << " ";
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "DISPONIBLE";
    std::cout << std::string(spaceForText - 10, ' ');

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << char(220) << " ";
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "RESERVADO";
    std::cout << std::string(spaceForText - 8, ' ');

    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    std::cout << char(220) << " ";
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "COMPRADO" << std::endl;

    std::cout << std::endl;

    rooms[roomNumber - 1]->printChairs();
    std::cout << std::endl;
    std::cout << "PELICULA: " << movie[assignedMovieIndex].getName() << std::endl;
    std::cout << "BUTACAS DISPONIBLES: " << rooms[roomNumber - 1]->getActualChairs() << std::endl;
    std::cout << "PRECIO DE LA SALA: " << rooms[roomNumber - 1]->getPrice() << std::endl;

    std::cout << "\n------------------------------------\n";
    std::cout << "1. Desea reservar esta funcion" << std::endl;
    std::cout << "2. Desea regresar" << std::endl;
    std::cout << "Digite una opcion: ";
    std::cin >> reserve;
    std::cout << std::endl;

    if (reserve == 1) {
        std::cout << "Digite la fila que desea: ";
        std::cin >> row;
        std::cout << "Digite la columna que desea: ";
        std::cin >> col;
        std::cout << std::endl;

        if (rooms[roomNumber - 1]->isSeatAvailable(row - 1, col - 1)) {
            rooms[roomNumber - 1]->setReserved(row - 1, col - 1);
            rooms[roomNumber - 1]->printChairs();
            this->client[roomNumber - 1].setTicket();
            this->client[roomNumber - 1].setReservedChair(row, col);
            std::cout << "POSICION RESERVADA" << std::endl;
            std::cout << "Su ticket es: " << this->client[roomNumber - 1].getTicket() << std::endl;
        }
        else {
            std::cout << "La silla seleccionada ya está reservada. Por favor, elija otra." << std::endl;
            reservation();
        }
    }
    else if (reserve == 2) {
        return;
    }
    else {
        std::cout << "Opcion digitada invalida" << std::endl;
        reservation();
    }
    setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}



void Cinema::purchase() {
    int row = 0, col = 0, id = 0, creditCard = 0;
    bool hasActiveReservation = false;

    for (int i = 0; i < roomCount; i++) {
        int assignedMovieIndex = movieAssignments[i];
        if (this->client[i].getTicket() != 0) {
            hasActiveReservation = true;

            std::cout << "Digite su numero de cedula: ";
            std::cin >> id;
            this->client[i].setId(id);

            std::cout << "Digite su numero de tarjeta: ";
            std::cin >> creditCard;
            this->client[i].setCreditCard(creditCard);

            int reservedRow = this->client[i].getReservedRow();
            int reservedCol = this->client[i].getReservedCol();

            if (rooms[i]->isSeatReserved(reservedRow - 1, reservedCol - 1)) {
                rooms[i]->setPucharsed(reservedRow - 1, reservedCol - 1);

                std::cout << "Compra completada. El asiento [" << reservedRow << ", " << reservedCol << "] ha sido pagado." << std::endl;
                rooms[i]->printChairs();
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else {
                std::cout << "El asiento no esta reservado o ya ha sido comprado." << std::endl;
                return;
            }
        }
    }

    if (hasActiveReservation == false) {
        std::cout << "No tiene ninguna reserva activa para esta pelicula." << std::endl;
    }
}




void Cinema::menu() {
    int option = 0;
    int secondOption = 0;
    int movieMaintenance = 0;
    int roomConfirmation = 0;
    int hourConfirmation = 0;

    do {
        std::cout << "------------------------------------\n";
        setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "     BIENVENIDO A NUEVA CINEMA SA   \n";
        setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        std::cout << "     [1] Archivo.          \n";
        std::cout << "     [2] Mantenimiento.    \n";
        std::cout << "     [3] Reserva.          \n";
        std::cout << "     [4] Venta.            \n";
        std::cout << "------------------------------------\n";
        std::cout << "Digite una opcion: ";
        std::cin >> option;
        std::cout << std::endl;

        clearScreen();

        switch (option) {
        case 1:
            std::cout << "----------------------\n";
            setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            std::cout << "        Archivo       \n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << "    [1] Acerca de.    \n";
            std::cout << "    [2] Salir.        \n";
            std::cout << "----------------------\n";
            std::cout << " Digite una opcion: ";
            std::cin >> secondOption;

            clearScreen();

            if (secondOption == 1) {
                aboutCinema();
            }
            else if (secondOption == 2) {
                std::cout << "Saliendo del programa...\n";
                exit(0);
            }
            else {
                std::cout << "FORMATO DIGITADO INVALIDO" << std::endl;
            }

            break;

        case 2:
            std::cout << "-------------------------\n";
            setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            std::cout << "        Mantenimiento    \n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << "    [1] Peliculas.       \n";
            std::cout << "    [2] Salas.           \n";
            std::cout << "    [3] Horarios.        \n";
            std::cout << "    [4] Distribuir Salas.\n";
            std::cout << "-------------------------\n";
            std::cout << " Digite una opcion: ";
            std::cin >> secondOption;
            std::cout << std::endl;

            clearScreen();

            if (secondOption == 1) {
                std::cout << "--------------------------------------------\n";
                setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                std::cout << "    1. Si desea ingresar peliculas.           " << std::endl;
                std::cout << "    2. Si desea ver las peliculas registradas." << std::endl;
                std::cout << "    3. Si desea regresar.                     " << std::endl;
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << "--------------------------------------------\n";
                std::cout << "Digite una opcion: ";
                std::cin >> movieMaintenance;

                if (movieMaintenance == 1) {
                    addMovies();
                    printMoviesInformation();
                }
                else if (movieMaintenance == 2) {
                    printMoviesInformation();
                }
                else if (movieMaintenance == 3) {
                    clearScreen();
                    menu();
                }
                else {
                    std::cout << "Valor fuera de rango";
                    clearScreen();
                    menu();
                }
            }
            else if (secondOption == 2) {
                std::cout << "--------------------------------------------\n";
                setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                std::cout << "    1. Si desea ingresar salas.           " << std::endl;
                std::cout << "    2. Si desea ver las salas registradas." << std::endl;
                std::cout << "    3. Si desea regresar.                 " << std::endl;
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << "--------------------------------------------\n";
                std::cout << "Digite una opcion: ";
                std::cin >> roomConfirmation;

                if (roomConfirmation == 1) {
                    addRoomInformation();
                    printRoomInformation();
                }
                else if (roomConfirmation == 2) {
                    printRoomInformation();
                }
                else if (roomConfirmation == 3) {
                    clearScreen();
                    menu();
                }
                else {
                    std::cout << "Valor fuera de rango";
                    clearScreen();
                    menu();
                }
            }
            else if (secondOption == 3) {
                std::cout << "--------------------------------------------\n";
                setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                std::cout << "    1. Si desea ingresar horarios.           " << std::endl;
                std::cout << "    2. Si desea ver los horarios registrados." << std::endl;
                std::cout << "    3. Si desea regresar.                 " << std::endl;
                setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << "--------------------------------------------\n";
                std::cout << "Digite una opcion: ";
                std::cin >> roomConfirmation;

                if (roomConfirmation == 1) {
                    addHour();
                    printHourInformation();
                }
                else if (roomConfirmation == 2) {
                    printHourInformation();
                }
                else if (roomConfirmation == 3) {
                    clearScreen();
                    menu();
                }
                else {
                    std::cout << "Valor fuera de rango";
                    clearScreen();
                    menu();
                }
            }
            else if (secondOption == 4) {
                distributeRooms();
            }
            else {
                std::cout << "FORMATO DIGITADO INVALIDO" << std::endl;
            }
            break;

        case 3:
            std::cout << "----------------------\n";
            setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            std::cout << "       Reserva        \n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << "----------------------\n";

            reservation();

            break;

        case 4:
            std::cout << "----------------------\n";
            setConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            std::cout << "        Venta          \n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            std::cout << "----------------------\n";

            purchase();

            break;

        default:
            std::cout << "ERROR!!!!!";
        }

    } while (option != 4);

}

Cinema::~Cinema() {}

