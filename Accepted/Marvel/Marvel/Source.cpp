#include <iostream>
#include <string>
#include "Temp_DLL.h"

using namespace std;


class Ability abstract
{
public:
	virtual void IcanThis()
	{
		cout << "What Can I Do?\n";
	}
};

class iFly: public Ability
{
	void IcanThis()
	{
		cout << "I can fly!\n";
	}
};

class iRunFast : public Ability
{
	void IcanThis()
	{
		cout << "I can run very fast\n";
	}
};

class iRegenerate : public Ability
{
	void IcanThis()
	{
		cout << "I can heal myself\n";
	}
};

class iReadMind : public Ability
{
	void IcanThis()
	{
		cout << "I can read other's mind\n";
	}
};

class iStong : public Ability
{
	void IcanThis()
	{
		cout << "I am stronger than humans!\n";
	}
};

class iSexual : public Ability
{
	void IcanThis()
	{
		cout << "Everybody wants to fuck me\n";
	}
};

class iArmor : public Ability
{
	void IcanThis()
	{
		cout << "It is very hard to hurt me\n";
	}
};

class iDisguise : public Ability
{
	void IcanThis()
	{
		cout << "It is very hard to find me\n";
	}
};

enum class SEX {MALE, FEMALE, SOME};

class Subject
{
protected:
	string name;
	bool IsGood;
	SEX sex;
	DList<Ability *> Abies;

public:
	Subject(string _name, bool _good, SEX _sex)
	{
		name = _name;
		IsGood = _good;
		sex = _sex;
	}
	Subject(string _name) :Subject(_name, true, SEX::MALE){}
	Subject() :Subject("Arnold", true, SEX::MALE){}

	string const GetName()const { return name; }
	bool GetIsGood() const { return IsGood; }
	SEX GetSex()const { return sex; }
	DList<Ability *>& GetList() { return Abies; }

	void SetName(string _name) { name = _name; }
	void SetIsGood(bool type) { IsGood = type; }
	void SetSex(SEX newS) { sex = newS; }

	void AddAbil(Ability * some) { Abies.AddHead(some); }
};

class Human : public Subject
{
	int age;
	string country;

public:
	Human(string _name, bool _good, SEX _sex, int _age, string _country) : Subject(_name, _good, _sex) { age = _age, country = _country; }
	Human(string _name, int _age, string _country) : Subject(_name){ age = _age, country = _country; }
	Human() :Subject(){ age = 0, country = "USA"; }

	int GetAge() const { return age; }
	string const GetCountry() const { return country; }

	void SetAge(int age)
	{
		if (age > 0)
			this->age = age;
		else
			this->age = 0;
	}

	void SetCountry(string _country) { country = _country; }
};

class HalfHuman : public Subject
{
	string secondHalf;
public:
	HalfHuman(string _name, bool _good, SEX _sex, string second) :Subject(_name, _good, _sex) { secondHalf = second; }
	HalfHuman(string _name, string second) :Subject(_name) { secondHalf = second; }
	HalfHuman(string _name) :Subject(_name) { secondHalf = "Wolf"; }
	HalfHuman(){ secondHalf = "Wolf"; }

	string const GetHalf() const { return secondHalf; }
	void SetHalf(string second) { secondHalf = second; }
};

class God : public Subject
{
	string religion;
	string from;

public:
	God(string _name, bool _good, SEX _sex, string _rel, string place) : Subject(_name, _good, _sex){ religion = _rel, from = place; }
	God(string _name) :Subject(_name){ religion = "Unknown", from = "Anywhere"; }
	God(){ religion = "Unknown", from = "Anywhere"; }

	const string const GetReligion() const { return religion; }
	const string const GetFrom() const { return from; }

	void SetReligion(string rel) { religion = rel; }
	void SetFrom(string place) { from = place; }
};

void founder(Subject any[], uint size, Ability * some)
{
	cout << "A list of some ability: ";
	int k = 0;
	for (uint i = 0; i < size; i++)
		for (uint j = 0; j < any[i].GetList().GetCount(); j++)
			if (any[i].GetList()[j] == some)
			{
				cout << any[i].GetName() << endl;
				k++;
			}
	if (k == 0)
		cout << "Empty list...";
	cout << endl;
}

void main()
{
	Subject Arny;
	cout << Arny.GetName() << " " << boolalpha << Arny.GetIsGood() << " " << Arny.GetList().GetCount() << endl;
	Arny.SetName("Shavartz");

	Ability * ptr;

	iArmor ar;
	iFly fly;
	iDisguise dis;
	iReadMind read;
	iRegenerate reg;
	iRunFast run;
	iSexual sexy;
	iStong str;

	/*ptr = &ar;
	Arny.GetList().AddHead(ptr);
	ptr = new iFly;
	Arny.GetList().AddHead(ptr);
	Arny.GetList()[1]->IcanThis();
	Arny.GetList()[0]->IcanThis();
	delete ptr;
	ptr = new iReadMind;
	Arny.AddAbil(ptr);
	Arny.GetList()[0]->IcanThis();
	delete ptr;*/

	HalfHuman Groot;
	cout << Groot.GetName() << endl;
	Groot.SetName("Groot");
	Groot.SetHalf("Tree");
	cout << Groot.GetHalf() << "  " << Groot.GetName() << endl;
	Groot.AddAbil(&str);
	Groot.AddAbil(&ar);
	Groot.AddAbil(&reg);

	God Tor("Thor", true, SEX::MALE, "Scandinavia", "Valhala");
	cout << Tor.GetName() << "  " << Tor.GetReligion() << endl;
	Tor.AddAbil(&sexy);
	Tor.AddAbil(&ar);
	Tor.AddAbil(&str);
	Tor.AddAbil(&fly);

	Human Storm("Storm", true, SEX::FEMALE, 25, "Euphiopia");
	Storm.AddAbil(&sexy);
	Storm.AddAbil(&fly);

	Subject * arr = new Subject[3];
	arr[0] = Groot;
	arr[1] = Tor;
	arr[2] = Storm;

	founder(arr, 3, &str);
}