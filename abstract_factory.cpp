//abstract Factory
#include<iostream>
#include<string>
using namespace std;

class iWeapon //interface
{
	public:
		virtual void useWeapon() = 0; //purely virtual method
};

class PlasmWeapon : public iWeapon
{
	public:
		void useWeapon() override
		{
			cout << "Plasm weapon";
		}
};

class LazerWeapon : public iWeapon
{
	public:
		void useWeapon() override
		{
			cout << "Lazer weapon";
		}
};

class iCyborg //interface
{
	public:
		virtual void useCyborg(iWeapon* weapon) = 0; //purely virtual method
};

class T600 : public iCyborg
{
	public:
		void useCyborg(iWeapon* weapon) override
		{
			cout << "T600 with ";
			weapon->useWeapon();
		}
};

class T1000 : public iCyborg
{
	public:
		void useCyborg(iWeapon* weapon) override
		{
			cout << "T1000 with ";
			weapon->useWeapon();
		}
};

class iFactory
{
	public:
		virtual iWeapon* createWeapon() = 0;
		virtual iCyborg* createCyborg() = 0;
};

class T600Factory : public iFactory
{
	public:
		iWeapon* createWeapon() override
		{
			return new PlasmWeapon();
		}
		iCyborg* createCyborg()
		{
			return new T600();
		}
};

class T1000Factory : public iFactory
{
	public:
		iWeapon* createWeapon() override
		{
			return new LazerWeapon();
		}
		iCyborg* createCyborg() override
		{
			return new T1000();
		}
};

int main()
{
	iFactory *factoryT600 = new T600Factory();
	iWeapon* weaponB = factoryT600->createWeapon();
	iCyborg* t600 = factoryT600->createCyborg();
	t600->useCyborg(weaponB);
	cout << endl;
	iFactory *factoryT1000 = new T1000Factory();
	iWeapon* weaponL = factoryT1000->createWeapon();
	iCyborg* t1000 = factoryT1000->createCyborg();
	t1000->useCyborg(weaponL);
	return 0;
}
