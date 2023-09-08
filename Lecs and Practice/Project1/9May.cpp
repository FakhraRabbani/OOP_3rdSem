
/*
#include<iostream>

using namespace std;

class A
{
	int da;
public:

	A()
	{
		cout << "A def" << endl;
		this->da = 0;
	}

	A(int da)
	{
		cout << "A PARA" << endl;
		this->da = da;
	}

	A(const A& obj)
	{
		cout << "A COPY" << endl;
		this->da = obj.da;
	}

	virtual void print()
	{
		cout << "da: " << da << endl;
	}

	virtual ~A()
	{
		cout << "A des" << endl;
	}
};

class B : public A
{
	int db;
public:

	B() : A()
	{
		cout << "B def" << endl;
		this->db = 0;
	}

	B(int da, int db) : A(da)
	{
		cout << "b PARA" << endl;
		this->db = db;
	}

	B(const B& obj) : A(obj)
	{
		cout << "b copy" << endl;
		this->db = obj.db;
	}

	void print()
	{
		this->A::print();
		cout << "db: " << db << endl;
	}

	virtual ~B()
	{
		cout << "B des" << endl;
	}
};



int main()
{
	A* pa[2];

	pa[0] = new A(1);

	pa[1] = new B(2, 4);

	for (int i = 0; i < 2; i++)
	{
		delete pa[i];
	}

	return 0;
}
*/




#include <iostream>

using namespace std;

/*
class Player
{
protected:
	string name;

public:

	string getName()
	{
		return name;
	}

	void setName(string name)
	{
		this->name = name;
	}
};

class CricketPlayer : public Player
{
private:
	string name;

public:

	string getName()
	{
		return Player::name;
	}

	void setName(string msg)
	{
		Player::name = this->name;
	}
};

int main()
{
	Player* objb = new Player();
	objb->setName("Fakhar Zaman");



	CricketPlayer* objc = new CricketPlayer();
	objc->setName("Babar Azam");

	cout << objb->getName() << endl;
	cout << objc->getName();

	delete objb, objc;

	return 0;
}
*/




class Player
{
public:
	Player(void) { cout << "P"; }
	~Player(void) { cout << "P"; }
};

class Batsman : public Player
{
public:
	Batsman(void) { cout << "B"; }
	~Batsman(void) { cout << "B"; }
};

class Bowler : public Player
{
public:
	Bowler(void) { cout << "R"; }
	~Bowler(void) { cout << "R"; }
};

class AllRounder : public Player, public Batsman,public Bowler
{
public:
	AllRounder(void) { cout << "A"; }
	~AllRounder(void) { cout << "A"; }
};

int main()
{
	AllRounder* obj = new AllRounder();
	cout << endl;
	delete obj;
}