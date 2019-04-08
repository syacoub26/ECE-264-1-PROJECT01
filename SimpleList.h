/*
 * Name: Sara Yacoub
 * This file has the implementation of an abstract class: SimpleList
 * SimpleListnis a singly linked list of a collection of ordered nodes
 *
 */


template<typename T>
class SimpleList {
	//nested class for nodes
	class Node{
		//private member variables
		T data;
		Node *next = NULL;

	public:
		//constructor
		Node( T d ) : data(d) {}

		//deconstructor
		~Node() {}

		//getter functions
		T getData() const { return data; }
		Node* getNext() const { return next; }

		//setter functions
		void setNext(Node *n) { next = n; }

	};

	//member variables
	string name;
	int size = 0;
	Node *start = NULL;
	Node *end = NULL;

protected:
	//member functions
	void insertStart(T obj);
	void insertEnd(T obj);
	T remove();

public:
	//constructor
	SimpleList(string n): name(n) {}

	//member functions
	virtual void push(T obj) = 0;
	virtual T pop() = 0;
	void printList();

	//getter functions
	string getName() const { return name; }
	int getSize() const { return size; }

};

//inserting a node in the beginning of the linked list
template<typename T>
void SimpleList<T>::insertStart(T obj){
	if(size == 0){
		start = new Node(obj);
		end = start;
	}else{
		Node *tempptr = start;
		start = new Node(obj);
		start->setNext(tempptr);
	}
	size++;
}

//insering a node at the end of the linked list
template<typename T>
void SimpleList<T>::insertEnd(T obj){
	if(size == 0){
		end = new Node(obj);
		start = end;
	}else{
		end->setNext( new Node(obj) );
		end = end->getNext();
	}
	size++;
}

//removing a node from the beginning of the list
template<typename T>
T SimpleList<T>::remove(){
	if(size == 0){
		return T();
	}
	Node *tempptr = start;
	start = tempptr->getNext();
	T val = tempptr->getData();
	size--;
	delete tempptr;
	return val;
}

//printing the contents of the list
template<typename T>
void SimpleList<T>::printList(){
	Node *ptr = start;
	cout << name << ": { ";
	for(int i = 0; i < size; i++){
		cout << ptr->getData();
		ptr = ptr->getNext();
		if(i != size - 1) { cout << ", "; }
	}
	cout << "}\n";
}
