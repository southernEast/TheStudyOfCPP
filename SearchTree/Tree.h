#ifndef _TREE_H_
#define _TREE_H_

#include "TreeNode.h"
#include <queue>
#include <iostream>
#include <iomanip>

template<typename NODETYPE>
class Tree {
public:
	Tree() : rootPtr(nullptr) {}
	void insertNode(const NODETYPE& value);		// 插入结点
	void preOrder() const;						// 前序遍历
	void inOrder() const;						// 中序遍历
	void postOrder() const;						// 后序遍历
	void levelOrder() const;					// 层次遍历
	int getDeepth();							// 树的深度
	void deleteNode(const NODETYPE& value);		// 删除结点

private:
	TreeNode<NODETYPE>* findMin(TreeNode<NODETYPE>* ptr);	// 查找直接后继
	TreeNode<NODETYPE>* deleteNodeHelper(TreeNode<NODETYPE>* ptr, const NODETYPE& value);	// 递归删除结点
	void insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value);
	void preOrderHelper(TreeNode<NODETYPE>* ptr) const;
	void inOrderHelper(TreeNode<NODETYPE>* ptr) const;
	void postOrderHelper(TreeNode<NODETYPE>* ptr) const;
	void travelTree(TreeNode<NODETYPE>* ptr, int& deepth, int& maxiumDeepth);
	TreeNode<NODETYPE>* rootPtr;
};

template<typename NODETYPE>
void Tree<NODETYPE>::insertNode(const NODETYPE& value) {
	insertNodeHelper(&rootPtr, value);
}
template<typename NODETYPE>
void Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value) {
	if (*ptr == nullptr)
		*ptr = new TreeNode<NODETYPE>(value);
	else if ((*ptr)->data < value)
		insertNodeHelper(&(*ptr)->rightPtr, value);
	else if ((*ptr)->data > value)
		insertNodeHelper(&(*ptr)->leftPtr, value);
	else
		std::cout << "Dup" << std::endl;
}
template<typename NODETYPE>
void Tree<NODETYPE>::preOrder() const {
	preOrderHelper(rootPtr);
}
template<typename NODETYPE>
void Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE>* ptr) const {
	if (ptr != nullptr) {
		std::cout << ptr->data << " ";
		preOrderHelper(ptr->leftPtr);
		preOrderHelper(ptr->rightPtr);
	}
}
template<typename NODETYPE>
void Tree<NODETYPE>::inOrder() const {
	inOrderHelper(rootPtr);
}
template<typename NODETYPE>
void Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE>* ptr) const {
	if (ptr != nullptr) {
		inOrderHelper(ptr->leftPtr);
		std::cout << ptr->data << " ";
		inOrderHelper(ptr->rightPtr);
	}
}
template<typename NODETYPE>
void Tree<NODETYPE>::postOrder() const {
	postOrderHelper(rootPtr);
}
template<typename NODETYPE>
void Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE>* ptr) const {
	if (ptr != nullptr) {
		postOrderHelper(ptr->leftPtr);
		postOrderHelper(ptr->rightPtr);
		std::cout << ptr->data << " ";
	}
}
template<typename NODETYPE>
void Tree<NODETYPE>::levelOrder() const {
	std::queue<TreeNode<NODETYPE>*> treePtrQueue;
	treePtrQueue.push(rootPtr);
	TreeNode<NODETYPE>* temp;
	while (!treePtrQueue.empty()) {
		temp = treePtrQueue.front();
		treePtrQueue.pop();
		std::cout << temp->data << " ";
		if (temp->leftPtr)
			treePtrQueue.push(temp->leftPtr);
		if (temp->rightPtr)
			treePtrQueue.push(temp->rightPtr);
	}
}
template<typename NODETYPE>
void Tree<NODETYPE>::deleteNode(const NODETYPE& value) {
	rootPtr = deleteNodeHelper(rootPtr, value);
}
template<typename NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::deleteNodeHelper(TreeNode<NODETYPE>* ptr, const NODETYPE& value) {
	if (!ptr)
		std::cout << "Not Found" << std::endl;
	else if (value < ptr->data)
		ptr->leftPtr = deleteNodeHelper(ptr->leftPtr, value);
	else if (value > ptr->data)
		ptr->rightPtr = deleteNodeHelper(ptr->rightPtr, value);
	else {
		TreeNode<NODETYPE>* tempPtr, *minPtr;
		if (ptr->leftPtr && ptr->rightPtr) {
			minPtr = findMin(ptr->rightPtr);
			ptr->data = minPtr->data;
			ptr->rightPtr = deleteNodeHelper(ptr->rightPtr, minPtr->data);
		}
		else {
			tempPtr = ptr;
			if (ptr->rightPtr)
				ptr = ptr->rightPtr;
			else
				ptr = ptr->leftPtr;
			delete tempPtr;
		}
	}
	return ptr;
}
template<typename NODETYPE>
TreeNode<NODETYPE>* Tree<NODETYPE>::findMin(TreeNode<NODETYPE>* ptr) {
	while (ptr->leftPtr)
		ptr = ptr->leftPtr;
	return ptr;
}
template<typename NODETYPE>
int Tree<NODETYPE>::getDeepth() {
	int deepth = 0, maxmiumDeepth = 0;
	this->travelTree(rootPtr, deepth, maxmiumDeepth);
	return maxmiumDeepth;
};
template<typename NODETYPE>
void Tree<NODETYPE>::travelTree(TreeNode<NODETYPE>* ptr, int& deepth, int& maxiumDeepth) {
	if (ptr) {
		++deepth;
		if (deepth > maxiumDeepth)
			maxiumDeepth = deepth;
		travelTree(ptr->leftPtr, deepth, maxiumDeepth);
		travelTree(ptr->rightPtr, deepth, maxiumDeepth);
		--deepth;
	}
}

#endif // !_TREE_H_