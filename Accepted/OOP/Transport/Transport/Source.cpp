#include <iostream>
#include <string>
typedef unsigned int uint;
using namespace std;

class Transport
{
protected:
	string Trademark;
	string owner;

public:
	Transport(string mark, string own) { Trademark = mark, owner = own; }
	Transport() :Transport("Benz", "Vovich"){}

	void SetMark(string name)
	{
		Trademark = name;
	}

	void SetOwner(string name)
	{
		owner = name;
	}

	virtual void Move()
	{
		cout << "No information how to move!\n";
	}

	string const GetMark()const { return Trademark; }
	string const GetOwner() const { return owner; }
};

class AirTransport : public Transport
{
protected:
	int amount_of_motors;
	int amount_of_pilots;

public:
	AirTransport(int motors = 0, int pilots = 0){ amount_of_motors = motors, amount_of_pilots = pilots; };
	AirTransport(int motors, int pilots, string mark, string own) :Transport(mark, own) { amount_of_motors = motors, amount_of_pilots = pilots; }

	virtual void Move()
	{
		cout << "We can fly!\n";
	}
};

class RailWayTransport : public Transport
{
protected:
	int amount_of_carriages;
	double distance_between_the_wheels;

public:
	RailWayTransport(int car = 0, double wheels = 1.5){ amount_of_carriages = car, distance_between_the_wheels = wheels; };
	RailWayTransport(int car, double wheels, string mark, string own): Transport(mark, own) { amount_of_carriages = car, distance_between_the_wheels = wheels; }
	virtual void Move()
	{
		cout << "We can chooh-chooh!\n";
	}
};

class WaterTransport : public Transport
{
protected:
	int displacement;
	string shipname;

public:
	WaterTransport(int dis, string name) { displacement = dis, shipname = name; }
	WaterTransport(int dis, string name, string mark, string own):Transport(mark, own) { displacement = dis, shipname = name; }
	WaterTransport() : WaterTransport(90000, "Step"){}

	virtual void Move()
	{
		cout << "We can sail ship!\n";
	}
};

class RoadTransport : public Transport
{
protected:
	int amount_of_doors;
	int amount_of_wheels;

public:
	RoadTransport(int doors = 4, int wheels = 4){ amount_of_doors = doors, amount_of_wheels = wheels; }
	RoadTransport(int doors, int wheels, string mark, string own):Transport(mark, own){ amount_of_doors = doors, amount_of_wheels = wheels; }

	virtual void Move()
	{
		cout << "We can drive this transport!\n";
	}
};

class Plain : public AirTransport
{
	string plain_model;
	string type;
public:
	Plain(string model, string type){ plain_model = model, this->type = type; }
	Plain(string model, string type, int motors, int pilots) :AirTransport(motors, pilots){ plain_model = model, this->type = type; }
	Plain(string model, string type, int motors, int pilots, string mark, string own) :AirTransport(motors, pilots, mark, own){ plain_model = model, this->type = type; }

	void Move()
	{
		cout << "We can fly fast, but can't stay at the same place in the air!\n";
	}
};

class Helicopter : public AirTransport
{
	string department;
	int work_index;
public:
	Helicopter(string dep, int index) { department = dep, work_index = index; }
	Helicopter(string dep, int index, int motors, int pilots) :AirTransport(motors, pilots){ department = dep, work_index = index; }
	Helicopter(string dep, int index, int motors, int pilots, string mark, string own) :AirTransport(motors, pilots, mark, own){ department = dep, work_index = index; }

	void Move()
	{
		cout << "We can stay at the same place in the air, but can't fly fast!\n";
	}
};

class PassengerTrain : public RailWayTransport
{
	uint amount_of_people;

public:
	PassengerTrain(uint people = 10){ amount_of_people = people; }
	PassengerTrain(uint people, int car, double wheels) :RailWayTransport(car, wheels){ amount_of_people = people; }
	PassengerTrain(uint people, int car, double wheels, string mark, string own) :RailWayTransport(car, wheels, mark, own){ amount_of_people = people; }

	void Move()
	{
		cout << "We make chooh-chooh with a lot of people!\n";
	}
};

class FreightTrain : public RailWayTransport
{
	uint freight;

public:
	FreightTrain(uint freight = 500){ this->freight = freight; }
	FreightTrain(uint freight, int car, double wheels) :RailWayTransport(car, wheels){ this->freight = freight; }
	FreightTrain(uint freight, int car, double wheels, string mark, string own) :RailWayTransport(car, wheels, mark, own){this->freight = freight;}
	void Move()
	{
		cout << "We make chooh-chooh with a lot of Gold!\n";
	}
};

class Fishing_smack : WaterTransport
{
	string fish_type;

public:
	Fishing_smack(string fish){ fish_type = fish; }
	Fishing_smack(string fish, int dis, string name) :WaterTransport(dis, name){ fish_type = fish; }
	Fishing_smack(string fish, int dis, string name, string mark, string own) :WaterTransport(dis, name, mark, own){ fish_type = fish; }

	void Move()
	{
		cout << "We move with a lot of fish...\n";
	}
};

class Crouiser : WaterTransport
{
	string fish_type; //on such ships a lot of fat rich people (our fishes))

public:
	Crouiser(string fish){ fish_type = fish; }
	Crouiser(string fish, int dis, string name) :WaterTransport(dis, name){ fish_type = fish; }
	Crouiser(string fish, int dis, string name, string mark, string own) :WaterTransport(dis, name, mark, own){ fish_type = fish; }

	void Move()
	{
		cout << "We move with a lot of fish...\n";
	}
};

class Car:public RoadTransport
{
	string type_of_motor;
	string type_of_corpus;

public:
	Car(string motor, string corpus) { type_of_motor = motor, type_of_corpus = corpus; }
	Car(string motor, string corpus, int doors, int wheels = 4):RoadTransport(doors, wheels) { type_of_motor = motor, type_of_corpus = corpus; }
	Car(string motor, string corpus, int doors, int wheels, string mark, string own) :RoadTransport(doors, wheels, mark, own) { type_of_motor = motor, type_of_corpus = corpus; }

	void Move()
	{
		cout << GetOwner() << " drives new cool " << GetMark() << endl;
	}
};

class Bike :public RoadTransport
{
	string bike_type;

public:
	Bike(string bike) { bike_type = bike; }
	Bike(string bike, int doors, int wheels = 2) :RoadTransport(doors, wheels) { bike_type = bike; }
	Bike(string bike, int doors, int wheels, string mark, string own) :RoadTransport(doors, wheels, mark, own) { bike_type = bike; }

	void Move()
	{
		cout << GetOwner() << " drives unbelivible " << GetMark() << endl;
	}
};

void main()
{
	Transport a("BMV", "Alex");
	cout << a.GetMark() << endl << a.GetOwner() << endl;
	a.Move();

	AirTransport b(2, 4, "TU", "Yurets");
	b.Move();
	cout << b.GetOwner() << endl;

	RailWayTransport c;
	c.Move();

	Car d("benzin", "sedan", 2, 4, "Mercedes", "Alex");
	d.Move();

	Bike f("sport", 0, 2, "Suzuki", "Nikolas");
	f.Move();
}