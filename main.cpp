//course: CS215-004
//Project: Programming Assignment 3
//Date: 12/4/16
//Purpose: Reads data from the user and displays the data and offers two sorting algorithms repeatedly
//Author: Jared Rigdon

#include <iostream>
#include <vector>
#include <string>
#include "IntSequence.h"

using namespace std;

void pause_215(bool have_newline);
void submenu(IntSequence& Seq); //displays the sub menu
void read_data(IntSequence& Seq);	//reads the data until the user enters q
void sort_alg(IntSequence& Seq,int key);

int main() {
	int choice;
	IntSequence Seq;	//initialize the object
						//display the menu until the user enters 4 to quit
	while (true) {
		cout << "=============================================" << endl;
		cout << "1. Read\n" << "2. Print\n" << "3. Search\n" << "4. Quit\n" << "Option: ";
		cin >> choice;

		//checks to see if the input is valid
		if (cin.fail()) {
			cin.clear();
			cin.ignore(265, '\n');
			cout << "Invalid option!" << endl;
		}
		else if (choice <= 0 || choice > 4) {
			cin.clear();
			cin.ignore(265, '\n');
			cout << "Invalid option!" << endl;
		}
		//else call the proper functions from the IntSequence class
		//asks the user to enter integers
		else if (choice == 1) {
			//check if there are values in the sequence, if so then clear the sequence
			if (Seq.isEmpty() == true) {
				Seq.~IntSequence();
				read_data(Seq);
			}
			else {
				read_data(Seq);
			}
		}
		//prints the sequence
		else if (choice == 2) {
			if (Seq.isEmpty() == true) {
				Seq.print();
			}
			else {
				cout << "The sequence is empty, you need to read data first..." << endl;
			}
		}
		//displays the submenu
		else if (choice == 3) {
			if (Seq.isEmpty() == true) {
				submenu(Seq);
			}
			else {
				cout << "The sequence is empty, you need to read data first..." << endl;
			}
		}
		//if the user enters 4 then quit the program
		else if (choice == 4) {
			break;
		}
	}

	pause_215(true);
	return 0;
}

//ask the user to enter an integer until the user enters 'q'
void read_data(IntSequence& Seq) {
	int num;
	while (true) {
		cout << "Enter the next element (Enter 'q' to stop): ";
		cin >> num;
		cout << endl;
		//check if the user entered q to quit or an invalid number
		if (cin.fail())
		{
			string input_to_check;
			cin.clear();
			cin >> input_to_check;
			if (input_to_check == "q")
				break;
			else { cout << "Invalid number!" << endl; }
		}
		//else add it to the vector
		else {
			Seq.insert(num);
		}
	}
}
//display the submenu until the user enters 3 to quit
void submenu(IntSequence& Seq) {
	//display the options
	int choice, key;
	while (true) {
		cout << "Choose from the following sub-menu: " << endl;
		cout << "1. Sequential search\n" << "2. Binary search\n" << "3. Quit\n" << "Option: ";
		cin >> choice;

		//checks to see if the input is valid
		if (cin.fail()) {
			cin.clear();
			cin.ignore(265, '\n');
			cout << "Invalid option!" << endl;
		}
		else if (choice <= 0 || choice > 3) {
			cin.clear();
			cin.ignore(265, '\n');
			cout << "Invalid option!" << endl;
		}

		//uses the sequential search
		else if (choice == 1) {
			//check if valid
			cout << "Enter the key to find: ";
			cin >> key;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(265, '\n');
				cout << "Invalid option!" << endl;
			}
			else {
				if (Seq.sequential_search(key) == -1) {	//if it was not found
					cout << "Key not Found" << endl;
				}
				else {
					//return the index the key was found at
					cout << "Key found at index " << Seq.sequential_search(key) << endl;
				}
			}
		}

		//uses the binary search
		else if (choice == 2) {
			cout << "Enter the key to find: ";
			cin >> key;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(265, '\n');
				cout << "Invalid option!" << endl;
			}
			else {
				/*
				for the bonus we will create another menu letting the user choose between 3 sorting algorithms
				*/
				sort_alg(Seq, key);
				//sorts the sequence before finding the key
				
				
			}

		}
		//quits the submenu
		else if (choice == 3) {
			break;
		}
	}
}
void sort_alg(IntSequence& Seq,int key) {
	int choice;
	//display and ask what sorting algorithm to use
	while (true) {
		cout << "Please choose one of the following algorithms to sort the\nsequence: " << endl;
		cout << "1. Bubble Sort\n" << "2. Selection Sort\n" << "3. Merge Sort\n" << "Option: ";
		cin >> choice;

		//checks to see if the input is valid
		if (cin.fail()) {
			cin.clear();
			cin.ignore(265, '\n');
			cout << "Invalid option!\nThe sequence is not sorted, cannot apply binary search!" << endl;
			break;
		}
		else if (choice <= 0 || choice > 3) {
			cin.clear();
			cin.ignore(265, '\n');
			cout << "Invalid option!\nThe sequence is not sorted, cannot apply binary search!" << endl;
			break;
		}

		//Bubble Sort
		else if (choice == 1) {
			Seq.bubble_sort();
		}
		//Selection Sort
		else if (choice == 2) {
			Seq.selection_sort();
		}
		//Merge Sort
		else {
			int left = 0;
			int right = Seq.getSize() - 1;
			
			cout << "Unsorted: ";
			Seq.print();
			Seq.merge_sort(left,right);
			cout << "Sorted: ";
			Seq.print();
		}

		if (Seq.binary_search(key) == -1) {	//if it was not found
			cout << "\nKey not Found" << endl;
		}
		else {
			cout << "\nKey found at index " << Seq.binary_search(key) << endl;	//display the index it was found at
		}
		//the sorted sequence is then shuffled randomly
		cout << "After calling shuffle, the sequence is in a random\npermutation: ";
		Seq.shuffle();
		Seq.print();
	}
}

void pause_215(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(256, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(256, '\n');
}