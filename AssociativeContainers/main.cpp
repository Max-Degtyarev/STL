#include<iostream>
#include<string>
#include<set>
#include<map>
#include<list>
#include <windows.h>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Kitten
{
	std::string name;
public:

	Kitten(const std::string& name) : name(name){}
	bool operator<(const Kitten& other)const
	{
		return this->name < other.name;
	}
	bool operator>(const Kitten& other)const
	{
		return this->name > other.name;
	}


	friend std::ostream& operator << (std::ostream& os, const Kitten& obj)
	{
		return os << obj.name;
	}



};



//#define STL_SET
//#define STL_MAP
//#define STL_MAP2


void main()
{

	setlocale(LC_ALL, "");

#ifdef STL_SET
	std::multiset<int> i_set = { 50, 25, 75, 16, 16, 16, 32, 64, 64, 64, 88, 22 };
	for (int i : i_set)cout << i << tab; cout << endl;
	for (std::set<int>::reverse_iterator it = i_set.rbegin(); it != i_set.rend(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;


	std::set<std::string>s_set = { "хорошо", "живет", "на", "свете", "Винни пух" };
	for (std::string i : s_set)cout << i << tab; cout << endl;


	std::set<Kitten> k_set = { Kitten("Tom"), Kitten("Garfield"), Kitten("Tiger") };
	for (Kitten i : k_set)cout << i << tab; cout << endl;
#endif // STL_SET

#ifdef STL_MAP
	std::multimap<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		{2, "Tuesday"},
		{3, "Wednesday"},
		{4, "Thursday"},
		{5, "Friday"},
		{6, "Saturaday"},
		{7, "Sunday"},
		{0, "Sunday"},
		{0, "Sunday"}
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << tab << it->second << endl;
	}

#endif // STL_MAP






#ifdef STL_MAP2
	std::map<std::string, std::list<std::string>> dictionary =
	{
		std::pair<std::string, std::list<std::string>>("clutter", {"беспорядок", "хаос"}),
		{"space", {"пространство", "пробел", "космос"}},
		{"plural", {"множественное число", ""}},
		{"worth", {"ценность", "значимость"}}
	};

	/*for (std::map<std::string, std::list<std::string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << ":\t";
		for (std::list<std::string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			cout << *it2 << ", ";
		}
		cout << ";\n";
	}*/


	for (std::pair<std::string, std::list<std::string>> i : dictionary)
	{
		cout << i.first << ":\t";
		for (std::string j : i.second)
		{
			cout << j << ", ";
		}
		cout << ";\n";
	}

#endif // STL_MAP2




	std::map<int, std::list<std::string>> database =
	{
		{458, {"Превышение скорости"}},
		{859, {"Остановка под запрещающим знаком"}},
		{156, {"Проезд на красный свет"}}

	};


	for (std::pair<int, std::list<std::string>> i : database)
	{
		cout << i.first << ":\t";
		for (std::string j : i.second)
		{
			cout << j << ", ";

		}
		cout << endl;

	}

	int number;
	char offence[50];
	std::list<std::string> list_offence;
	

	cout << "Введите номер машины: "; cin >> number;
	cout << "Введите правонарушение (для окончания ввода введите \"стоп\"): ";
	
	int n = 0;

	
	do
	{
		SetConsoleCP(1251);
		cin.getline(offence, 50);
		if (offence[0] != 'с' || offence[1] != 'т' || offence[2] != 'о' || offence[3] != 'п')
		{
			if (offence[1] != -52)
			{
				list_offence.push_back(offence);
				n++;
			}
		}

	} while (offence[0] != 'с' || offence[1] != 'т' || offence[2] != 'о' || offence [3] != 'п');
	
	

	std::map<int, std::list<std::string>>::iterator it = database.find(number);
	if (it == database.end())
	{
		database.insert(it, std::pair<int, std::list<std::string>>(number, list_offence));

	}
	else
	{

		std::list<std::string>::iterator it2 = list_offence.begin();
		for (int i = 0; i < n; i++)
		{
			it->second.push_back(it2->c_str());
			it2++;
		}

	}
	

	for (std::pair<int, std::list<std::string>> i : database)
	{
		cout << i.first << ":\t";
		for (std::string j : i.second)
		{
			cout << j << ", ";

		}
		cout << endl;

	}

	





}
