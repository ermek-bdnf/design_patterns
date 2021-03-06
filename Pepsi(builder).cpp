//builder
#include<iostream>
#include<string>
using namespace std;

class Pepsi
{
	string aboutPepsi;
	
	public:
		Pepsi()
		{
			aboutPepsi = "";
		}
		string AboutPepsi() const
		{
			return aboutPepsi;
		}
		void appendFeature(string str)
		{
			aboutPepsi += str;
		}
};

class Plant
{
	public:
		virtual void createPepsi() = 0;
		virtual void createVariant() = 0;
		virtual void createSugar() = 0;
		
		virtual Pepsi* getPepsi() = 0; //pointer on class Pepsi
};

class PepsiSt : public Plant
{
	Pepsi* pepsi;
	
	public:
		PepsiSt()
		{
			pepsi = new Pepsi();
		}
		~PepsiSt()
		{
			delete pepsi;
		}
		void createPepsi() override
		{
			pepsi->appendFeature("Pepsi ");
		}
		void createVariant() override
		{
			pepsi->appendFeature("Light ");
		}
		void createSugar() override
		{
			pepsi->appendFeature("Sugarfree");
		}
		Pepsi* getPepsi() override
		{
			return pepsi;
		}
};

class PepsiCoffee : public Plant
{
	Pepsi* pepsi;
	
	public:
		PepsiCoffee()
		{
			pepsi = new Pepsi();
		}
		~PepsiCoffee()
		{
			delete pepsi;
		}
		void createPepsi() override
		{
			pepsi->appendFeature("Pepsi ");
		}
		void createVariant() override
		{
			pepsi->appendFeature("Americano ");
		}
		void createSugar() override
		{
			pepsi->appendFeature("with Sugar");
		}
		Pepsi* getPepsi() override
		{
			return pepsi;
		}
};

class Chemist
{
	Plant* plant;
	
	public:
		Chemist(Plant* p) : plant(p)
		{
			
		}
		void setPlant(Plant* p)
		{
			plant = p;
		}
		Pepsi* PepsiFeaturePepsi()
		{
			plant->createPepsi();
			return plant->getPepsi();
		}
		Pepsi* AnyFeaturePepsi()
		{
			plant->createPepsi();
			plant->createVariant();
			plant->createSugar();
			return plant->getPepsi();
		}
};

int main()
{
	Plant* plant = new PepsiSt();
	Chemist chemist(plant);
	Pepsi* pepsi1 = chemist.PepsiFeaturePepsi();
	cout << pepsi1->AboutPepsi() << endl;			//Pepsi
	
	chemist.setPlant(new PepsiSt());
	Pepsi* pepsi2 = chemist.AnyFeaturePepsi();
	cout << pepsi2->AboutPepsi() << endl;			//Pepsi Light Sugarfree
	
	chemist.setPlant(new PepsiCoffee());	
	Pepsi* pepsi3 = chemist.AnyFeaturePepsi();
	cout << pepsi3->AboutPepsi() << endl;			//Pepsi Americano with Sugar
	
	return 0;
}
