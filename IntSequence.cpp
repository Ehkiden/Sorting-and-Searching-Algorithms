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
		cout << sequence[i] << " ";
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
//done
void IntSequence::selection_sort()
{
	//displays the unsorted sequence
	cout << "Unsorted Sequence ";
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i] << " ";
	}
	cout << endl;
	int size = getSize();
	for (int i = 0; i < size - 1; i++) {
		int min_index = i;
		for (int j = 1+i; j < size; j++) {
			if (sequence[j] < sequence[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i) {
			swap(sequence[i], sequence[min_index]);
			cout << "Min " << sequence[i] << ", swap with " << sequence[min_index] << ":" << endl;
		}
	}
	//displays the sorted sequence
	cout << "Sorted Sequence  ";
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i] << " ";
	}
	cout << endl;
}

void IntSequence::merge_sort(int left, int right)
{
	if (left < right) {
		int mid = (left + right) / 2;
		//sort first and second half
		merge_sort(left, mid);
		merge_sort(mid + 1, right);

		merge(left, mid, right);
	}
	return;
}

void IntSequence::merge(int left,int mid,int right)
{
	int i = left;
	int k = left;
	int j = mid + 1;
	vector<int> temp(getSize());

	while (i <= mid && j <= right) {
		if (sequence[i] < sequence[j]) {
			cout << "Sub vector 1:\n" << sequence[i] << endl;
			cout << "Sub vector 2:\n" << sequence[j] << endl;
			cout << "Merged Vector:\n" << sequence[i] << " " << sequence[j] << endl;

			temp[k] = sequence[i];
			k++;
			i++;
		}
		else {
			cout << "Sub vector 1:\n" << sequence[i] << endl;
			cout << "Sub vector 2:\n" << sequence[j] << endl;
			cout << "Merged Vector:\n" << sequence[j] << " " << sequence[i] << endl;

			temp[k] = sequence[j];
			k++;
			j++;
		}
	}
	// Copy the original vector to the temp vector 
	while (i <= mid) {
		temp[k] = sequence[i];
		k++;
		i++;
	}
	// Copy the original vector to the temp vector 
	while (j <= right) {
		temp[k] = sequence[j];
		k++;
		j++;
	}
	//copy the corted temp vector to the origninal vector
	for (i = left; i < k; i++) {
		sequence[i] = temp[i];
	}
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
		if (key<sequence[0] || key>sequence[getSize() - 1]) {
			return -1;
		}
		else {
			//this will return either the index of the key or a -1 if not found
			return binary_search_helper(key, 0, getSize() - 1);
		}
	}
}

IntSequence::~IntSequence()
{
	sequence.clear();
}