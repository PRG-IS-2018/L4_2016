#include "List.h"

List::Node::Node(const  Circle* cir, Node* prev, Node* next):m_Cir(*cir){
	m_Prev_p = prev;
	m_Next_p = next;		
	if (m_Next_p) {
		prev->m_Next_p = this;
	}
	if (m_Prev_p) {
		next->m_Prev_p = this;
	}
}


List::Node::Node( Circle&& cir, Node* prev, Node* next):m_Cir(std::move(cir)) {
	m_Prev_p = prev;
	m_Next_p = next;
	if (m_Next_p) {
		prev->m_Next_p = this;
	}
	if (m_Prev_p) {
		next->m_Prev_p = this;
	}
}

List::Node::Node(const Node& other, Node* prev, Node* next):m_Cir(other.m_Cir) {
	m_Prev_p = prev;
	m_Next_p = next;
	if (m_Next_p) {
		prev->m_Next_p = this;
	}
	if (m_Prev_p) {
		next->m_Prev_p = this;
	}
}
List::Node::~Node(){         
	//if (this) {
		if (m_Prev_p) {
			m_Prev_p->m_Next_p = m_Next_p;
		}
		if (m_Next_p) {
			m_Next_p->m_Prev_p = m_Prev_p;
		}
	//}
	//List::m_size--;
}

List::List():Tail(),Head(){
	Tail.m_Prev_p = &Head;
	Head.m_Next_p = &Tail;
	m_size = 0; 
}

void List::AddNodeT(Node& ExistingNode) {
	ExistingNode.m_Prev_p = Tail.m_Prev_p;
	Tail.m_Prev_p->m_Next_p = &ExistingNode;
	ExistingNode.m_Next_p = &Tail;
	Tail.m_Prev_p = Tail.m_Prev_p->m_Next_p;
	m_size++;
}
void List::AddNodeH(Node& ExistingNode) {
	ExistingNode.m_Prev_p = &Head;
	ExistingNode.m_Next_p = Head.m_Next_p;
	Head.m_Next_p->m_Prev_p = &ExistingNode;
	Head.m_Next_p= &ExistingNode;
	m_size++;
}
void List::AddToTail(const Circle& cir) {
	new Node(&cir,Tail.m_Prev_p, &Tail);
	m_size++;
}
void List::AddToTail(Circle&& cir) {
	new Node(static_cast<Circle&&>(cir), Tail.m_Prev_p, &Tail); ///без статик_каста не хочет...??
	m_size++;
}
void List::AddToHead(const Circle& cir) {
	new Node(&cir, &Head, Head.m_Next_p);
	m_size++;
}
void List::AddToHead(Circle&& cir) {
	new Node(static_cast<Circle&&>(cir), &Head, Head.m_Next_p); ///без статик_каста не хочет...??
	m_size++;
}

List::List(const List& other){
	Tail.m_Prev_p = &Head;
	Head.m_Next_p = &Tail;
	
	List::Node* curNodeSource = other.Head.m_Next_p;
		//m_size = other.m_size;
		//Head.m_Next_p = static_cast<Node*>(malloc(sizeof(Node)*m_size));
		//List::Node* curNodeDest = Head.m_Next_p;
		//curNodeDest->m_Prev_p = &Head;
	while (curNodeSource != &other.Tail){
		new Node(*curNodeSource, Tail.m_Prev_p, &Tail);
		m_size++;
		curNodeSource = curNodeSource->m_Next_p;
			//curNodeDest = new Node(*curNodeSource, curNodeDest->m_Prev_p, &Tail);
			//curNodeDest = curNodeDest->m_Next_p;
	}
		// Tail.m_Prev_p = curNodeDest->m_Prev_p;
}

List::List(List&& other) {
	m_size = other.m_size;

	Head.m_Next_p = other.Head.m_Next_p;
	Head.m_Next_p->m_Prev_p = &Head;
	other.Head.m_Next_p = &other.Tail;

	Tail.m_Prev_p = other.Tail.m_Prev_p;
	Tail.m_Prev_p->m_Next_p = &Tail;
	other.Tail.m_Prev_p = &other.Head;
}



