#include <iostream>

using namespace std;

class A
{
public:
	A(string t):text(t){}
	const char& operator[](size_t pos)const
	{
		return text[pos];
	}
	char& operator[](size_t pos)
	{
		return const_cast<char&>(static_cast<const A&>(*this)[pos]);
		//return text[pos];
	}
private:
	string text;
};

void print(const A& t)
{
	cout<<t[0]<<endl;
}

int main()
{
	A t1("123456");
	cout<<t1[0]<<endl;
	t1[0] = '7';
	cout<<t1[0]<<endl;
	const A t2("234567");
	cout<<t2[0]<<endl;
	print(t2);

	return 0;
}
