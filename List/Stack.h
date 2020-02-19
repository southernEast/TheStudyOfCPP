#ifndef _STACK_H_
#define _STACK_H_

#include "List.h"

template<typename STACKTYPE>
class Stack : private List<STACKTYPE> {
public:
	void push(const STACKTYPE& value) {
		this->insertAtFront(value);
	}
	bool pop(STACKTYPE& value) {
		return this->removeFromFront(value);
	}
	bool isEmptyStack() const{
		return this->isEmpty();
	}
	void printStakc() const {
		this->print();
	}
};

#endif // !_STACK_H_
