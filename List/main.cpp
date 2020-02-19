#include <iostream> 
#include "List.h"
using namespace std;

template<typename T>
void testList(List<T>& listObj, const string& typeName) {
	cout << "Testing a list of " << typeName << "values\n";
	cout << "1 - insert at the beginning of list\n"
		<< "2 - insert at the end of list\n"
		<< "3 - delete from beginning of list\n"
		<< "4 - delete from end of list\n"
		<< "5 - quit\n";

	int choice;
	T value;
	do {
		cout << "?";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObj.insertAtFront(value);
			listObj.print();
			break;
		case 2:
			cout << "Enter " << typeName << ": ";
			cin >> value;
			listObj.insertAtBack(value);
			listObj.print();
			break;
		case 3:
			if (listObj.removeFromFront(value))
				cout << value << " removed from list\n";
			listObj.print();
			break;
		case 4:
			if (listObj.removeFromBack(value))
				cout << value << " removed from list\n";
			listObj.print();
			break;
		}
	} while (choice < 5);
}

int main() {
	List<int> integerList;
	testList(integerList, "integer");
	

	return 0;
}
