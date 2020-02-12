#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>

class Employee {
public:
	Employee(const std::string& first, const std::string& last,
		const std::string& ssn);
	virtual ~Employee() {}
	
	void setFirstName(const std::string& first);
	std::string getFirstName() const;

	void setLastName(const std::string& last);
	std::string getLastName() const;

	void setSocialSecurityNumber(const std::string& ssn);
	std::string getSocialSecurityNumber() const;

	virtual double earnings() const = 0;
	virtual void print() const;
private:
	std::string firstName;
	std::string lastName;
	std::string socialSecurityNumber;
};

#endif // !__EMPLOYEE_H__