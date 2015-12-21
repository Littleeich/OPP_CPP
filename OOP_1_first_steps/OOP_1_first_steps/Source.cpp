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

/*
2.	Реализовать класс Counter, описывающий цифровой счетчик. Одним из полей этого класса 
будет переменная с ограниченным диапазоном, значение которой сбрасывается, если её 
целочисленное значение достигает определённого максимума (например, переменная current 
может принимать значения в диапазоне от 0 до 99999). В качестве реального примера такого 
счётчика представьте счётчик километража в автомобиле, или же домашний счётчик по учёту 
расхода воды или электроэнергии. Обязательные поля: текущее значение счётчика, максимальное 
значение диапазона, минимальное значение диапазона, шаг прироста. Обязательные методы: 
конструктор по умолчанию, несколько видов конструкторов с параметрами, увеличение текущего
значения счётчика на 1, увеличение значения на заданную величину (шаг прироста), сброс 
(обнуление) счётчика, установка минимального и максимального значений.*/
//
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//class Counter{
//	int number;
//	int min;
//	int max;
//	int size;
//	int step;
//
//public:
//	Counter(double number, int max, int min, int size, int step);
//	Counter(double number, int max, int min, int size) :Counter(number, max, min, size, 1){};
//	Counter(double number, int max, int min) :Counter(number, max, min, 4, 1){};
//	Counter(double number, int max) :Counter(number, max, 0, 4, 1){};
//	Counter(double number) :Counter(number, 9999, 0, 4, 1){};
//	Counter() :Counter(0, 9999, 0, 4, 1){};
//
//	void Set_Num(double number)
//	{
//		if (number - (int)number != 0)
//			number = (int)number;
//		if (number < 0)
//			number = -number;
//		if (number >= min && number <= max)
//			this->number = (int)number;
//		else if (number < min)
//			this->number = 0;
//		else
//			this->number = (int)number % (max - min + 1);
//	}
//
//	int Get_Num() const
//	{
//		return number;
//	}
//
//	int Get_Min() const
//	{
//		return min;
//	}
//
//	int Get_Max() const
//	{
//		return max;
//	}
//
//	int Get_Size() const
//	{
//		return size;
//	}
//
//	int Get_Step() const
//	{
//		return step;
//	}
//
//	void Show_Number()
//	{
//		printf("%0*.*d\n", 0, size, number);
//	}
//
//	void Set_Minimum(int min)
//	{
//		if (min < max && min > 0)
//			this->min = min;
//		else
//			this->min = 0;
//	}
//
//	void Set_Maximum(int max)
//	{
//		if (max > min)
//			this->max = max;
//		//если нам предлагают установить максимум ниже минимума, то мы организовываем максимум из девяток на всю ширину счетчика
//		else
//		{
//			int temp = 1;
//			for (int i = 0; i < size; i++)
//			{
//				temp *= 10;
//			}
//			this->max = temp - 1;
//		}
//	}
//
//	void Set_Size(int size)
//	{
//		if (size > 0 && size < 10)
//		{
//			//если максимальное число знаков будет меньше, чем необходимое для отобраения максимума, то будет как то не камильфо
//			char strmax[80];
//			_itoa_s(max, strmax, 10);
//			int size_of_max = strlen(strmax);
//			if (size < size_of_max)
//				this->size = size_of_max;
//			else
//				this->size = size;
//		}
//		else
//			this->size = 10;
//	}
//
//	void Set_Add(int step)
//	{
//		Set_Num(number + step);
//	}
//
//	void Set_Step(int step)
//	{
//		if (step > 0)
//			this->step = step;
//	}
//};
//
//Counter::Counter(double number, int max, int min, int size, int step)
//{
//	Set_Maximum(max);
//	Set_Minimum(min);
//	Set_Size(size);
//	Set_Step(step);
//	Set_Num(number);
//}
//
//void main()
//{
//	cout << "The start position of the Counter is: ";
//	int number;
//	cin >> number;
//	Counter shet(number);
//
//	shet.Show_Number();
//
//	Counter shet2;
//	shet2.Show_Number();
//
//	cout << endl << endl;
//	bool stopper = 0;
//	while (!stopper){
//		cout << "Please, choose what you want to do:\n1)Change the minimum of the Counter." <<
//			"\n2)Change the maximum of the Counter.\n3)Change the amount of the numbers in the Counter." <<
//			"\n4)Add 1 point to the Counter\n5)Add more points to the counter\n6)Restart Counter" <<
//			"\n\nPress another number to stop the procedure...\n\nYour choise is: ";
//		int choise;
//		cin >> choise;
//		switch (choise){
//		case 1:
//		{
//			cout << "What is the new Minimum?";
//			int temp;
//			cin >> temp;
//			shet.Set_Minimum(temp);
//			break;
//		}
//		case 2:
//		{
//			cout << "What is the new Maximum?";
//			int temp;
//			cin >> temp;
//			shet.Set_Maximum(temp);
//			break;
//		}
//		case 3:
//		{
//			cout << "How many numbers should it be?";
//			int temp;
//			cin >> temp;
//			shet.Set_Size(temp);
//			break;
//		}
//		case 4:
//		{
//			cout << "The task is done!";
//			shet.Set_Add(1);
//			break;
//		}
//		case 5:
//		{
//			cout << "How many points do you want to add?";
//			int temp;
//			cin >> temp;
//			shet.Set_Step(temp);
//			shet.Set_Add(shet.Get_Step());
//			break;
//		}
//		case 6:
//		{
//			cout << "The task is done!";
//			shet.Set_Num(shet.Get_Min());
//			break;
//		}
//		default:
//			stopper = 1;
//		}
//
//		system("cls");
//		shet.Show_Number();
//		cout << "Max is " << shet.Get_Max() << endl << "Min is " << shet.Get_Min() << endl <<
//			"Size is " << shet.Get_Size() << endl << "Step is " << shet.Get_Step() << endl << endl;
//	}
//}
