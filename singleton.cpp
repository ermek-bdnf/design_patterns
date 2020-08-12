//singleton
#include<iostream>
#include<string>
using namespace std;

class XenomorphQueen
{
	private:
		XenomorphQueen()
		{
			
		}
		static XenomorphQueen* xqueen;
		string value;
		
	public:
		XenomorphQueen(const XenomorphQueen&) = delete; //delete the copy constructor
		void operator=(const XenomorphQueen&) = delete; //delete an assignment ('=') operator
		static XenomorphQueen* GetInstance() //static method
		{
			if(xqueen == nullptr)
				xqueen = new XenomorphQueen();
			return xqueen;
		}
		string getValue() const
		{
			return value;
		}
		void setValue(string v)
		{
			value = v;
		}
};

XenomorphQueen* XenomorphQueen::xqueen = nullptr;

int main()
{
	XenomorphQueen::GetInstance()->setValue("Xenomorph Queen");
	cout << XenomorphQueen::GetInstance()->getValue() << endl;
	return 0;
}
