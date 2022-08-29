#include<iostream>
using namespace std;


class Foo
{

public:
	int x;
	int y;


};




//#define EXM_1
#define EXM_2


void main()
{

	setlocale(LC_ALL, "");

#ifdef EXM_1


	int x = 0;
	int y = 0;
	if (x++ && y++)
	{
		y += 2;
	}
	cout << x + y << endl;


#endif // EXM_1


#ifdef EXM_2

	Foo r;
	if (&r.x < &r.y)
	{

		cout << "Я программист" << endl;

	}
#endif // EXM_2






}