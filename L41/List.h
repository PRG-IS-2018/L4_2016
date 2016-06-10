#pragma once
#include "circle.h"

class List{
	class Node{
	public:

		Node* m_Prev_p;
		Node* m_Next_p;
		Circle* m_Cir;
		Node(const Circle* = nullptr, Node* = nullptr, Node* = nullptr);
		Node(Circle&& , Node* = nullptr, Node* = nullptr);
		Node(const Node&, Node* = nullptr, Node* = nullptr);
		//Node(Node&&, Node* = nullptr, Node* = nullptr);
		~Node();
		
		//friend class List;

	};
		Node Head;
		Node Tail;
		size_t m_size;
protected:
	void AddNode(const Node&);
	Node& GetRemoveNode(Node&);
public:
	List();
	List(const List&);
	List(List&&);
	
	//Node& Find(List&, typename T );
	Node& FindMin(List&);
	void AddNode(const Circle&);
	void AddNode(Circle&&);
	void Swap(List&);
	void Sort();

	
	friend std::ostream& operator<<(std::ostream&, List&);
	~List();
};

