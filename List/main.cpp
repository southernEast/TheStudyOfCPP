#include <iostream> 
#include "List.h"
#include "Stack.h"
#include "Queue.h"
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
	Queue<int> intQueue;

	for (int i = 0; i < 10; ++i) {
		intQueue.enqueue(i);
		intQueue.printQueue();
	}
	
	int value;
	while (!intQueue.isEmptyQueue()) {
		intQueue.dequeue(value);
		cout << value << " ";
	}

	return 0;
}
