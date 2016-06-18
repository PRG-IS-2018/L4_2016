#pragma once
#include "circle.h"
#include <fstream>

class List{
	class Node{
	public:

		Node* m_Prev_p;
		Node* m_Next_p;
		Circle m_Cir;
		Node():m_Cir(),m_Next_p(nullptr), m_Prev_p(nullptr) {}
		Node(const Circle*, Node* = nullptr, Node* = nullptr);
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
	void AddNodeT(Node&);
	void AddNodeH(Node&);
	Node& GetRemoveNode(Node&);
public:
	List();
	List(const List&);
	List(List&&);
	~List();

	//Node& Find(List&, typename T );
	Node& FindMin();
	void AddToTail(const Circle&);
	void AddToTail(Circle&&);
	void AddToHead(const Circle&);
	void AddToHead(Circle&&);
	void RemoveFirst();
	void RemoveLast();
	bool FindRemoveCir(const Circle&);
	uint32_t FindRemoveAllCir(const Circle&);
	void Swap(List&);
	List& operator=(const List&);
	void Sort();

	
	friend std::ostream& operator<<(std::ostream&, const List&);
	//friend std::ofstream& operator<<(std::ofstream&, const List&);
	friend std::ifstream& operator>>(std::ifstream&, List&);

};

