#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
	vector<int> input{3,4,4,4,4,4,4,1,2,5};

	map<int, int> m;
	unordered_map<int, int> um;

	for (auto value : arr) {
		m[value]++;
		um[value]++;

		cout << "current value is um[" << value << "] = " << um[value]<<endl;
	}

	cout << "Map = " << endl;
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << endl;

	cout << "Unordered Map = " << endl;
	for (auto it = um.begin(); it != um.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << endl;

	return 0;
}
