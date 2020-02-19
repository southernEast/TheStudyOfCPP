#ifndef _LISTNODE_H_
#define _LISTNODE_H_

template<typename NODETYPE> class List;
template<typename NODETYPE>
class ListNode {
	friend class List<NODETYPE>;
public:
	explicit ListNode(const NODETYPE& val)
		: data(val), nextPtr(nullptr) {}
	NODETYPE getData() const {
		return data;
	}
private:
	NODETYPE data;
	ListNode<NODETYPE>* nextPtr;
};

#endif // !_LISTNODE_H_
