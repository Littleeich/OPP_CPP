/*3.	Создать класс с домашним питомцем и издеваться над ним столько, на сколько хватит фантазии.*/

#include "Cat.h"
#include <iostream>
using namespace std;

void show_the_cat(Cat &myKitty)
{
	cout << "Имя: " << myKitty.Get_Name() <<endl;

	cout << "Пол: ";
	if (myKitty.Get_Gender() == GENDER::MALE)
		cout << "Пацанчик!" << endl;
	else
		cout << "Деваха" << endl;

	cout << "Окрас: ";
	if(myKitty.Get_Colour() == COLOUR::black)
		cout << "Черный"<< endl;
	else if (myKitty.Get_Colour() == COLOUR::grey)
		cout << "Серый" << endl;
	else if (myKitty.Get_Colour() == COLOUR::red)
		cout << "Рыжий" << endl;
	else if (myKitty.Get_Colour() == COLOUR::white)
		cout << "Белый" << endl;
	else 
		cout << "Полосатый" << endl;

	cout << "Уровень удовлетворенности жизнью: " << myKitty.Get_Moor() << endl;
	cout << "Вес: " << myKitty.Get_Weight() << endl;
	cout << "Длина: " << myKitty.Get_Length() << endl;
	cout << "Возраст: " << myKitty.Get_Age() << endl;
	cout << "Уровень голода: " << myKitty.Get_Hunger() << endl;
	cout << "Показатель жизни: ";

	if (myKitty.Get_Life())
		cout << "Живой" << endl;
	else
		cout << "Мертвый" << endl;

	cout << endl << endl;
}

void main()
{
	setlocale(0, "ru");
	cout << "Привет!\n";
	cout << "Давай поиграем с котятами...\nДля начала создадим кота!\n\n";

	Cat first;
	show_the_cat(first);

	Cat second("Vasya", GENDER::MALE, COLOUR::zebrastyle, 10, 8, 40, 4, 20);
	show_the_cat(second);

	Cat third = second;
	show_the_cat(third);

	bool stopper = false;
	while (!stopper){

		cout << "Что мы будем делать с третим котом?\n\n1)Покормим\n2)Погладим\n3)Покрасим\n4)Дадим ему покакать\n" <<
			"5)Выкинем в окно\n6)Отправим играть с сестрой\n7)Дадим поспать\n8)Назовём другим именем \n" <<
			"Если нужного нету, то набери другое число\n\n";
		cout << "Вы выбрали: ";
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
			cout << "В какой цвет мы перекрасим котяру?\n";
			cout << "1)Черный\n2)Серый\n3)Рыжий\n4)Белый\n5)Сделаем его полосатым\n\n";
			cout << "Ваш выбор: ";
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
			cout << "Введите имя нашего котяры: ";
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
