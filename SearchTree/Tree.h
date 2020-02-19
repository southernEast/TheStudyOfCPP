#ifndef _TREE_H_
#define _TREE_H_

#include "TreeNode.h"
#include <iostream>

template<typename NODETYPE>
class Tree {
public:
	Tree() : rootPtr(nullptr) {}
	void insertNode(const NODETYPE& value) {
		insertNodeHelper(&rootPtr, value);
	}
	void preOrder() const {
		preOrderHelper(rootPtr);
	}
	void inOrder() const {
		inOrderHelper(rootPtr);
	}
	void postOrder() const {
		postOrderHelper(rootPtr);
	}
private:
	void insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
		if (*ptr == nullptr)
			*ptr = new TreeNode<NODETYPE>(value);
		else if ((*ptr)->data < value)
			insertNodeHelper(&(*ptr)->rightPtr, value);
		else if ((*ptr)->data > value)
			insertNodeHelper(&(*ptr)->leftPtr, value);
		else
			std::cout << "Dup" << std::endl;
	}
	void preOrderHelper(TreeNode<NODETYPE>* ptr) const {
		if (ptr != nullptr) {
			std::cout << ptr->data << " ";
			preOrderHelper(ptr->leftPtr);
			preOrderHelper(ptr->rightPtr);
		}
	}
	void inOrderHelper(TreeNode<NODETYPE>* ptr) const {
		if (ptr != nullptr) {
			inOrderHelper(ptr->leftPtr);
			std::cout << ptr->data << " ";
			inOrderHelper(ptr->rightPtr);
		}
	}
	void postOrderHelper(TreeNode<NODETYPE>* ptr) const {
		if (ptr != nullptr) {
			postOrderHelper(ptr->leftPtr);
			postOrderHelper(ptr->rightPtr);
			std::cout << ptr->data << " ";
		}
	}
	TreeNode<NODETYPE>* rootPtr;
};

#endif // !_TREE_H_

