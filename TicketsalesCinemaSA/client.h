#pragma once
#include <cstdlib>
#include <ctime>

class Client
{
private:
	int id;
	int ticket;
	int creditCard;
	int reservedRow;
	int reservedCol;
public:
	Client();

	void setId(int pId);

	void setCreditCard(int pCreditCard);

	void setTicket();

	void setReservedChair(int row, int col);

	int getReservedRow();

	int getReservedCol();

	int getId();

	int getCreditCard();

	int getTicket();

	~Client();
};