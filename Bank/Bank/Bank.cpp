#include "Bank.h"
#include <iostream>

double Bank::bank_balans = 0;
double Bank::money_in_the_road = 0;

double row(int number, int row)
{
	double result = 1;
	for (int i = 0; i < row; i++)
		result *= number;
	return result;
}

void Bank::SetMinBalans(double balans)
{
	min_balans = balans / 5;
}

void Bank::SetDepBalans(double dep_balans)
{
	if (dep_balans >= 0)
	{
		this->dep_balans = dep_balans;
		bank_balans += dep_balans;
	}
	else
		this->dep_balans = 0;
}

Bank::Bank(double dep_balance)
{
	SetDepBalans(dep_balance);
	SetMinBalans(dep_balance);
}

//в случае несанкционированного удаления филиала "силой", деньги не исчезают в никуда,
//а остаются на специальном счете "деньги в дороге"
Bank::~Bank()
{
	bank_balans -= dep_balans;
	money_in_the_road += dep_balans;
}

void Bank::AddDeposit(Date start, double sum, int period, double interest)
{
	//в будущем мы присоединим время начало и срок, в случае присоединения класса "Депозит"
	bank_balans += sum;
	dep_balans += sum;
}

double Bank::WhatDeposit(Date start, Date end, double sum, double interest)const
{
	double SumDep = sum * row((1 + (interest / 100.0)), (end - start) / 365.0);
	return SumDep;
}

void Bank::GoodByeDeposit(Date start, Date end, double sum, double interest)
{
	bank_balans -= sum * row((1 + (interest / 100.0)), (end - start) / 365.0);
	dep_balans -= sum * row((1 + (interest / 100.0)), (end - start) / 365.0);
}

void Bank::GiveLoan(Date start, int period, double interest, double sum, bool Standart)
{
	//start, period, interest and standart will be need for class "Loan"
	if (dep_balans - sum > min_balans)
	{
		bank_balans -= sum;
		dep_balans -= sum;
	}
	else
		printf("Cash Limit\n");
}

void Bank::PayLoan(Date start, int period, double interest, double sum, bool Standart)
{
	if (!Standart)
	{
		dep_balans += sum * row((1 + (interest / 100)), period / 365.0);
		bank_balans += sum * row((1 + (interest / 100)), period / 365.0);
	}
	else
	{
		return;
		//Standart type of Loans can't be organized without class "Loan"
	}
}