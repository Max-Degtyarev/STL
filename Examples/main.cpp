#include<iostream>
using namespace std;



//#define EXM1


int Sum(int *n, int *m)
{

	*n += 5;
	*m += 8;

	return *n + *m;


}




void main()
{

	setlocale(LC_ALL, "");


	

	//int n = 10;
	//
	//while (n != 0)
	//{
	//	cout << n << endl;
	//	n--;

	//}


#ifdef EXM1
	int n;
	cout << "Введите номер заказа: ";

	do
	{
		cin >> n;
		if (n < 5 || n > 10)
		{
			cout << "Вы ввели неправильный номер!" << endl;

		}


	} while (n < 5 || n > 10);

	cout << "Вы ввели правильный номер" << endl;
#endif // EXM1




	//for (int i = 0; i < 10; i++)
	//{
	//	cout << i << endl;


	//}







	

	int n = 10;
	int m = 7;

	cout << "n = " << n << endl;
	cout << "m = " << m << endl;

	cout << Sum(&n, &m) << endl;

	cout << "n = " << n << endl;
	cout << "m = " << m << endl;


//	int* pointer = &n;
//
//	cout << pointer << endl;
//
//	cout << *pointer << endl;
//
//
//


}

