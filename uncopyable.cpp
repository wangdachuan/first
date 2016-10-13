#include <iostream>

using namespace std;

class Uncopyable
{
protected:
	Uncopyable(){}
	~Uncopyable(){cout<<"~Uncopyable()"<<endl;}
private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class A:private Uncopyable
{
public:
	A(){cout<<"A()"<<endl;}
	~A(){cout<<"~A()"<<endl;}
};

int main()
{
	A a;
	//A b(a);
	//A c;
	//c = a;

	return 0;
}
