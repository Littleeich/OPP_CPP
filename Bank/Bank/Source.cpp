#include <iostream>
#include "Bank.h"

using namespace std;

void main()
{
	Bank F001(50000);
	Bank F002;
	/*cout << Bank::bank_balans << endl;
	F002.~Bank();
	cout << Bank::bank_balans << " and " << Bank::money_in_the_road << endl;*/

	F001.AddDeposit((13, 1, 2016), 36500.14, 90, 22.7);
	cout << F001.GetDepBalans()<< endl;
	F001.GiveLoan((10, 1, 2016), 730, 25, 40000);
	F002.GiveLoan((10, 1, 2016), 730, 25, 40000);
	F002.PayLoan((18, 6, 2007), 5500, 28, 30000);
	F001.GoodByeDeposit((21, 8, 2014), (21, 2, 2016), 25000, 19);
	cout << F001.GetDepBalans() << endl;
	cout << F002.GetDepBalans() << endl;
	cout << Bank::bank_balans << endl;
}