void List::Swap(List& other) {
	//List tmp(*this);

	Node* tmpH = Head.m_Next_p;
	Node* tmpT = Tail.m_Prev_p;

	if (other.Head.m_Next_p != &other.Tail) {
		Head.m_Next_p = other.Head.m_Next_p;
		Head.m_Next_p->m_Prev_p = &Head;
		Tail.m_Prev_p = other.Tail.m_Prev_p;
		Tail.m_Prev_p->m_Next_p = &Tail;
	}
	else {
		Head.m_Next_p = &Tail;
		Tail.m_Prev_p = &Head;
	}

	if ((tmpH != &Tail)||(tmpT != &Head)) {
		other.Head.m_Next_p = tmpH;
		other.Head.m_Next_p->m_Prev_p = &other.Head;
		other.Tail.m_Prev_p = tmpT;
		other.Tail.m_Prev_p->m_Next_p = &other.Tail;
	}
	else {
		other.Head.m_Next_p = &other.Tail;
		other.Tail.m_Prev_p = &other.Head;
	}
	m_size ^= other.m_size;
	other.m_size ^= m_size;
	m_size ^= other.m_size;

	//////////////////как написать Ёффективнее?....
}


List::Node& List::FindMin(List&) {
	Node* MinNode = Head.m_Next_p;
	Node* RunningNode = MinNode;
	while (RunningNode != &Tail){
		if (RunningNode->m_Cir.GetArea() < MinNode->m_Cir.GetArea()) {
			MinNode = RunningNode;
		}
		RunningNode = RunningNode->m_Next_p;
	}
	return *MinNode;
}

void List::Sort() {
	List tmp;
	while (Head.m_Next_p != &Tail){
		tmp.AddNodeT(GetRemoveNode(FindMin(*this)));
	}
	Swap(tmp);
}

List::Node& List::GetRemoveNode(Node& del) {
	//if (&del) {
		if (del.m_Prev_p) {
			del.m_Prev_p->m_Next_p = del.m_Next_p;
		}
		if (del.m_Next_p) {
			del.m_Next_p->m_Prev_p = del.m_Prev_p;
		}
		del.m_Prev_p = nullptr;
		del.m_Next_p = nullptr;
		m_size--;
	//}
	return del;
}
void List::RemoveFirst() {
	if (Head.m_Next_p != &Tail) {
		delete Head.m_Next_p;
		m_size--;
	}
}
void List::RemoveLast() {
	if (Tail.m_Prev_p != &Head) {
		delete Tail.m_Prev_p;
		m_size--;
	}
}

bool List::FindRemoveCir(const Circle & cir){
	List::Node* curN = Head.m_Next_p;
	while (curN != &Tail) {
		if (curN->m_Cir == cir) {
			delete curN;
			m_size--;
			return true;
		}
		curN = curN->m_Next_p;
	}
	return false;
}


uint32_t List::FindRemoveAllCir(const Circle & cir) {
	uint32_t counter=0;
	List::Node* curN = Head.m_Next_p;
	while (curN != &Tail) {
		if (curN->m_Cir == cir) {
			delete curN;
			m_size--;
			counter++;
		}
		curN = curN->m_Next_p;
	}
	return counter;
}
List& List::operator=(const List& other) {
	List::Node* curDest = Head.m_Next_p;
	List::Node* curSorce= other.Head.m_Next_p;
	while (curDest->m_Next_p && curSorce->m_Next_p){
		curDest->m_Cir = curSorce->m_Cir;
		curDest = curDest->m_Next_p;
		curSorce = curSorce->m_Next_p;
	}
	if (curDest !=&Tail) {
		curDest = curDest->m_Prev_p;
		while (curDest->m_Next_p!= &Tail) {
			RemoveLast();
		}
	}
	else {
		while (curSorce != &other.Tail){
			new Node(*curSorce, Tail.m_Prev_p, &Tail);
			curSorce = curSorce->m_Next_p;
		}
	}
	return *this;
}
std::ostream& operator<<(std::ostream& os, List& l) {          
	List::Node* curN = l.Head.m_Next_p;
	while (curN != &l.Tail) {
		os << curN->m_Cir << std::endl;
		curN = curN->m_Next_p;
	}
	return os;
}
std::ofstream& operator<<(std::ofstream& os, List&l) {
	List::Node* curN = l.Head.m_Next_p;
	while (curN != &l.Tail) {
		os << curN->m_Cir << std::endl;
		curN = curN->m_Next_p;
	}
	return os;
}

List::~List(){
	while (Head.m_Next_p != &Tail){
		delete Tail.m_Prev_p;
		m_size--;
	}
// delete Head,Tail ???
}
