#include <iostream>
#include <math.h>

using namespace std;

const double PI = 3.14159265359;

class Figure abstract
{
protected:
	int x = 0;
public:
	virtual double area() = 0;
	virtual double perimetr() = 0;
	virtual void show() = 0;

	Figure(int x) { this->x = x; }
	Figure() :Figure(0){}

	int GetX()const { return x; }
};

class Point : virtual public Figure
{
public:
	double area() { return 0; }
	double perimetr() { return 0; }
	void show() { cout << "."; }
};

class Straight : virtual public Figure
{
protected:
	int y = 0;
public:
	double area() { return 0; }
	double perimetr() { return 0; }
	void show() { cout << "Straight"; }
};

class Ellips : virtual public Figure
{
protected:
	int ey = 0;
	int ex2 = 10;
	int ey2 = 10;

public:
	Ellips(int a, int b, int a2, int b2) { x = a, ey = b, ex2 = a2, ey2 = b2; }
	Ellips() :Ellips(GetX(), 0, 0, 0){}

	double area() { return ((ex2 - x) / 2)*((ey2 - ey) / 2)*PI; }
	double perimetr() { return 4 * ((PI * (ex2 - x) * (ey2 - ey) + abs(ex2 - x - ey2 + ey))) / (ex2 - x + ey2 - ey); }
	void show() { cout << "Ellips"; }
};

class Polygon : virtual public Figure
{
public:
	Polygon(int x) :Figure(x){}
	Polygon() :Figure(){}
	void show() { cout << "Polyon"; }
};

class circle : virtual public Ellips
{
protected:
	double radius;
public:
	circle(int a, double r) : Ellips(a, a, a + r * 2, a + r * 2) { radius = r; }
	circle() : circle(0, 5){}

	double area() { return PI * radius * radius; }
	double perimetr() { return 2 * PI * radius; }
	void show() { cout << "circle"; }
};

class treangle : virtual public Polygon
{
protected:
	
	double x1x2, x2x3, x1x3;

public:

	treangle(double a, double b, double c) : Polygon() { x1x2 = a, x2x3 = b, x1x3 = c; }

	double perimetr() { return x1x2 + x2x3 + x1x3; }
	double area() { return sqrt(perimetr()/2 * (perimetr()/2 - x1x2) * (perimetr()/2 - x2x3) * (perimetr()/2 - x1x3)); }
	void show() { cout << "Treangle!"; }
};

class quadry : public Polygon
{
protected:
	int y = 0;
	int x2 = 10;
	int y2 = 10;

public:
	quadry(int x1, int y1, int _x2, int _y2) :Polygon(x1){ y = y1, x2 = _x2, y2 = _y2; }
	quadry() :quadry(0, 0, 10, 10){}

	double perimetr() { return /*sum of all sydes*/ (x2 - x) * 2 + (y2 - y) * 2; }
	virtual double area() = 0;
	void show() { cout << "some rectangle"; }
};

class usualTreangle : public treangle
{
public:
	usualTreangle(double a, double b, double c) : treangle(a, b, c){}
	usualTreangle() : usualTreangle(2, 6, 8){}
	void show() { cout << "usual treangle"; }
};

class acuteTreangle : public treangle
{
public:
	acuteTreangle(double a, double b, double c) : treangle(a, b, c){}
	acuteTreangle() : acuteTreangle(3, 4, 5){}
	void show() { cout << "acute treangle"; }
};

class equalsidetriangle : public treangle
{
public:
	equalsidetriangle(double a) : treangle(a, a, a){}
	equalsidetriangle() : equalsidetriangle(10){}
	void show() { cout << "eq treangle"; }
};

class parallelogram : public quadry
{
protected:
	int h;
	double xy;
public:
	parallelogram(int a, int b, int c, int d, int h, double xy) :quadry(a, b, c, d) { this->h = h, this->xy = xy; }
	parallelogram(int a, int b, int c, int d) : parallelogram(a, b, c, d, 0, (c - a)){}
	parallelogram(int H, double XY){ h = H, xy = XY; }
	parallelogram() : parallelogram(0, 0, 10, 10, 0, 10){}

	double area() { return h * xy; }
	void show() { "some prllgrm"; }
};

class trapezia : public quadry
{
protected:
	int h;
	double xy;
	double x2y2;
public:
	trapezia(int a, int b, int c, int d, int h, double xy, double x2y2) :quadry(a, b, c, d) { this->h = h, this->xy = xy, this->x2y2 = x2y2; }
	trapezia(int a, int b, int c, int d) : trapezia(a, b, c, d, 0, (c - a), (d - b)){}
	trapezia(int H, double XY, double X2Y2) : quadry() { h = H, xy = XY, x2y2 = X2Y2; }
	trapezia() : trapezia(4, 10, 0, 10, 0, 10, 14){}

	double area() { return h * abs(xy - x2y2) / 2; }
	void show() { "some prllgrm"; }
};

class rectangle : public parallelogram
{
public:
	rectangle(int h, double xy) : parallelogram(h, xy){}
	rectangle() : parallelogram() {}
};

class rhombus : public parallelogram
{
	rhombus(int h, double xy) : parallelogram(0, 0, xy, xy, h, xy){}
	rhombus() : parallelogram() {}
};

class squere :virtual public parallelogram
{
public:
	squere(int h, double xy) : parallelogram(0, 0, xy, xy, h, xy){}
	squere() : squere(10, 10) {}
};

class circleInTheSphere :virtual public circle, virtual public squere
{
public:
	circleInTheSphere(int a, int b, int c, int d, double r, int h, double xy)
	{ circle::x = a, squere::x = a, ey = b, y = b, ex2 = c, x2 = c, 
	ey2 = d, y2 = d, radius = r, this->h = h, this->xy = xy; }
	circleInTheSphere(int r) : circleInTheSphere(0, 0, r * 2, r * 2, r, r * 2, r * 2){}
	circleInTheSphere(int h, double xy) : circleInTheSphere(0, 0, h, h, h / 2, h, xy){}
	circleInTheSphere() :circleInTheSphere(0, 0, 0, 0, 0, 0, 0){}

	void show() { cout << "New figure!"; }
	double area() { return h * xy; }
	double perimetr() { return circle::perimetr() + squere::perimetr(); }
};

void main()
{
	circle a(6, 8);
	cout << a.GetX() << endl;
	cout << a.area() << "  and  " << a.Ellips::area() << endl;

	usualTreangle c;
	cout << c.area() << "  " << c.perimetr() << endl;
	
	circleInTheSphere f(10);
	cout << f.area();
	cout << endl;
}