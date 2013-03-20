/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  Header file for the queue class
 *
 *        Version:  1.0
 *        Created:  03/19/2013 02:25:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#ifndef ELIGUNDRY_QUEUE_H_
#define ELIGUNDRY_QUEUE_H_

#include "node.h"

template <typename T>
class Queue {
public:
	/*
	 * Default constructor for a queue with no data
	 * Ex: Queue<int> empty_queue;
	 */
	Queue(void);

	/*
	 * Copy constructor for queue
	 * Ex: Queue<int> new_queue(old_queue);
	 */
	Queue(const Queue<T>&);

	/*
	 * Destructor for queue
	 */
	~Queue(void);

	/*
	 * Assignment operator for queue
	 * Ex: Queue<int> new_queue = old_queue;
	 */
	Queue<T>& operator = (Queue<T>);

	/*
	 * Equality operator for queue
	 * Ex: new_queue == old_queue;
	 * Ex: new_queue != old_queue;
	 */
	bool operator == (const Queue<T>&) const;
	bool operator != (const Queue<T>& rhs) const { return !(*this == rhs); };

	/*
	 * Returns the length of the queue
	 * Ex. example_queue.getLength();
	 */
	int getLength(void) const { return length; };

	/*
	 * Determines if current queue is empty
	 * Ex: empty_queue.isEmpty();
	 */
	bool isEmpty(void) const { return front == 0; };

	/*
	 * Determines if current queue is full
	 * Ex: full_queue.isFull();
	 */
	bool isFull(void) const;

	/*
	 * Adds an element to the top of the queue
	 * Ex: example_queue.enqueue(1);
	 */
	void enqueue(const T&);

	/*
	 * Removes the top element of the queue
	 * Ex: example_queue.dequeue();
	 */
	T dequeue(void);

	/*
	 * Swaps two queues
	 * Ex: new_queue.swap(old_queue);
	 */
	void swap(Queue<T>&);

private:
	// Pointer to the front and back of the queue
	Node<T> *front, *back;

	// Length of the queue
	int length;
};

/*
 * Default constructor for a queue with no data
 * Ex: Queue<int> empty_queue;
 */
template <typename T>
Queue<T>::Queue()
{
	front = 0;
	back = 0;
	length = 0;
}

/*
 * Copy constructor for queue
 * Ex: Queue<int> new_queue(old_queue);
 */
template <typename T>
Queue<T>::Queue(const Queue<T>& actual)
{
	Node<T> *temp = actual.front;

	front = 0;
	back = 0;
	length = actual.length;

	while (temp != 0) {
		if (front == 0) {
			front = new Node<T>(temp->data);
			back = front;
		} else {
			back->next = new Node<T>(temp->data);
			back = back->next;
		}

		temp = temp->next;
	}
}

/*
 * Destructor for queue
 */
template <typename T>
Queue<T>::~Queue()
{
	while (front != 0) {
		Node<T> *temp = front;
		front = front->next;
		delete temp;
	}

	length = 0;
}

/*
 * Assignment operator for queue
 * Ex: Queue<int> new_queue = old_queue;
 */
template <typename T>
Queue<T>& Queue<T>::operator = (Queue<T> rhs)
{
	swap(rhs);
	return *this;
}

/*
 * Equality operator for queue
 * Ex: new_stack == old_stack;
 * Ex: new_stack != old_stack;
 */
template <typename T>
bool Queue<T>::operator == (const Queue<T>& rhs) const
{
	if (length != rhs.length) {
		return false;
	}

	Queue<T> l(*this), r(rhs);

	while (!l.isEmpty() && !r.isEmpty()) {
		if (l.dequeue() != r.dequeue()) {
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
std::ostream& operator << (std::ostream& out, const Queue<T> rhs)
{
	for (Queue<T> temp(rhs); !temp.isEmpty();) {
		out << '[' << temp.dequeue() << "] ";
	}

	return out;
}

/*
 * Determines if current queue is full
 * Ex: full_queue.isFull();
 */
template <typename T>
bool Queue<T>::isFull() const
{
	// Try to create a new node in the queue
	Node<T> *temp = new(std::nothrow) Node<T> ();

	// If we can't do that, we are out of memory
	if (temp == 0) {
		return true;
	}

	delete temp;
	return false;
}

/*
 * Adds an element to the top of the queue
 * Ex: example_queue.enqueue(1);
 */
template <typename T>
void Queue<T>::enqueue(const T& item)
{
	// If queue is full, do nothing
	assert(!isFull());

	// Create temporary node with passed in data
	Node<T> *temp = new Node<T>(item);

	if (front == 0) {
		front = temp;
		back = temp;
	} else {
		back->next = temp;
		back = temp;
	}

	++length;
}

/*
 * Removes the top element of the queue
 * Ex: example_queue.dequeue();
 */
template <typename T>
T Queue<T>::dequeue()
{
	// If queue is empty do nothing
	assert(!isEmpty());

	// Set result to the top of the data
	T result = front->data;

	// Make a temporary pointer to front
	Node<T> *temp = front;
	front = front->next;

	// If front equals back, delete it
	if (temp == back) {
		back = 0;
	}

	--length;

	delete temp;
	return result;
}

/*
 * Swaps two queues
 * Ex: new_queue.swap(old_queue);
 */
template <typename T>
void Queue<T>::swap(Queue<T>& rhs)
{
	// Creates a temp node and copy front into it
	Node<T> *temp = rhs.front;
	int tempLength = rhs.length;

	// Set rhs to *this
	rhs.front = front;
	rhs.length = length;
	front = temp;

	// Swap the backs
	temp = rhs.back;
	back = temp;
	length = tempLength;
}

#endif
