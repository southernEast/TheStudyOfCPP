#include "ClientData.h"
#include <string>
using namespace std;

ClientData::ClientData(int accountNumberVal, const string& lastName,
	const string& firstName, double balanceVal)
	: accountNumber(accountNumberVal), balance(balanceVal) {
	setLastName(lastName);
	setFirstName(firstName);
}
void ClientData::setAccountNumber(int accountNumberVal) {
	accountNumber = accountNumberVal;
}
int ClientData::getAccountNumber() const {
	return accountNumber;
}
void ClientData::setLastName(const string& lastNameStr) {
	int length = lastNameStr.size();
	length = (length < 15 ? length : 14);
	lastNameStr.copy(lastName, length);
	lastName[length] = '\0';
}
string ClientData::getLastName() const {
	return lastName;
}
void ClientData::setFirstName(const string& firstNameStr) {
	int length = firstNameStr.size();
	length = (length < 10 ? length : 9);
	firstNameStr.copy(firstName, length);
	firstName[length] = '\0';
}
string ClientData::getFirstName() const {
	return firstName;
}
void ClientData::setBalance(double balanceVal) {
	balance = balanceVal;
}
double ClientData::getBalance() const {
	return balance;
}