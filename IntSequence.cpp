#include "IntSequence.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

IntSequence::IntSequence()
{
	vector<int> sequence;
}

IntSequence::IntSequence(const IntSequence & other)
{
	vector<int> sequence = other.sequence;
}

IntSequence & IntSequence::operator=(const IntSequence & other)
{
	if (this != &other) {
		int size = getSize();
		sequence.clear();
		for (int i = 0; i < size; i++) {
			sequence[i] = other.sequence[i];
		}
		return *this;
	}
	// TODO: insert return statement here
}

void IntSequence::insert(int item)
{
	sequence.push_back(item);
}

int IntSequence::getSize() const
{
	int size = sequence.size();
	return size;
}

bool IntSequence::isEmpty() const
{
	if (sequence.empty()) {
		return false;
	}
	else {
		return true;
	}
}

void IntSequence::print() const
{
	cout << "Sequence ";
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i]<<" ";
	}
	cout << endl;
}

void IntSequence::bubble_sort()
{
	//displays the unsorted sequence
	cout << "Unsorted Sequence ";
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i] << " ";
	}
	cout << endl;
	//sorts the sequence and displays easch iteration
	int n = 1;
	for (int i = 0; i < getSize() - 1; i++) {
		for (int j = 0; j < getSize() - 1; j++) {
			if (sequence[j] > sequence[j + 1]) {
				swap(sequence[j], sequence[j + 1]);

				cout << "Iteration " << n++ << ": ";
				for (int k = 0; k<sequence.size(); k++) {
					cout << sequence[k] << " ";
				}
				cout << endl;
			}
		}
	}
	//displays the sorted sequence
	cout << "Sorted Sequence  ";
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i] << " ";
	}
	cout << endl;
}

void IntSequence::shuffle()
{
	//shuffles the vector after it was sorted
	random_shuffle(begin(sequence), end(sequence));
}

int IntSequence::sequential_search(int key) const
{
	//checks each value until it finds the key or if it reaches the end
	int index = -1;
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] == key) {
			index = i;
			return index;
		}
	}
	//return -1 if not found
	if (index == -1) {
		return -1;
	}
}

int IntSequence::binary_search_helper(int key, int leftindex, int rightindex)
{
	//if the right index is less than the left index then return -1 for not found
	if (rightindex < leftindex) {
		return -1;
	}
	else {
		int mid = (leftindex + rightindex) / 2;
		//checks to the right of vector
		if (key > sequence[mid]) {
			return binary_search_helper(key, mid + 1, rightindex);
		}
		//checks to the left of vector
		else if (key < sequence[mid]) {
			return binary_search_helper(key, leftindex, mid - 1);
		}
		//returns the index it was found at
		else {
			return mid;
		}
	}
}

int IntSequence::binary_search(int key)
{
	int index = -1;
	//base case
	if (sequence.size() == 1) {
		if (sequence[0] == key) {
			index = 0;
			return index;
		}
		else {
			return index;
		}
	}
	else {
		//first need to check the out bounds of the pre sorted list first
		if (key<sequence[0] || key>sequence[getSize()-1]) {
			return -1;
		}
		else {
			//this will return either the index of the key or a -1 if not found
			return binary_search_helper(key, 0, getSize()-1);
		}
	}
}

IntSequence::~IntSequence()
{
	sequence.clear();
}
