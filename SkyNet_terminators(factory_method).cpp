//factory_method
#include<iostream>
using namespace std;

class iSkyNet //interface
{
public:
	virtual void show() = 0;	
};

class T600 : public iSkyNet
{
public:
	void show()
	{
		cout << "This is T600" << endl;
	}
};

class T1000 : public iSkyNet
{
public:
	void show()
	{
		cout << "This is T1000" << endl;
	}
};

class iSkCreator //interface
{
public:
	virtual iSkyNet* create() = 0;
};

class T600Creator : public iSkCreator
{
public:
	iSkyNet* create()
	{
		return new T600;
	}
};

class T1000Creator : public iSkCreator
{
public:
	iSkyNet* create()
	{
		return new T1000;
	}
};

int main()
{
	iSkCreator *sk = new T600Creator();
	iSkyNet* sk600 = sk->create();
	sk = new T1000Creator();
	iSkyNet* sk1000 = sk->create();
	sk600->show(); //This is T600
	sk1000->show(); //This is T1000
	return 0;
}
