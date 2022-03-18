#include<iostream>
using namespace std;
class Set
{
public:
	Set(int n)
	{
		set_elements = new int[n];
		for (int i = 0; i < n; i++)
			set_elements[i] = -1;
		set_size = n;
	}
	void Union(int i, int j)
	{
		int m = Find_Parent(i), n = Find_Parent(j);
		if (m == n)return;
		else {
			set_elements[m] = set_elements[m] + set_elements[n];
			set_elements[n] = m;
		}
	}
	int Find_Parent(int i)
	{
		while (set_elements[i] >= 0)
			i = set_elements[i];
		return i;
	}
	int  Road_Needed()
	{
		int res = 0;
		for (int i = 0; i < set_size; i++)
			if (set_elements[i] < 0)res++;
		return res - 1;
	}
	~Set() { delete[]set_elements; }
private:
	int set_size;
	int* set_elements;
};
int main()
{
	int county_num = 0, road_num = 0, m = 0, n = 0;
	cin >> county_num >> road_num;
	Set County(county_num);
	for (int i = 0; i < road_num; i++)
	{
		cin >> m >> n;
		County.Union(m - 1, n - 1);
	}
	cout << County.Road_Needed() << endl;
}