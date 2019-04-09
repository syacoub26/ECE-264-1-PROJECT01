/*
 * Name: Sara Yacoub
 * This file holds some template functions to help the program
 * process lists and SimpleLists of different types
 *
 */


//this functtion determines if a name already exists
template<typename T>
bool isUnique( list<SimpleList<T>*> *l, string n){
	bool uni = true;
	for(auto const& i: *l){
		if( i->getName().compare(n) == 0 ){
			uni = false;
		}
	}
	return uni;
}

//this function creates a new SimpleList
template<typename T>
void addList( list<SimpleList<T>*> *l, string n, string t){
	if( !t.compare("stack") ){
		SimpleList<T> *temp = new Stack<T>(n);
		l->push_front(temp);
	}else if( !t.compare("queue") ){
		SimpleList<T> *temp = new Queue<T>(n);
		l->push_front(temp);
	}
}

//this functions searches for a SimpleList pointer in a list
template<typename T>
SimpleList<T>* search( list<SimpleList<T>*> *l, string n){
	for(auto const& i: *l){
		if( i->getName().compare(n) == 0 ){
			return i;
		}
	}
}

//this function determines if a SimpleList is empty
template<typename T>
bool isEmpty( list<SimpleList<T>*> *l, string n){
	return ( search<T>(l, n)->getSize() == 0 );
}

//this function pops values from stacks and queues
template<typename T>
T listPop( list<SimpleList<T>*> *l, string n){
	return search<T>(l, n)->pop();
}
