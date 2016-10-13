#include <iostream>

using namespace std;

class A
{
	public:
		virtual void print(){cout<<"A"<<endl;}
		void print2(){cout<<"A2"<<endl;}
};

class B:public A
{
	public:
		virtual void print(){cout<<"B"<<endl;}
		void print2(){cout<<"B2"<<endl;}
};

int main()
{
	A a;
	B b;
	a = b;
	a.print();
	A *p = new B();
	(*p).print();

	return 0;
}
