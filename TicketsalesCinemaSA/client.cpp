#include "client.h"

Client::Client() : id(0), ticket(0), creditCard(0), reservedRow(-1), reservedCol(-1) {
	srand(static_cast<unsigned>(time(0)));
}

void Client::setId(int pId) {
	id = pId;
}

void Client::setCreditCard(int pCreditCard) {
	creditCard = pCreditCard;
}

void Client::setTicket() {
	ticket = rand() % 9000 + 1000;
}

void Client::setReservedChair(int row, int col) {
	reservedRow = row; reservedCol = col;
}

int Client::getReservedRow() {
	return reservedRow;
}

int Client::getReservedCol() {
	return reservedCol;
}

int Client::getId() {
	return id;
}

int Client::getCreditCard() {
	return creditCard;
}

int Client::getTicket() {
	return ticket;
}

Client::~Client() {

}