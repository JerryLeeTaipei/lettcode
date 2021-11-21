#include <iostream>
#include <iterator>
#include <map>

using namespace std;

int main()
{

	// empty map container
	map<int, int> mapA;

	// insert elements in random order
	mapA.insert(pair<int, int>(1, 40));
	mapA.insert(pair<int, int>(2, 30));
	mapA.insert(pair<int, int>(3, 60));
	mapA.insert(pair<int, int>(4, 20));
	mapA.insert(pair<int, int>(5, 50));
	mapA.insert(pair<int, int>(6, 50));
	mapA.insert(pair<int, int>(7, 10));

	// printing map mapA
	map<int, int>::iterator itr;
	cout << "\nThe map mapA is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = mapA.begin(); itr != mapA.end(); itr++) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;

	// assigning the elements from mapA to mapB
	map<int, int> mapB(mapA.begin(), mapA.end());

	// print all elements of the map mapB
	cout << "\nThe map mapB after"
		<< " assign from mapA is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = mapB.begin(); itr != mapB.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;

	// remove all elements up to
	// element with key=3 in mapB
	cout << "\nmapB after removal of"
			" elements from the begin to the key=3 : \n";
	cout << "\tKEY\tELEMENT\n";
	mapB.erase(mapB.begin(), mapB.find(3));
	for (itr = mapB.begin(); itr != mapB.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	// remove all elements with key = 4
	int num;
	num = mapB.erase(4);
	cout << "\nmapB.erase(4) : ";
	cout << num << " removed \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = mapB.begin(); itr != mapB.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	cout << endl;

	// lower bound and upper bound for map mapA key = 5
	cout << "mapA.lower_bound(5) : "
		<< "\tKEY = ";
	cout << mapA.lower_bound(5)->first << '\t';
	cout << "\tELEMENT = "
		<< mapA.lower_bound(5)->second << endl;
	cout << "mapA.upper_bound(5) : "
		<< "\tKEY = ";
	cout << mapA.upper_bound(5)->first << '\t';
	cout << "\tELEMENT = "
		<< mapA.upper_bound(5)->second << endl;

	return 0;
}

