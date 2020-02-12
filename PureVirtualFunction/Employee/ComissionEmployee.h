#ifndef __COMISSIONEMPLOYEE_H__
#define __COMISSIONEMPLOYEE_H__

#include <string>
#include "Employee.h"

class ComissionEmployee : public Employee {
public:
	ComissionEmployee(const std::string& first, const std::string& last,
		const std::string& ssn, double sales = 0.0, double rate = 0.0);
	virtual ~ComissionEmployee() {}

	void setGrossSales(double sales);
	double getGrossSales() const;

	void setComissionRate(double rate);
	double getComissionRate() const;

	virtual double earnings() const override;
	virtual void print() const override;
private:
	double grossSales;
	double comissionRate;
};

#endif // !__COMISSIONEMPLOYEE_H__

