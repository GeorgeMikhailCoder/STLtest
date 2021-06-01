#define number short
#define myCount 5
#define maxCountDel 4
#include<iostream>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

void generate(vector<number>& v)
{
	for (int i = 0; i < myCount; i++)
	{
		v.push_back(rand() % 9 + 1);
	}
}

void generate(map<int, number>& m)
{
	for (int i = 0; i < myCount; i++)
	{
		m[i] = rand() % 9 + 1;
	}
}

void show(vector<number> v)
{
	if (v.size() == 0)
		cout << "Vector is empty" << endl;
	else 
	{
		cout << "vec = [ " << v[0] << " ";
		for (int i = 1; i < v.size(); i++)
			cout << v[i] << " ";
		cout <<"]" << endl;
	}

}

void show(map<int, number> m)
{
	if (m.empty())
		cout << "Map is empty" << endl;
	else
	{
		map <int, number> ::iterator iter = m.begin();

		cout << "map keys: \t";
		for (map <int, number> ::iterator iter = m.begin(); iter != m.end(); iter++)
			cout << iter->first << " ";

		cout <<endl<< "map values: \t";
		for (map <int, number> ::iterator iter = m.begin(); iter != m.end(); iter++)
			cout << iter->second << " ";

		cout << endl;
	}

}

void delSomething(vector<number>& v)
{
	srand(time(NULL));
	int n = rand() % (maxCountDel - 1) + 1;
	cout << "deleting " << n << " first values from vector" << endl;
	v.erase(v.begin(), v.begin() + n);
}

void delSomething(map<int, number>& m)
{
	int n = rand() % (maxCountDel - 1) + 1;
	cout << "deleting " << n << " first values from map" << endl;
	map <int, number> ::iterator iter;
	for (int i = 0; i < n; i++)
	{
		iter = m.find(i);
		cout << "deleting map" << i << " values " << m[i] << endl;
		m.erase(iter);
	}

}

void synchronize(vector<number>& v, map<int, number>& m)
{
	map <int, number> ::iterator iter;

	map <int, number> resMap;
	vector<short> resVec;
	int k = 0;

	for (iter = m.begin();iter != m.end();iter++)
	{

			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] == iter->second)
				{
					resVec.push_back(iter->second);
					resMap[k] = iter->second;
					k++;
					break;
				}
			}

	}
	v = resVec;
	m = resMap;

}

void main()
{
	srand(time(NULL));
	vector<number> vec1;
	map<int, number> map1;

	generate(vec1);
	generate(map1);
	show(vec1);
	show(map1);
	cout << endl;

	delSomething(vec1);
	delSomething(map1);
	show(vec1);
	show(map1);
	cout << endl;

	synchronize(vec1, map1);
	show(vec1);
	show(map1);
	system("pause");

}