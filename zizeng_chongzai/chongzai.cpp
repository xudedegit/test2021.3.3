#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

class MyInteger
{
	friend ostream& operator <<(ostream& cout, MyInteger& myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}

	//重载前置++运算符
	MyInteger& operator++()
	{
		m_Num++;
		return (*this);
	}
	//重载后置++运算符
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		m_Num++;
		return temp;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, MyInteger& myint)
{
	cout <<"myint的m_Num为:"<< myint.m_Num << endl;
	return cout;
}
void test01()
{
	MyInteger myint;
	cout <<  ++(++myint) << endl;
	cout << myint << endl;
	
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
int main()
{
	//test01();
	test02();
	system("pause");
	return 0;

}