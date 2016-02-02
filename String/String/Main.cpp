#include <iostream>
#include "String.h"
#include "boobs.h"
#include <time.h>

using namespace std;

void main()
{
	setlocale(0, "ru");
	srand(time(0));
	/*String first("some flowers on the window of my heart", 10);
	cout << "Capacity " << first.GetCapacity() << endl;
	cout << "Length " << first.GetLength() << endl;
	cout << "Amount of symbols = " << first.StrLen(first.GetStr()) << endl;

	String a = first;
	cout << a.GetStr() << endl;*/

	String b("Oh my le mala la");
	String c(8);
	/*String d(b, 70);

	cout << b.GetCapacity() << "     " << b.GetLength() << endl;
	cout << c.GetCapacity() << "     " << c.GetLength() << endl;
	cout << d.GetStr() << endl;*/

	//c = first;
	//cout << c.GetStr() << endl;

	//if (b < c)
	//	cout << "Operator Works!\n\n";
	//else
	//	cout << "Operator Doesn't Work!\n\n";

	/*b("96.57599");
	cout << b.GetStr() << endl;*/
	/*c(b);
	cout << c.GetStr() << endl;

	cout << c[5] << endl;*/

	/*String d = b + c;
	cout << d.GetStr() << endl;*/

	/*char * some = " !!!";
	d = c + some;
	cout << d.GetStr() << endl;
	d = some + b;*/
	/*cout << (char*)d << endl;
	cout << (int)b << endl;
	cout << (double)b << endl;
	double k = 95.57599;
	cout << k << endl;

	cout << b << endl;

	cin >> b;
	cout << b << endl;
	b.Print();
	b.PrintLn();
	b.GetLine();*/
	/*cout << b.CompareTo(b) << endl << b.CompareTo(c) <<  endl;
	cout << c;
	cout << b.CompareTo("96.57599") << endl << b.CompareTo("975555") << endl;*/
	//c.Concat(b);
	//cout << c << endl;
	//c.Concat(" is my number!");
	//cout << c << endl;
	//c.Concat(123.56);
	//cout << c << endl;
	//String * t = & c;
	//b.Concat(t, 4);
	//cout << b << endl;

	//b("        Sose        chars...Sose chars...          ");
	//c("chars...");
	//if (b.Equals(c))
	//	cout << "It works!\n";
	//else
	//	cout << "Retry!\n";
	////c.CopyTo(d);
	//cout << d << endl;
	//d += c;
	//char * text = nullptr;
	//d += text;
	//cout << d << endl;
	//cout << b.IndexOf('s') << endl;
	//cout << b.LastIndexOf('s') << endl;
	//cout << b.IndexOf(c) << endl;
	//cout << b.LastIndexOf(c) << endl;
	//cout << b.IndexOfAny(d) << endl;
	//cout << b << c << endl;
	///*b.TrimEnd();
	//cout << b << c << endl;
	//b.TrimStart();*/
	//b.Trim();
	//cout << b << c << endl;
	//b.Normalize();
	//cout << b << c << endl;
	//b.PadLeft(10);
	//cout << b << endl;
	//b.PadRight(10);
	//cout << b << c << endl;
	//b.Remove(18);
	//cout << b << c << endl;
	//b.Remove(13, 2);
	//cout << b << c << endl;
	//b.Replace('h', 'X');
	//cout << b << endl;

	b("...some final methods, some final steps...");
	c(" ");
	String d("_");
	b.Replace(c, d);
	cout << b << endl;
	b("Тестовая проверка русского текста");
	cout << b << endl;
	b.ToUpper();
	cout << b << endl;
	b.ToLower();
	cout << b << endl;
	b.Revers();
	cout << b << endl;
	b.SortAZ();
	cout << b << endl;
	b.SortZA();
	cout << b << endl;
	b.Shuffle();
	cout << b << endl;
	//b.RandomFill();
	cout << b << endl;
	c("--Normal Text--");
	b.Insert(c, 4);
	cout << b << endl;
	b = b + c;
	cout << b << endl;
	char some[] = "  some text  !";
	b = b + some;
	cout << b << endl;
	cout << String::Compare(c, b) << endl;
	String g("Kill my mind ");
	g.Concat(50.0000);
	g.Concat(some);
	cout << g << endl;
	cout << boolalpha << g.Equals(b) << endl;
	cout << boolalpha << g.Equals(g) << endl;
	cout << g.CompareTo(g) << endl;
	String t("515,88");
	cout << (double)t + 5 << endl;
}
