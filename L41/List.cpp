#include "List.h"

List::Node::Node(const  Circle* cir, Node* prev, Node* next){
	m_Prev_p = prev;
	m_Next_p = next;
	if (cir) {
		m_Cir = static_cast<Circle*>(malloc(sizeof(Circle)));
		new(m_Cir)Circle(const_cast<Circle&>(*cir));
	}
	else { m_Cir = nullptr; }
}

List::Node::Node( Circle&& cir, Node* prev, Node* next) {
	m_Prev_p = prev;
	m_Next_p = next;
	m_Cir = new Circle(std::move(cir));
}

List::Node::Node(const Node& other, Node* prev, Node* next) {

	m_Prev_p = prev;
	m_Next_p = next;
	if (other.m_Cir) {
		m_Cir = static_cast<Circle*>(malloc(sizeof(Circle)));
		new(m_Cir)Circle(*other.m_Cir);
	}
	else { m_Cir = nullptr; }
}
List::Node::~Node(){             
 	if (m_Prev_p) {
		m_Prev_p->m_Next_p = m_Next_p;
	}
	if (m_Next_p){ 
		m_Next_p->m_Prev_p = m_Prev_p;
	}
	delete m_Cir;

	//List::m_size--;
}

List::List():Tail(),Head(){
	Tail.m_Prev_p = &Head;
	Head.m_Next_p = &Tail;
	m_size = 0; 
}

void List::AddNode(const Node& newN) {
	Tail.m_Prev_p->m_Next_p = new Node(newN, Tail.m_Prev_p, &Tail);
	Tail.m_Prev_p = Tail.m_Prev_p->m_Next_p;
	m_size++;
}
void List::AddNode(const Circle& cir) {
	Tail.m_Prev_p->m_Next_p = new Node(&cir,Tail.m_Prev_p, &Tail);
	Tail.m_Prev_p = Tail.m_Prev_p->m_Next_p;
	m_size++;
}
void List::AddNode(Circle&& cir) {
	Tail.m_Prev_p->m_Next_p = new Node(static_cast<Circle&&>(cir), Tail.m_Prev_p, &Tail); ///без статик_каста не хочет...??
	Tail.m_Prev_p = Tail.m_Prev_p->m_Next_p;
	m_size++;
}

List::List(const List& other){
	Tail.m_Prev_p = &Head;
	Head.m_Next_p = &Tail;
	m_size = other.m_size;
	List::Node* curNodeSource = other.Head.m_Next_p;
		//Head.m_Next_p = static_cast<Node*>(malloc(sizeof(Node)*m_size));
		//List::Node* curNodeDest = Head.m_Next_p;
		//curNodeDest->m_Prev_p = &Head;
	while (curNodeSource != &other.Tail){
		AddNode(*curNodeSource);
		curNodeSource = curNodeSource->m_Next_p;
			//curNodeDest = new Node(*curNodeSource, curNodeDest->m_Prev_p, &Tail);
			//curNodeDest = curNodeDest->m_Next_p;
	}
		// Tail.m_Prev_p = curNodeDest->m_Prev_p;
}

List::List(List&& other) {
	m_size = other.m_size;
	Head.m_Next_p = other.Head.m_Next_p;
	other.Head.m_Next_p = nullptr;
	Tail.m_Prev_p = other.Tail.m_Prev_p;
	other.Tail.m_Prev_p = nullptr;
}

List::Node* List::GetRemoveNode(Node& del) {
	if (del.m_Prev_p) {
		del.m_Prev_p->m_Next_p = del.m_Next_p;

	}
	if (del.m_Next_p) {
		del.m_Next_p->m_Prev_p = del.m_Prev_p;
	}
	del.m_Prev_p = nullptr;
	del.m_Next_p = nullptr;
	m_size--;
	return &del;
}

std::ostream& operator<<(std::ostream& os, List& l) {          
	List::Node* curN = l.Head.m_Next_p;
	while (curN != &l.Tail) {
		if (curN->m_Cir) {
			os << *curN->m_Cir << std::endl;
		}
		curN = curN->m_Next_p;
	}
	return os;
}

List::~List(){
	while (Head.m_Next_p != &Tail){
		Tail.m_Prev_p->~Node();
		m_size--;
	}
	// delete Head,Tail ???
}
