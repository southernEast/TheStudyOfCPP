#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "List.h"

template<typename QUEUETYPE>
class Queue : private List<QUEUETYPE> {
public:
	void enqueue(const QUEUETYPE& value) {
		this->insertAtBack(value);
	}
	bool dequeue(QUEUETYPE& value) {
		return this->removeFromFront(value);
	}
	bool isEmptyQueue() const {
		return this->isEmpty();
	}
	void printQueue() const {
		this->print();
	}
};

#endif // !_QUEUE_H_