#pragma once
#include "circle.h"

class List{
	class Node{
	public:

		Node* m_Prev_p;
		Node* m_Next_p;
		Circle* m_Cir;
		Node(Node* = nullptr, Node* = nullptr, const Circle* = nullptr);
		Node(const Node&);
		~Node();

		//friend class List;

	};
		Node Head;
		Node Tail;
		size_t m_size;

public:
	List();
	List(const List&);
	void AddNode(const Node&);
	void AddNode(const Circle&);

	friend std::ostream& operator<<(std::ostream&, List&);
	~List();
};

