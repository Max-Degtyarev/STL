#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"


//#define ARRAY
//#define VECTOR
//#define DEQUEU
#define LIST



void main()
{
	setlocale(LC_ALL, "");
	typedef int DataType;


#ifdef ARRAY

	const int n = 5;
	std::array<int, n> arr = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

#endif // ARRAY


#ifdef VECTOR

	std::vector<DataType> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	for (std::vector<DataType>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	for (std::vector<DataType>::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	vec.front() = 1024;
	cout << vec.front() << endl;
	cout << vec.back() << endl;

	cout << *(vec.data() + 4) << endl;

	cout << "\n---------------Vector capacity------------------\n";
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "Size:\t " << vec.size() << endl;
	cout << "MaxSize:  " << vec.max_size() << endl;
	
	vec.push_back(55);

	
	cout << "Capacity:" << vec.capacity() << endl;
	cout << "Size:\t " << vec.size() << endl;
	cout << "MaxSize:  " << vec.max_size() << endl;

	//vec.shrink_to_fit(); // уменьшает Capasity до фактическог размера
	vec.resize(8); // Принудительно задает размер vectora
	vec.reserve(55); // Задает Capasity vectora, работает только на увеличение

	//vec.assign({ 1024, 2048, 3072, 4096, 5120 });
	for (int i : vec)cout << i << tab; cout << endl;

	cout << "Capacity:" << vec.capacity() << endl;
	cout << "Size:\t " << vec.size() << endl;
	cout << "MaxSize:  " << vec.max_size() << endl;

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;

	//std::vector<DataType>::iterator position = vec.begin() + index;
	if (index <= vec.size())
		vec.insert(vec.begin() + index, 3, value);
	for (int i : vec)cout << i << tab; cout << endl;
	vec.insert(vec.begin() + 3, vec.end() - 3, vec.end() - 1);
	for (int i : vec)cout << i << tab; cout << endl;



#endif // VECTOR


#ifdef DEQUEU


	std::deque<DataType> deque = { 3, 5, 8, 13, 21 };
	for (std::deque<DataType>::iterator it = deque.begin(); it != deque.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	deque.push_back(34);
	deque.push_back(55);
	deque.push_back(89);
	deque.push_front(2);
	deque.push_front(1);
	deque.push_front(1);
	deque.push_front(0);
	for (int i : deque)cout << i << tab; cout << endl;

	for (std::deque<DataType>::reverse_iterator it = deque.rbegin(); it != deque.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;



#endif // DEQUEU


#ifdef LIST


	std::list<DataType>Mylist = { 5, 8, 13, 21, 52, 65, 85 };
	for (std::list<DataType>::iterator it = Mylist.begin(); it != Mylist.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;

	int index, index2, value;
	

	cout << "Введите индекс для вставки значения: ";
	do
	{
		cin >> index;
		if (index < 0 || index > Mylist.size())
		{
			cout << "Вы ввели неправильный индекс" << endl;
		}

	} while (index < 0 || index > Mylist.size());
	cout << "Введите добавляемое значение: "; cin >> value;

	if (index <= Mylist.size() / 2)
	{
		std::list<DataType>::iterator pos = Mylist.begin();
		for (int i = 0; i < index; i++)pos++;
		Mylist.insert(pos, value);
	}
	else
	{
		std::list<DataType>::iterator pos = Mylist.end();
		for (int i = 0; i < (Mylist.size() - index); i++)pos--;
		Mylist.insert(pos, value);

	}
	for (std::list<DataType>::iterator it = Mylist.begin(); it != Mylist.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
	


	cout << "Введитe индекс для удаления значения: "; cin >> index2;
	std::list<DataType>::iterator pos2 = Mylist.begin();
	for (int i = 0; i < index2; i++)pos2++;
	Mylist.erase(pos2);
	for (std::list<DataType>::iterator it = Mylist.begin(); it != Mylist.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;




#endif // LIST





	//int x = 1;
	//int& y = x;	//объявляем ссылку на константу
	//y += 7;
	//cout << x << endl;
	//x <<= 1;
	//cout << x << endl;
	//cout << (x << 1) << endl;



}