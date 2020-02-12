#include "ComissionEmployee.h"
#include <iostream>
using namespace std;

ComissionEmployee::ComissionEmployee(const string& first, const string& last,
	const string& ssn, double sales, double rate) : Employee(first, last, ssn) {
	setGrossSales(sales);
	setComissionRate(rate);
}
void ComissionEmployee::setGrossSales(double sales) {
	grossSales = sales;
}
double ComissionEmployee::getGrossSales() const {
	return grossSales;
}
void ComissionEmployee::setComissionRate(double rate) {
	comissionRate = rate;
}
double ComissionEmployee::getComissionRate() const {
	return comissionRate;
}
double ComissionEmployee::earnings() const {
	return getComissionRate() * getGrossSales();
}
void ComissionEmployee::print() const {
	cout << "comission employee: ";
	Employee::print();
	cout << "\ngross sales: " << getGrossSales()
		<< "; comission rate: " << getComissionRate();
}
