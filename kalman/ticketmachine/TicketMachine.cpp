/*
 * TicketMachine.cpp
 *
 *  Created on: 2018Äê4ÔÂ26ÈÕ
 *      Author: super
 */

#include "TicketMachine.h"

#include <iostream>
using namespace std;

TicketMachine::TicketMachine() : PRICE(0){
	// TODO Auto-generated constructor stub
	balance = 0;
	total = 0;
}

TicketMachine::~TicketMachine() {
	// TODO Auto-generated destructor stub
}

void TicketMachine::showPrompt()
{
	cout << "something";
}

void TicketMachine::insertMoney(int money)
{
	balance += money;
}

void TicketMachine::printTicket()
{

}

void TicketMachine::showBalance()
{
	cout << "balance" << balance;
}
