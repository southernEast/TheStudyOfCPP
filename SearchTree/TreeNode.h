#ifndef _TREENODE_H_
#define _TREENODE_H_

template<typename NODETYPE> class Tree;
template<typename NODETYPE>
class TreeNode {
	friend class Tree<NODETYPE>;
public:
	TreeNode(const NODETYPE& val)
		: leftPtr(nullptr), rightPtr(nullptr), data(val) {}
	NODETYPE getData() const{
		return data;
	}
private:
	TreeNode<NODETYPE>* leftPtr;
	TreeNode<NODETYPE>* rightPtr;
	NODETYPE data;
};

#endif // !_TREENODE_H_

