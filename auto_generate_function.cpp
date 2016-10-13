#include <iostream>
#include <string>

using namespace std;

template<class T>class NamedObject;
template<class T>ostream& operator<<(ostream &os, NamedObject<T>& rhs);
template<class T>
class NamedObject
{
	//template<class T>
	friend ostream& operator<< <T>(ostream &os, NamedObject<T>& rhs);
public:
	NamedObject(string& name, const T& value):nameValue(name), objectValue(value){}
	NamedObject& operator=(NamedObject& rhs)
	{
		nameValue = rhs.nameValue;
	}
private:
	string& nameValue;
	const T objectValue;
};

template<class T>
ostream& operator<<(ostream &os, NamedObject<T>& rhs)
{
	os<<rhs.nameValue<<endl;
	os<<rhs.objectValue<<endl;
	return os;
}

int main()
{
	string newDog("123");
	string oldDog("456");
	NamedObject<int> p(newDog, 2);
	NamedObject<int> s(oldDog, 36);
	cout<<p;
	p = s;
	cout<<p;

	return 0;
}
