/*
 * Name: Sara Yacoub
 * This file has the implementation of the class: Queue
 * Queue is a derived class; it is a FIFO SimpleList
 * 
 */


template<typename T>
class Queue : public SimpleList<T> {
public:
	//constructor
	Queue(string n): SimpleList<T>(n) {}

	//member functions
	void push(T obj);
	T pop();
};

//push adds a value to the queue
template<typename T>
void Queue<T>::push(T obj){
	SimpleList<T>::insertEnd(obj);
}

//pop removes the first value added to the queue
template<typename T>
T Queue<T>::pop(){
	return SimpleList<T>::remove();
}
