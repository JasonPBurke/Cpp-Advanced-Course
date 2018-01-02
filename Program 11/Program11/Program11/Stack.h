#ifndef STACK_H
#define STACK_H
#include <vector>

// DEFINE A CLASS TEMPLATE CALLED 'STACK' IN THE HEADER FILE
template<typename T>
class Stack {
public:
	//push an element onto the Stack
	void push( const T& pushValue ) {
		elements.insert(elements.begin(), pushValue);
	}
	//pop an element from the Stack
	void pop() {
		elements.erase( elements.begin() );
	}
	// return the top element of the Stack
	const T& top() {
		return elements.front();
	}
	//determine whether the Stack is empty
	bool isEmpty() const {
		return elements.empty();
	}
	//clear the Stack of all elements
	void clear() {
		elements.clear();
	}
	void size() {
		elements.size();
	}
	void fill(const T& val) {
		elements.push_back(val);
	}
private:	
	std::vector<T> elements;// create a class vector called 'elements'
};
#endif // !STACK_H