#include "BasePlusComissionEmployee.h"
#include <iostream>
using namespace std;

BasePlusComissionEmployee::BasePlusComissionEmployee(const string& first,
	const string& last, const string& ssn,
	double sales, double rate, double salary) 
	: ComissionEmployee(first, last, ssn, sales, rate) {
	setBaseSalary(salary);
}
void BasePlusComissionEmployee::setBaseSalary(double salary) {
	baseSalary = salary;
}
double BasePlusComissionEmployee::getBaseSalary() const {
	return baseSalary;
}
double BasePlusComissionEmployee::earnings() const {
	return getBaseSalary() + ComissionEmployee::earnings();
}
void BasePlusComissionEmployee::print() const {
	cout << "base-salaried ";
	ComissionEmployee::print();
	cout << "; base salary: " << getBaseSalary();
}