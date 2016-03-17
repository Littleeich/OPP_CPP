/*3.	������� ����� � �������� �������� � ���������� ��� ��� �������, �� ������� ������ ��������.*/

#include "Cat.h"
#include <iostream>
using namespace std;

void show_the_cat(Cat &myKitty)
{
	cout << "���: " << myKitty.Get_Name() <<endl;

	cout << "���: ";
	if (myKitty.Get_Gender() == GENDER::MALE)
		cout << "��������!" << endl;
	else
		cout << "������" << endl;

	cout << "�����: ";
	if(myKitty.Get_Colour() == COLOUR::black)
		cout << "������"<< endl;
	else if (myKitty.Get_Colour() == COLOUR::grey)
		cout << "�����" << endl;
	else if (myKitty.Get_Colour() == COLOUR::red)
		cout << "�����" << endl;
	else if (myKitty.Get_Colour() == COLOUR::white)
		cout << "�����" << endl;
	else 
		cout << "���������" << endl;

	cout << "������� ����������������� ������: " << myKitty.Get_Moor() << endl;
	cout << "���: " << myKitty.Get_Weight() << endl;
	cout << "�����: " << myKitty.Get_Length() << endl;
	cout << "�������: " << myKitty.Get_Age() << endl;
	cout << "������� ������: " << myKitty.Get_Hunger() << endl;
	cout << "���������� �����: ";

	if (myKitty.Get_Life())
		cout << "�����" << endl;
	else
		cout << "�������" << endl;

	cout << endl << endl;
}

void main()
{
	setlocale(0, "ru");
	cout << "������!\n";
	cout << "����� �������� � ��������...\n��� ������ �������� ����!\n\n";

	Cat first;
	show_the_cat(first);

	Cat second("Vasya", GENDER::MALE, COLOUR::zebrastyle, 10, 8, 40, 4, 20);
	show_the_cat(second);

	Cat third = second;
	show_the_cat(third);

	bool stopper = false;
	while (!stopper){

		cout << "��� �� ����� ������ � ������ �����?\n\n1)��������\n2)��������\n3)��������\n4)����� ��� ��������\n" <<
			"5)������� � ����\n6)�������� ������ � �������\n7)����� �������\n8)������ ������ ������ \n" <<
			"���� ������� ����, �� ������ ������ �����\n\n";
		cout << "�� �������: ";
		short choise;
		cin >> choise;

		switch (choise){
		case 1:
			third.Set_Feed(10);
			break;
		case 2:
			third.Stroking(2);
			break;
		case 3:
		{
			cout << "� ����� ���� �� ���������� ������?\n";
			cout << "1)������\n2)�����\n3)�����\n4)�����\n5)������� ��� ���������\n\n";
			cout << "��� �����: ";
			int choise2;
			cin >> choise2;

			if (choise2 == 1)
				third.Set_Colour(COLOUR::black);
			else if (choise2 == 2)
				third.Set_Colour(COLOUR::grey);
			else if (choise2 == 3)
				third.Set_Colour(COLOUR::red);
			else if (choise == 4)
				third.Set_Colour(COLOUR::white);
			else if (choise == 5)
				third.Set_Colour(COLOUR::zebrastyle);
			else
				cout << "Wrong number. So no paint today!\n";
			break;
		}
		case 4:
			third.shit(10);
			break;
		case 5:
			third.throw_out_the_window();
			break;
		case 6:
			third.playing_with_a_sister();
			break;
		case 7:
			third.sleep();
			break;
		case 8:
		{
			cout << "������� ��� ������ ������: ";
			char * nick = new char[80];
			cin >> nick;
			third.Set_Name(nick);
			delete[] nick;
			break;
		}
		default:
			stopper = true;
		}
	}

	system("cls");
	show_the_cat(third);
}
