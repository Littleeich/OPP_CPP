#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

using namespace std;

class AbstractWeapon abstract
{
public:
	virtual void Action1()
	{
		cout << "piu\n";
	}

	virtual void Action2()
	{
		cout << "pif-paf\n";
	}

	virtual void Change() = 0;
};

class Knife : public AbstractWeapon
{
	void Change()
	{
		cout << "The weapon was changed on knife!\n";
	}

	void Action1()
	{
		cout << "Scratch scratch\n";
	}

	void Action2()
	{
		cout << "Prf hrf\n";
	}
};

class Pistol : public AbstractWeapon
{
	void Change()
	{
		cout << "The weapon was changed on pistol!\n";
	}

	void Action1()
	{
		cout << "\a";
	}

	void Action2()
	{
		cout << "A new clip is inserted\n!";
	}
};

class UZI : public AbstractWeapon
{
	void Change()
	{
		cout << "The weapon was changed on UZI!\n";
	}

	void Action1()
	{
		cout << "pi-pi-piu piu piu\n";
	}

	void Action2()
	{
		cout << "brf hrf mrf\n";
	}
};

class M14 : public AbstractWeapon
{
	void Change()
	{
		cout << "The weapon was changed on M14!\n";
	}

	void Action1()
	{
		cout << "a\a\a\n";
	}

	void Action2()
	{
		cout << "psh psh psh\n";
	}
};

class Sniper : public AbstractWeapon
{
	void Change()
	{
		cout << "The weapon was changed on Sniper!\n";
	}

	void Action1()
	{
		cout << "Aim is in contact\n";
	}

	void Action2()
	{
		cout << "\a\n";
	}
};

class Chechnya : public AbstractWeapon
{
	void Change()
	{
		cout << "The weapon was changed to Chechnya!\n";
	}

	void Action1()
	{
		for (int i = 0; i < 20; i++)
			cout << "\a psh \n";
	}

	void Action2()
	{
		for (int i = 0; i < 40; i++)
			cout << "\a badish \n";
	}
};

class Woman : public AbstractWeapon
{
	void Change()
	{
		cout << "The weapon was changed on woman!\n";
	}

	void Action1()
	{
		for (int i = 0; i < 10; i++)
			cout << "Ты меня не любишь!\n";
	}

	void Action2()
	{
		for (int i = 0; i < 20; i++)
			cout << "Ой всё!\n";
	}
};

void main()
{
	setlocale(0, "ru");

	cout << "Приветствую тебя, мой друг!\n"
		<< "Выбери оружие, которое тебе по душе.\n1) нож; \n2) пистолет; \n3) УЗИ; \n4) М14; \n5) Снайперская винтовка; \n6) Чечня; \n7) Баба.\n";
	AbstractWeapon * ptr;

	Pistol p;
	Knife kn;
	UZI uzi;
	M14 m;
	Sniper s;
	Chechnya ch;
	Woman lady;

	ptr = &p;
	
	while (true)
	{
		//Sleep(3000);
		if (_kbhit())
		{
			int k = _getch();
			switch (k)
			{
			case 32:
				ptr->Action1();
				break;
			case 13:
				ptr->Action2();
				break;
			case 49:
				ptr = &kn;
				break;
			case 50:
				ptr = &p;
				break;
			case 51:
				ptr = &uzi;
				break;
			case 52:
				ptr = &m;
				break;
			case 53:
				ptr = &s;
				break;
			case 54:
				ptr = &ch;
				break;
			case 55:
				ptr = &lady;
				break;
			default:
				break;
			}
			if (k >= 49 && k <= 55)
				ptr->Change();
			//system("cls");
			cout << "Выберите, что вы хотите сделать... \nДействие 1: Пробел \nДействие 2: Энтер \nЛибо же выберите новое оружие!\n";
		}
	}
}