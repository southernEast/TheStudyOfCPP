#include <iostream> 
#include <iomanip> 
#include <fstream>
#include <string>
using namespace std;

class Person {
	friend ostream& operator<<(ostream& output, const Person& p);
public:
	Person(const string& last = "unassigned", const string& first = "",
		int ageNum = 0, int idNum = 0);

	void setId(int idNum);
	int getId() const;

	void setLastName(const string& last);
	string getLastName() const;

	void setFirstName(const string& last);
	string getFirstName() const;

	void setAge(int ageNum);
	int getAge() const;
private:
	char lastName[15];
	char firstName[10];
	int age;
	int id;
};

ostream& operator<<(ostream & output, const Person& p) {
	output << setw(5) << p.id
		<< setw(12) << p.firstName
		<< setw(17) << p.lastName
		<< setw(3) << p.age << endl;
	return output;
}

Person::Person(const string& last, const string& first, int ageNum, int idNum) {
	setLastName(last);
	setFirstName(first);
	setAge(ageNum);
	setId(idNum);
}
void Person::setId(int idNum) {
	id = idNum;
}
int Person::getId() const {
	return id;
}
void Person::setLastName(const string& last) {
	int length = last.size();
	length = (length < 15 ? length : 14);
	last.copy(lastName, length);
	lastName[length] = '\0';
}
string Person::getLastName() const {
	return lastName;
}
void Person::setFirstName(const string& first) {
	int length = first.size();
	length = (length < 10 ? length : 9);
	first.copy(firstName, length);
	firstName[length] = '\0';
}
string Person::getFirstName() const {
	return firstName;
}
void Person::setAge(int ageNum) {
	age = ageNum;
}
int Person::getAge() const {
	return age;
}

void addItem(fstream& file);
void updateItem(fstream& file);
void deleteItem(fstream& file);
void showInfo(fstream& file);

int main() {
	/*ofstream outFile("persons.dat", ios::out | ios::binary);
	if (!outFile) {
		cerr << "Cannot create persons.dat" << endl;
		exit(EXIT_FAILURE);
	}

	Person p;
	for (int i = 0; i < 100; i++) {
		outFile.write(reinterpret_cast<const char*>(&p), sizeof(p));
	}*/

	fstream file("persons.dat", ios::out | ios::in | ios::binary);

	enum Mode { ADD = 1, UPDATE, DELETE, SHOW, QUIT };

	int choice;
	bool keep = true;
	while (keep) {
		cout << "1-add\n2-update\n3-delete\n4-show\n5-quit\n";
		cin >> choice;
		switch (choice) {
		case ADD:
			addItem(file);
			break;
		case UPDATE:
			updateItem(file);
			break;
		case DELETE:
			deleteItem(file);
			break;
		case SHOW:
			showInfo(file);
			break;
		case QUIT:
			keep = false;
			break;
		default:
			cerr << "Error command!" << endl;
			break;
		}
	}

	return 0;
}

void showInfo(fstream& file) {
	Person p;
	file.seekg(0);

	while (!file.eof()) {
		file.read(reinterpret_cast<char*>(&p), sizeof(p));
		if (p.getId() != 0) {
			cout << p;
		}
	}
	file.clear();
}

void addItem(fstream& file) {
	int idNum;
	do {
		cout << "Please input an id: ";
		cin >> idNum;
	} while (!(idNum > 0 && idNum <= 100));
	
	Person p;
	file.seekg((idNum - 1) * sizeof(Person));
	file.read(reinterpret_cast<char*>(&p), sizeof(p));

	if (p.getId() != 0) {
		cout << "This id is already occupied" << endl;
	}
	else {
		string firstName;
		string lastName;
		int age;
		cout << "firstname lastname age:" << endl;
		cin >> firstName >> lastName >> age;
		p.setId(idNum);
		p.setFirstName(firstName);
		p.setLastName(lastName);
		p.setAge(age);
		file.seekp((idNum - 1) * sizeof(Person));
		file.write(reinterpret_cast<const char*>(&p), sizeof(p));
		cout << "add success" << endl;
	}
}

void updateItem(fstream& file) {
	int idNum;
	do {
		cout << "Please input an id: ";
		cin >> idNum;
	} while (!(idNum > 0 && idNum <= 100));

	Person p;
	file.seekg((idNum - 1) * sizeof(Person));
	file.read(reinterpret_cast<char*>(&p), sizeof(p));
	
	if (p.getId() == 0) {
		cout << "This id is empty." << endl;
	}
	else {
		string firstName;
		string lastName;
		int age;
		cout << "firstname lastname age:" << endl;
		cin >> firstName >> lastName >> age;
		p.setId(idNum);
		p.setFirstName(firstName);
		p.setLastName(lastName);
		p.setAge(age);
		file.seekp((idNum - 1) * sizeof(Person));
		file.write(reinterpret_cast<const char*>(&p), sizeof(p));
		cout << "update success" << endl;
	}
}

void deleteItem(fstream& file) {
	int idNum;
	do {
		cout << "Please input an id: ";
		cin >> idNum;
	} while (!(idNum > 0 && idNum <= 100));

	Person p;
	file.seekg((idNum - 1) * sizeof(Person));
	file.read(reinterpret_cast<char*>(&p), sizeof(p));

	if (p.getId() == 0) {
		cout << "This id is empty." << endl;
	}
	else {
		Person initPerson;
		file.seekp((idNum - 1) * sizeof(Person));
		file.write(reinterpret_cast<const char*>(&initPerson), sizeof(Person));
		cout << "delete success" << endl;
	}
}