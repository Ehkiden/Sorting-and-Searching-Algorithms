#pragma once
#ifndef INTSEQUENCE_H
#define INTSEQUENCE_H
#include <vector>

using namespace std;

class IntSequence
{
public:
	// create an empty vector 
	IntSequence();		// default constructor

						// copy constructor
	IntSequence(const IntSequence &other);

	// Assignment operator overloading
	IntSequence &operator=(const IntSequence &other);

	// insert item into the end of the current sequence
	void insert(int item);

	// return the current size of the sequence
	int getSize() const;

	// check if the sequence is empty
	bool isEmpty() const;

	// display all the items in the sequence
	void print() const;

	// sort the sequence into non-decreasing order
	// using Bubble Sorting algorithm
	void bubble_sort();

	// using Selection Sorting algorithm
	void selection_sort();

	// using Merge Sorting algorithm
	void merge_sort(int left,int right);

	//recursive for merge_sort
	void merge(int left, int mid, int right);

	// shuffle the items in the sequence
	// generates a random permutation of vector elements
	void shuffle();

	// search a target key in the sequence: 
	// if found return the index number; if not found return -1
	int sequential_search(int key) const;

	// Condition: this only applys to a sorted sequence
	// search a target key in the sequence: 
	// if found return the index number; if not found return -1
	int binary_search_helper(int key, int leftindex, int rightindex);
	int binary_search(int key);

	// destructor
	~IntSequence();

	// more member functions here ... 

private:
	vector<int> sequence;	  //sequence is the vector of integers
};

#endif