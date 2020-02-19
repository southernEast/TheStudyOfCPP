#ifndef _LIST_H_
#define _LIST_H_

#include "ListNode.h"
#include <iostream>

template<typename NODETYPE>
class List {
public:
	List() : firstPtr(nullptr), lastPtr(nullptr) {}
	~List() {
		if (!isEmpty()) {
			ListNode<NODETYPE>* temPtr, *currentPtr = firstPtr;
			while (currentPtr != nullptr) {
				temPtr = currentPtr;
				currentPtr = currentPtr->nextPtr;
				std::cout << temPtr->data << " ";
				delete temPtr;
			}
			std::cout << "\nAll nodes destory\n\n";
			firstPtr = lastPtr = nullptr;
		}
	}
	void insertAtFront(const NODETYPE& value) {
		ListNode<NODETYPE>* newNode = getNewNode(value);
		if (isEmpty()) {
			firstPtr = lastPtr = newNode;
		}
		else {
			newNode->nextPtr = firstPtr;
			firstPtr = newNode;
		}
	}
	void insertAtBack(const NODETYPE& value) {
		ListNode<NODETYPE>* newNode = getNewNode(value);
		if (isEmpty()) {
			firstPtr = lastPtr = newNode;
		}
		else {
			lastPtr->nextPtr = newNode;
			lastPtr = lastPtr->nextPtr;
		}
	}
	bool removeFromFront(NODETYPE& value) {
		if (isEmpty()) {
			return false;
		}
		else {
			ListNode<NODETYPE>* temPtr = firstPtr;
			if (firstPtr == lastPtr)
				firstPtr = lastPtr = nullptr;
			else
				firstPtr = firstPtr->nextPtr;
			value = temPtr->data;
			delete temPtr;
			return true;
		}
	}
	bool removeFromBack(NODETYPE& value) {
		if (isEmpty())
			return false;
		else {
			ListNode<NODETYPE>* temPtr = lastPtr;
			if (firstPtr == lastPtr)
				firstPtr = lastPtr = nullptr;
			else {
				ListNode<NODETYPE>* currentPtr = firstPtr;
				while (currentPtr->nextPtr != lastPtr)
					currentPtr = currentPtr->nextPtr;
				lastPtr = currentPtr;
				lastPtr->nextPtr = nullptr;
			}
			value = temPtr->data;
			delete temPtr;
			return true;
		}
	}
	bool isEmpty() const {
		return firstPtr == 0;
	}
	void print() const {
		if (isEmpty())
			std::cout << "This list is empty\n\n";
		else {
			ListNode<NODETYPE>* currentPtr = firstPtr;
			while (currentPtr != nullptr) {
				std::cout << currentPtr->data << " ";
				currentPtr = currentPtr->nextPtr;
			}
			std::cout << "\n\n";
		}
	}
private:
	ListNode<NODETYPE>* firstPtr;
	ListNode<NODETYPE>* lastPtr;

	ListNode<NODETYPE>* getNewNode(const NODETYPE& val) {
		return new ListNode<NODETYPE>(val);
	}
};

#endif // !_LIST_H_

