#pragma once

// this is a forward declaration of class List.  It is required to announce
// that class List exists so it can be used in the friend declaration.
template<typename NODETYPE> class List;

template<typename NODETYPE>
class ListNode {
	friend class List<NODETYPE>; // make the list class a friend

public:
	// CONSTRUCTOR
	explicit ListNode(const NODETYPE& info)
		: data{ info }, nextPtr{ nullptr } {}

	NODETYPE data; // for data
	ListNode<NODETYPE>* nextPtr; // next node in the list
};