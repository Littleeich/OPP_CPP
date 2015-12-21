#include "Cat.h"

Cat::Cat(char *name, GENDER cat_gender, COLOUR cat_colour, int age, int weight, int length, int moor, int hunger, bool life)
{
	Set_Name(name);
	this->cat_gender = cat_gender;
	Set_Colour(cat_colour);
	Set_Moor(moor);
	Set_Weight(weight);
	Set_Length(length);
	Set_Age(age);
	Set_Hunger(hunger);
	Set_Life(life);
}

Cat::~Cat()
{
	delete[] name;
}

void Cat::Set_Name(char * name)
{
	int length = strlen(name) + 1;
	if (length < 2) return;

	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

void Cat::Set_Colour(COLOUR cat_colour)
{
	this->cat_colour = cat_colour;
}

void Cat::Set_Moor(int moor)
{
	if (moor < 0)
		this->moor = 0;
	else if (moor > 10)
		this->moor = 10;
	else
		this->moor = moor;

}

void Cat::Set_Weight(int weight)
{
	if (weight < 1)
		this->weight = 1;
	else if (weight > 50)
		this->weight = 50;
	else
		this->weight = weight;
}

void Cat::Set_Length(int length)
{
	if (length < 1)
		this->length = 1;
	else if (length > 80)
		this->length = 80;
	else
		this->length = length;
}

void Cat::Set_Age(int age)
{
	if (age < 1)
		this->age = 1;
	else if (age > 25)
		this->age = 25;
	else
		this->age = age;
}

void Cat::Set_Hunger(int hunger)
{
	if (hunger < 1)
		this->hunger = 1;
	else if (hunger > 50)
		this->hunger = 50;
	else
		this->hunger = hunger;
}

void Cat::Set_Life(bool life)
{
	this->life = life;
}

void Cat::Set_Feed(int food)
{
	Set_Hunger(hunger + food);
	Set_Weight(weight + food / 2);
}

void Cat::Stroking(int dMoor)
{
	Set_Moor(moor + dMoor);
}

void Cat::shit(int shit)
{
	Set_Hunger(hunger - shit);
}

void Cat::throw_out_the_window()
{
	Set_Name("GoodByeMyCat");
	Set_Age(0);
	Set_Hunger(0);
	Set_Length(0);
	Set_Weight(0);
	Set_Life(0);
}

void Cat::playing_with_a_sister()
{
	Set_Moor(-5);
	shit(20);
	Set_Weight(weight - 1);
	Set_Length(length - 2);
	Set_Age(age + 2);
}

void Cat::sleep()
{
	Set_Moor(moor + 1);
	Set_Age(age + 1);
	Set_Weight(weight + 1);
	Set_Length(length + 5);
}