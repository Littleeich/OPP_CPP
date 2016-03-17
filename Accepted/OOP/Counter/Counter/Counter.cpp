/*
2.	����������� ����� Counter, ����������� �������� �������. ����� �� ����� ����� ������
����� ���������� � ������������ ����������, �������� ������� ������������, ���� �
������������� �������� ��������� ������������ ��������� (��������, ���������� current
����� ��������� �������� � ��������� �� 0 �� 99999). � �������� ��������� ������� ������
�������� ����������� ������� ����������� � ����������, ��� �� �������� ������� �� �����
������� ���� ��� ��������������. ������������ ����: ������� �������� ��������, ������������
�������� ���������, ����������� �������� ���������, ��� ��������. ������������ ������:
����������� �� ���������, ��������� ����� ������������� � �����������, ���������� ��������
�������� �������� �� 1, ���������� �������� �� �������� �������� (��� ��������), �����
(���������) ��������, ��������� ������������ � ������������� ��������.*/

#include <iostream>
#include <cstdlib>
using namespace std;

class Counter{
	int number;
	int min;
	int max;
	int size;
	int step;

public:
	Counter(double number, int max, int min, int size, int step);
	Counter(double number, int max, int min, int size) :Counter(number, max, min, size, 1){};
	Counter(double number, int max, int min) :Counter(number, max, min, 4, 1){};
	Counter(double number, int max) :Counter(number, max, 0, 4, 1){};
	Counter(double number) :Counter(number, 9999, 0, 4, 1){};
	Counter() :Counter(0, 9999, 0, 4, 1){};

	void SetNum(double number)
	{
		if (number - (int)number != 0)
			number = (int)number;
		if (number < 0)
			number = -number;
		if (number >= min && number <= max)
			this->number = (int)number;
		else if (number < min)
			this->number = 0;
		else
			this->number = (int)number % (max - min + 1);
	}

	int GetNum() const
	{
		return number;
	}

	int GetMin() const
	{
		return min;
	}

	int GetMax() const
	{
		return max;
	}

	int GetSize() const
	{
		return size;
	}

	int GetStep() const
	{
		return step;
	}

	void ShowNumber()
	{
		printf("%0*.*d\n", 0, size, number);
	}

	void SetMinimum(int min)
	{
		if (min < max && min > 0)
			this->min = min;
		else
			this->min = 0;
	}

	void SetMaximum(int max)
	{
		if (max > min)
			this->max = max;
		//���� ��� ���������� ���������� �������� ���� ��������, �� �� �������������� �������� �� ������� �� ��� ������ ��������
		else
		{
			int temp = 1;
			for (int i = 0; i < size; i++)
			{
				temp *= 10;
			}
			this->max = temp - 1;
		}
	}

	void SetSize(int size)
	{
		if (size > 0 && size < 10)
		{
			//���� ������������ ����� ������ ����� ������, ��� ����������� ��� ���������� ���������, �� ����� ��� �� �� ��������
			char strmax[80];
			_itoa_s(max, strmax, 10);
			int size_of_max = strlen(strmax);
			if (size < size_of_max)
				this->size = size_of_max;
			else
				this->size = size;
		}
		else
			this->size = 10;
	}

	void SetAdd(int step)
	{
		SetNum(number + step);
	}

	void SetStep(int step)
	{
		if (step > 0)
			this->step = step;
	}
};

Counter::Counter(double number, int max, int min, int size, int step)
{
	SetMaximum(max);
	SetMinimum(min);
	SetSize(size);
	SetStep(step);
	SetNum(number);
}

void main()
{
	cout << "The start position of the Counter is: ";
	int number;
	cin >> number;
	Counter shet(number);

	shet.ShowNumber();

	Counter shet2;
	shet2.ShowNumber();

	cout << endl << endl;
	bool stopper = 0;
	while (!stopper){
		cout << "Please, choose what you want to do:\n1)Change the minimum of the Counter." <<
			"\n2)Change the maximum of the Counter.\n3)Change the amount of the numbers in the Counter." <<
			"\n4)Add 1 point to the Counter\n5)Add more points to the counter\n6)Restart Counter" <<
			"\n\nPress another number to stop the procedure...\n\nYour choise is: ";
		int choise;
		cin >> choise;
		switch (choise){
		case 1:
		{
			cout << "What is the new Minimum?";
			int temp;
			cin >> temp;
			shet.SetMinimum(temp);
			break;
		}
		case 2:
		{
			cout << "What is the new Maximum?";
			int temp;
			cin >> temp;
			shet.SetMaximum(temp);
			break;
		}
		case 3:
		{
			cout << "How many numbers should it be?";
			int temp;
			cin >> temp;
			shet.SetSize(temp);
			break;
		}
		case 4:
		{
			cout << "The task is done!";
			shet.SetAdd(1);
			break;
		}
		case 5:
		{
			cout << "How many points do you want to add?";
			int temp;
			cin >> temp;
			shet.SetStep(temp);
			shet.SetAdd(shet.GetStep());
			break;
		}
		case 6:
		{
			cout << "The task is done!";
			shet.SetNum(shet.GetMin());
			break;
		}
		default:
			stopper = 1;
		}

		system("cls");
		shet.ShowNumber();
		cout << "Max is " << shet.GetMax() << endl << "Min is " << shet.GetMin() << endl <<
			"Size is " << shet.GetSize() << endl << "Step is " << shet.GetStep() << endl << endl;
	}
}
