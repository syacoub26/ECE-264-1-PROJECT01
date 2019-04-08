/*
 * Name: Sara Yacoub
 * This file has the implementation of the class: Stack
 * Stack is a derived class; it is a LIFO SimpleList
 *
 */


template<typename T>
class Stack: public SimpleList<T> {
public:
	//constructor
	Stack(string n): SimpleList<T>(n) {}

	//member functions
	void push(T obj);
	T pop();
};

//push adds a value to the stack
template<typename T>
void Stack<T>::push(T obj){
	SimpleList<T>::insertStart(obj);
}

//pop removes the last value added to the stack and returns it
template<typename T>
T Stack<T>::pop(){
	return SimpleList<T>::remove();
}
