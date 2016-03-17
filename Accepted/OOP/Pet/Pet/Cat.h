#pragma once
#include <iostream>
using namespace std;

enum class COLOUR{ black, white, grey, red, zebrastyle };

enum class GENDER{ MALE, FEMALE };

class Cat{
	char * name;
	int moor;
	int weight;
	int length;
	int age;
	int hunger;
	COLOUR cat_colour;
	GENDER cat_gender;
	bool life;

public:
	Cat(char *name, GENDER cat_gender, COLOUR cat_colour, int age, int weight, int length, int moor, int hunger, bool life);
	Cat(char *name, GENDER cat_gender, COLOUR cat_colour, int age, int weight, int length, int moor, int hunger) :
		Cat(name, cat_gender, cat_colour, age, weight, length, moor, hunger, 1){};
	Cat(char *name, GENDER cat_gender, COLOUR cat_colour, int age, int weight, int length, int moor) :
		Cat(name, cat_gender, cat_colour, age, weight, length, moor, 40, 1){};
	Cat(char *name, GENDER cat_gender, COLOUR cat_colour, int age, int weight, int length) :
		Cat(name, cat_gender, cat_colour, age, weight, length, 5, 40, 1){};
	Cat(char *name, GENDER cat_gender, COLOUR cat_colour, int age, int weight) :
		Cat(name, cat_gender, cat_colour, age, weight, 20, 5, 40, 1){};
	Cat(char *name, GENDER cat_gender, COLOUR cat_colour, int age) :
		Cat(name, cat_gender, cat_colour, age, 1, 20, 5, 40, 1){};
	Cat(char *name, GENDER cat_gender, COLOUR cat_colour) :
		Cat(name, cat_gender, cat_colour, 1, 1, 20, 5, 40, 1){};
	Cat(char *name, GENDER cat_gender) :
		Cat(name, cat_gender, COLOUR::black, 1, 1, 20, 5, 40, 1){};
	Cat(char *name) :
		Cat(name, GENDER::MALE, COLOUR::black, 1, 1, 20, 5, 40, 1){};
	Cat():
		Cat("NoCatInMyHouse", GENDER::MALE, COLOUR::black, 0, 0, 0, 0, 0, 0){};

	//конструктор копирования, т.к. у нас есть поле нейм, работающее сдинамической памятью
	Cat(const Cat & other) :Cat(other.name, other.cat_gender, other.cat_colour, other.age, 
		other.weight, other.length, other.moor, other.hunger, other.life)
	{}

	~Cat();


	void Set_Name(char * name);
	//я решил не мучать кота и пол не менять!
	void Set_Colour(COLOUR cat_colour);
	//moor - степень доброжелательности кота
	void Set_Moor(int moor);
	void Set_Weight(int weight);
	void Set_Length(int length);
	void Set_Age(int age);
	void Set_Hunger(int hunger);
	void Set_Life(bool life);

	char * Get_Name()const{ return name; };
	GENDER Get_Gender()const { return cat_gender; };
	COLOUR Get_Colour()const { return cat_colour; };
	int Get_Moor()const { return moor; };
	int Get_Weight()const { return weight; };
	int Get_Length()const { return length; };
	int Get_Age()const { return age; };
	int Get_Hunger()const { return hunger; };
	bool Get_Life()const { return life; };

	void Set_Feed(int food);
	void Stroking(int dMoor);
	void shit(int shit);
	void throw_out_the_window();
	void playing_with_a_sister();
	void sleep();
};
