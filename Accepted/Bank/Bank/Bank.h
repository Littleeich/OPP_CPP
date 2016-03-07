#pragma once
#include "Date.h"

class Bank
{
	double dep_balans;
	double min_balans;
public:
	static double bank_balans;
	static double money_in_the_road;
	double GetDepBalans()const { return dep_balans; };
	double GetBankBalans()const { return bank_balans; };

	void SetDepBalans(double dep_balans);
	void SetMinBalans(double balanse);

	void AddDeposit(Date start, double sum, int period, double interest);
	void GoodByeDeposit(Date start, Date end, double sum, double interest);

	double WhatDeposit(Date start, Date end, double sum, double interest)const;
	double LoanLeft(); //данный метод требует отдельный класс для учета ссуд

	void GiveLoan(Date start, int period, double interest, double sum, bool Standart = 0);
	void PayLoan(Date start, int period, double interest, double sum, bool Standart = 0);

	Bank(double dep_balans);
	Bank() :Bank(10000){};

	~Bank();
};

