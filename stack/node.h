/*
 * =====================================================================================
 *
 *       Filename:  node.h
 *
 *    Description:  Header file for the node class
 *
 *        Version:  1.0
 *        Created:  03/18/2013 02:31:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Eli Gundry
 *
 * =====================================================================================
 */

#ifndef ELIGUNDRY_NODE_H_
#define ELIGUNDRY_NODE_H_

#include <iostream>
#include <cassert>

template <typename T>
class Node {
public:
	// Default constructor for node
	Node(): data(), next(0) {};

	// Node constructor for element with data
	Node(T item): data(item), next(0) {};

	// Data container for node
	T data;

	// Node's pointer to the next element
	Node<T> *next;
};

#endif
