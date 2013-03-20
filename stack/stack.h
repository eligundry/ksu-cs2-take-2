/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  Header file for the stack class
 *
 *        Version:  1.0
 *        Created:  03/18/2013 02:30:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#ifndef ELIGUNDRY_STACK_H_
#define ELIGUNDRY_STACK_H_

#include "node.h"

template <typename T>
class Stack {
public:
	/*
	 * Default constructor for stack with no data
	 * Ex: Stack<int> empty_stack;
	 */
	Stack(void);

	/*
	 * Stack's copy constructor
	 * Ex: Stack<int> new_stack(old_stack);
	 */
	Stack(const Stack<T>&);

	/*
	 * Destructor for stack
	 */
	~Stack(void);

	/*
	 * Assignment operator for stack
	 * Ex: Stack<int> new_stack = copy_stack;
	 */
	Stack<T>& operator = (Stack<T>);

	/*
	 * Equality operator for stack
	 * Ex: new_stack == copy_stack;
	 * Ex: new_stack != copy_stack;
	 */
	bool operator == (const Stack<T>&) const;
	bool operator != (const Stack<T>& rhs) const { return !(*this == rhs); };

	/*
	 * Returns the length of the stack
	 * Ex: example_stack.getLength();
	 */
	int getLength(void) const { return length; };

	/*
	 * Determines if the current stack is empty
	 * Ex: empty_stack.isEmpty();
	 */
	bool isEmpty(void) const { return tos == 0; };

	/*
	 * Determines of the current stack is full
	 * Ex: full_stack.isFull();
	 */
	bool isFull(void) const;

	/*
	 * Pops the last item off of the stack
	 * Ex: example_stack.pop();
	 */
	T pop(void);

	/*
	 * Pushes an item to the top of the stack
	 * Ex: example_stack.push(1);
	 */
	void push(const T&);

	/*
	 * Constant time swap for stack
	 * Ex: example_stack.swap(copy_stack);
	 */
	void swap(Stack<T>&);

	/*
	 * Returns the top element of the stack
	 * Ex: example_stack.top();
	 */
	T top(void) const { return tos->data; };

private:
	// Pointer to top of stack
	Node<T> *tos;

	// Number of items in the stack
	int length;
};

/*
 * Default constructor for stack with no data
 * Ex: Stack<int> empty_stack;
 */
template <typename T>
Stack<T>::Stack()
{
	tos = 0;
	length = 0;
}

/*
 * Stack's copy constructor
 * Ex: Stack<int> new_stack(old_stack);
 */
template <typename T>
Stack<T>::Stack(const Stack<T>& actual)
{
	Node<T> *bottom, *temptos, *tempNode;

	temptos = actual.tos;

	tos = 0;
	length = actual.length;

	while (temptos != 0) {
		tempNode = new Node<T>(temptos->data);

		if (tos == 0) {
			tos = tempNode;
		} else {
			bottom->next = tempNode;
		}

		bottom = tempNode;
		temptos = temptos->next;
	}
}

/*
 * Destructor for stack
 */
template <typename T>
Stack<T>::~Stack()
{
	while (tos != 0) {
		Node<T> *temp = tos;
		tos = tos->next;
		delete temp;
	}

	length = 0;
}

/*
 * Assignment operator for stack
 * Ex: Stack<int> new_stack = copy_stack;
 */
template <typename T>
Stack<T>& Stack<T>::operator = (Stack<T> rhs)
{
	swap(rhs);
	return *this;
}

/*
 * Equality operator for stack
 * Ex: new_stack == copy_stack;
 */
template <typename T>
bool Stack<T>::operator == (const Stack<T>& rhs) const
{
	if (length != rhs.length) {
		return false;
	}

	Stack<T> l(*this), r(rhs);

	while (!l.isEmpty() && !r.isEmpty()) {
		if (l.pop() != r.pop()) {
			return false;
		}
	}

	return true;
}

/*
 * Outputs all the elements of the Stack
 * Ex: out << example_stack;
 */
template <typename T>
std::ostream& operator << (std::ostream& out, const Stack<T>& rhs)
{
	for (Stack<T> temp(rhs); !temp.isEmpty();) {
		out << '[' << temp.pop() << "] ";
	}

	return out;
}

/*
 * Determines of the current stack is full
 * Ex: full_stack.isFull();
 */
template <typename T>
bool Stack<T>::isFull() const
{
	// Try to create a new node in memory
	Node<T> *temp = new(std::nothrow) Node<T> ();

	// If we can't do that, we are out of memory
	if (temp == 0) {
		return true;
	}

	delete temp;
	return false;
}

/*
 * Pops the last item off of the stack
 * Ex: example_stack.pop();
 */
template <typename T>
T Stack<T>::pop()
{
	// If stack is empty, do nothing
	assert(tos != 0);

	// Copy the pointer of the top element of the stack into a temp var
	Node<T> *temp = tos;

	// Set tos's contents into the result variable
	T result = tos->data;

	tos = tos->next;
	--length;

	// Delete the element we just copied from the stack and return
	delete temp;
	return result;
}

/*
 * Pushes an item to the top of the stack
 * Ex: example_stack.push(1);
 */
template <typename T>
void Stack<T>::push(const T& item)
{
	// If stack is full, do nothing
	assert(!isFull());

	// Create temporary node with passed in data
	Node<T> *temp = new Node<T>(item);

	// Take existing data and append it to temp
	temp->next = tos;

	// Set tos to our temp, essentially copying it
	tos = temp;
	++length;
}

/*
 * Constant time swap for stack
 * Ex: example_stack.swap(copy_stack);
 */
template <typename T>
void Stack<T>::swap(Stack<T>& rhs)
{
	// Create temp node and copy tos into it
	Node<T> *temp = tos;
	int tempLength = length;

	// Set tos to what you passed in
	tos = rhs.tos;
	length = rhs.length;

	// Set what you passed in to temp
	rhs.tos = temp;
	rhs.length = tempLength;
}

#endif
