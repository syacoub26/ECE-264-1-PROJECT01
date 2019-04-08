/*
 * Name: Sara Yacoub
 * This file holds some template functions to help the program
 * process lists and SimpleLists of different types
 *
 */


/*//this function returns a pointer to the list holding pointers of SimpleLists depending on the type
template<typename T>
list<SimpleList<T>*>* findList(string n){
	if(n.at(0) == 'i'){
		return &intLi;
	}else if(n.at(0) == 'd'){
		return &douLi;
	}else if(n.at(0) == 's'){
		return &strLi;
	}
}*/

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

/*//this function returns a pointer to the SimpleList of the given name
template<typename T>
SimpleList<T>* findSimpleList(string n){
	list<SimpleList<T> *> *l = findList(n);

	for(auto const& i: *l){
		if( i->getName().compare(n) == 0 ){
			return i;
		}
	}
}*/

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

//this function pushes values into stacks and queues
template<typename T>
void listPush( list<SimpleList<T>*> *li, string n, string v){
	
	SimpleList<T> *l;
	for(auto const& i: *li){
		if( i->getName().compare(n) == 0 ){
			l = i;
		}
	}

	if(n.at(0) == 'i'){
		l->push( stoi(v) );
	}else if(n.at(0) == 'd'){
		l->push( stod(v) );
	}else if(n.at(0) == 's'){
		l->push( v );
	}
}

//this function determines if a SimpleList is empty
template<typename T>
bool isEmpty( list<SimpleList<T>*> *li, string n){
	SimpleList<T> *l;
	for(auto const& i: *li){
		if( i->getName().compare(n) == 0 ){
			l = i;
		}
	}
	return (l->getSize() == 0 );
}

//this function pops values from stacks and queues
template<typename T>
string listPop( list<SimpleList<T>*> *li, string n){
	SimpleList<T> *l;
	for(auto const& i: *li){
		if( i->getName.compare(n) == 0 ){
			l = i;
		}
	}
	return l->pop();
}
