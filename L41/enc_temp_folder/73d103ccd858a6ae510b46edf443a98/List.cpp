#include "List.h"

List::Node::Node(Node* prev, Node* next, const  Circle* cir){
	m_Prev_p = prev;
	m_Next_p = next;
	if (cir) {
		m_Cir = static_cast<Circle*>(malloc(sizeof(Circle)));
		new(&m_Cir)Circle(*cir);
	}
	else { m_Cir = nullptr; }
}
List::Node::Node(const Node& other) {

	m_Prev_p = nullptr;
	m_Next_p = nullptr;
	if (other.m_Cir) {
		m_Cir = static_cast<Circle*>(malloc(sizeof(Circle)));
		new(&m_Cir)Circle(*other.m_Cir);
	}
	else { m_Cir = nullptr; }
}
List::Node::~Node(){
	m_Prev_p->m_Next_p = m_Next_p;
	m_Next_p->m_Prev_p = m_Prev_p;
	delete m_Cir;
	//List::m_size--;
}

List::List():Tail(&Head),Head(){
	Head.m_Next_p = &Tail;
	m_size = 0;
}

void List::AddNode(const Node& newN) {
	Tail.m_Prev_p->m_Next_p = new Node(Tail.m_Prev_p, &Tail, newN.m_Cir);
	Tail.m_Prev_p = Tail.m_Prev_p->m_Next_p;
	m_size++;
}
void List::AddNode(const Circle& cir) {
	Tail.m_Prev_p->m_Next_p = new Node(Tail.m_Prev_p, &Tail, &cir);
	Tail.m_Prev_p = Tail.m_Prev_p->m_Next_p;
	m_size++;
}


List::List(const List& other):List(){
	m_size = other.m_size;
	Head.m_Next_p = static_cast<Node*>(malloc(sizeof(Node)*m_size));
	List::Node* curNodeSource = other.Head.m_Next_p;
	List::Node* curNodeDest = Head.m_Next_p;
	while (curNodeSource->m_Next_p != &other.Tail){
		new(&curNodeDest)Node(curNodeDest->m_Prev_p, &Tail, curNodeSource->m_Cir);
		curNodeSource = curNodeSource->m_Next_p;
		curNodeDest = curNodeDest->m_Next_p;
	}
	Tail.m_Prev_p = curNodeDest;
}

std::ostream& operator<<(std::ostream& os, List& l) {
	List::Node* curN = l.Head.m_Next_p;
	while (curN != &l.Tail) {
		os << curN->m_Cir << std::endl;
		curN = curN->m_Next_p;
	}
	return os;
}

List::~List(){
	while (Head.m_Next_p != &Tail){
		Tail.m_Prev_p->~Node();
	}
	// delete Head,Tail ???
}
