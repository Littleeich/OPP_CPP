///*
//1.	Реализовать класс Point, описывающий точку в двумерном (или трёхмерном) пространстве. 
//Предусмотреть поля, хранящие координаты по X и Y. Сделать конструктор по умолчанию, 
//конструктор с параметрами, геттеры и сеттеры для всех полей, а также методы, позволяющие 
//переместить точку (например - вверх, вниз, влево, вправо) на указанное количество единиц.*/

#include <iostream>
using namespace std;

class Point{
	int x;
	int y;
	int min;
	int max;
public:
	Point(double x, double y, int max = 15000, int min = -15000);
	Point() :Point(0, 0, 15000, -15000){};

	void SetChangeX(int dx)
	{
		if (dx + x >= min && dx + x <= max)
			this->x += dx;
		else if (dx + x < min)
			this->x = min;
		else
			this->x = max;
	}

	void SetChangeY(int dy)
	{
		if (dy + y >= min && dy + y <= max)
			this->y += dy;
		else if (dy + y < min)
			this->y = min;
		else
			this->y = max;
	}


	void PCout()
	{
		cout << "(" << x << ", " << y << ")\n";
	}

	//в моей системе координат все числа должны быть интовыми... 
	void SetX(double x)
	{
		if (x - (int)x == 0)
			this->x = x;
		else
			this->x = (int)x;
	}

	//в моей системе координат все числа должны быть интовыми... 
	void SetY(double y)
	{
		if (y - (int)y == 0)
			this->y = y;
		else
			this->y = (int)y;
	}

	int GetY() const
	{
		return y;
	}

	int GetX() const
	{
		return x;
	}

	void SetMinimum(int min)
	{
		if (min < max)
			this->min = min;
		else
			this->min = max - 1000;
	}

	void SetMaximum(int max)
	{
		if (max > min)
			this->max = max;
		//если нам предлагают установить максимум ниже минимума, то мы организовываем максимум = min + 1000
		else
			this->max = min + 1000;
	}
};

Point::Point(double x, double y, int max, int min)
{
	SetMaximum(max);
	SetMinimum(min);
	SetX(x);
	SetY(y);
}

void TotalChange(Point &point)
{
	cout << "What is the move by X line? ";
	int dx;
	cin >> dx;
	point.SetChangeX(dx);
	cout << "\nWhat is the move by Y line? ";
	int dy;
	cin >> dy;
	point.SetChangeY(dy);
	cout << endl << endl;
}

void main()
{
	double a, b;
	double c, d;
	cout << "First two numbers: ";
	cin >> a >> b;
	cout << "\nSecond two numbers: ";
	cin >> c >> d;
	Point one;
	one.PCout();

	Point two(a, b);
	two.PCout();

	Point three(c, d);
	three.PCout();

	bool loop = 1;
	while (loop)
	{
		cout << "Please, choose the Point that you want to change:\n" <<
			"1) The first Point\n" << "2) The second Point\n" << "3) The third Point"
			<< "\nPress the other number, if you want to exit...\n\n" <<
			"Your choise is: ";
		int choise;
		cin >> choise;
		switch (choise){
		case 1:
			TotalChange(one);
			break;
		case 2:
			TotalChange(two);
			break;
		case 3:
			TotalChange(three);
			break;
		default:
			loop = 0;
		}
	}

	one.PCout();
	two.PCout();
	three.PCout();

}

