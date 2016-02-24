#include <iostream>
#include <string>

typedef unsigned int uint;

using namespace std;

const uint length_of_field = 500;
const uint width_of_field = 750;

class Game
{
	uint game_id;
	uint local_settings;

public:
	static int gold;
	static int tree;
	static int food;
	static int diamonds;

	static int base_of_id;
};

int Game::diamonds = 0;
int Game::food = 20;
int Game::tree = 200;
int Game::gold = 1000;
int Game::base_of_id = 1;

struct Coord
{
	uint X = 0;
	uint Y = 0;

	Coord(uint a, uint b)
	{
		X = a;
		Y = b;
	}

	Coord() :Coord(0, 0){}
};

class Obj abstract
{
protected:
	Coord placement = Coord(0, 0);
public:

	Obj(){ placement = Coord(length_of_field, width_of_field); }
	Obj(Coord some){ placement = some; }
	Obj(uint a, uint b) { placement = Coord(a, b); }

	void Touch_my_obj()
	{
		cout << "No way!\n";
	}
};

class StaticObj abstract : public Obj
{
	uint obj_id;

public:
	StaticObj()
	{
		obj_id = Game::base_of_id++;
	}

	StaticObj(uint a, uint b) :Obj(a, b){}
};

class iLifePoints abstract
{
	virtual void injury()
	{
		cout << "another look of the obj\n";
	}

	virtual void death()
	{
		cout << "Capitan Jack!\n";
	}
};

class Houses abstract : public StaticObj, public iLifePoints
{
protected:
	short level;
	short house_width;
	short house_length;
	uint lifepoints;
	uint defence;
	uint cost;

public:
	Houses(){ level = 1, house_width = 1, house_length = 1, lifepoints = 10, defence = 1, cost = 10; }
	virtual void injury()
	{
		cout << "Some flame on the building!\n";
	}

	virtual void death()
	{
		cout << "Big bala bum!\n";
	}
};

class Church: public Houses
{
	short country_type;

public:
	Church(){ country_type = 1; }
};

class barracks : public Houses
{
	short army_type;

public:
	barracks(){ army_type = 1; }
};

class repository : public Houses
{
	short rep_type;

public:
	repository(){ rep_type = 1; }
};

class smithy : public Houses
{
	short weapons_type;

public:
	smithy(){ weapons_type = 1; }
};

class NPC abstract: public StaticObj
{
protected:
	bool isMale;
	bool isSpeaking;
public:
	NPC(){ isMale = false, isSpeaking = false; }
};

class WithQuests : public NPC
{
	uint amount_of_quests;
	string name;

public:
	WithQuests(uint a, string imya){ amount_of_quests = a, name = imya; }
	WithQuests() :WithQuests(0, "Alyosha"){}

	void ShowAbleQuests()
	{
		if (amount_of_quests > 0)
			cout << "I have something for you!\n";
		else
			cout << "I am too bizy today...\n";
	}
};

class WithOutQuests : public NPC
{
	string speach;
	string type;

public:
	WithOutQuests(string a, string imya){ speach = a, type = imya; }
	WithOutQuests() :WithOutQuests("NO", "Alyosha"){}

	void ShowSpeach()
	{
		if (speach != "NO")
			cout << speach;
		else
			return;
	}
};

class Place_of_resources abstract : public StaticObj, public iLifePoints
{
protected:	uint resources;
public:
	Place_of_resources(uint res){ resources = res; }
};

class Gold : public Place_of_resources
{
	string owner;

public:
	Gold(string own, uint res) :Place_of_resources(res){ owner = own; }

	void injury()
	{
		cout << "Less gold";
	}

	void death()
	{
		cout << "no gold...";
	}
};

class Wood : public Place_of_resources
{
	string type_of_wood;

public:
	Wood(string type, uint res) :Place_of_resources(res){ type_of_wood = type; }

	void injury()
	{
		cout << "Less trees";
	}

	void death()
	{
		cout << "no wood...";
	}
};

class Food : public Place_of_resources
{
	string type_of_food;

public:
	Food(string type, uint res) :Place_of_resources(res){ type_of_food = type; }

	void injury()
	{
		cout << "Less food";
	}

	void death()
	{
		cout << "no food...";
	}
};

class iFlyable abstract
{
	virtual void Fly()
	{
		cout << "I believe I can fly!";
	}
};

class iRunnable abstract
{
	virtual void Run()
	{
		cout << "I am Flash!";
	}
};

class iBite abstract
{
	virtual void kus_kus()
	{
		cout << "Chum chom chom";
	}
};

class iScratch abstract
{
	virtual void scratch()
	{
		cout << "Like a crazy prostitute";
	}
};

class DynamicObj : public Obj, public iLifePoints
{
protected:
	Coord prev;
	Coord now;
	Coord next;
	uint lifePoints = 600;
	uint level = 1;
public:
	DynamicObj(){ ; }
};

class Monster : public DynamicObj
{
protected:
	string type_name;
public:
	Monster(string type){ type_name = type; }
	Monster() :Monster("Bdzhilka"){}
};

class Dragon : public Monster, public iFlyable, public iBite, public iScratch
{
	string color;
public:
	Dragon(string col){ color = col; }
	Dragon() : Dragon("red"){}

	void Fly()
	{
		cout << "I fly to my princes!\n";
	}
};

class Bat : public Monster, public iFlyable, public iBite
{
	string SEX;
public:
	Bat(){ SEX = "Male"; }
};

class Wolf : public Monster, public iRunnable, public iBite
{
	string step;
public:
	Wolf(){ step = "usual"; }
};

class Squerell : public Monster, public iRunnable, public iScratch
{
	string type;
public:
	Squerell() { type = "crazy"; }
};

class Sceleton : public Monster, public iRunnable
{
	bool bow;
public:
	Sceleton() { bow = false; }
};

class Players : public DynamicObj
{
protected:
	string name;
	uint id;
public:
	Players(string a){ name = a, id = Game::base_of_id++; }
	Players()
	{
		char * temp;
		_itoa_s(Game::base_of_id, temp, 5, 10);
		name = temp;
		id = Game::base_of_id++;
	}
};

class Wizard : public Players, public iFlyable
{
	string skill;
public:
	Wizard(){ skill = "bird_attack"; }
};

class Elf : public Players
{
	string bow;
public:
	Elf() { bow = "arbalet"; }
};

class Warrior : public Players
{
	string type_of_sword;
public:
	Warrior() { type_of_sword = "stick"; }
};

class Package_items abstract
{
protected:
	uint positions;
	uint cost;
public:
	Package_items(){ positions = 1, cost = 10; }
};

class Jewels :public Package_items
{
	uint type;
public:
	Jewels(){ type = 1; }
};

class weapon : public Package_items
{
protected:
	uint attack;
public:
	weapon(){ attack = 1; }
};

class bow : public weapon
{
	uint level;
	uint add_skills;
public:
	bow(){ level = 1, add_skills = 0; }
};

class sword : public weapon
{
	string type;
	uint aggr;
public:
	sword(){ type = "new", aggr = 0; }
};

class staff : public weapon
{
	string weather_type;
public:
	staff() { weather_type = "air"; }
};

class clothes : public Package_items
{
	uint def;
public:
	clothes() { def = 1; }
};

void main()
{
	;
}