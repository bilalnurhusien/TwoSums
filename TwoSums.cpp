/*
 * File: TwoSums.cpp
 *
 * Created on: 2013-08-05
 * Author: Bilal Nurhusien
 * Copyright 2013 © Bilal Nurhusien
 * This program is free software.
 *
 * Description: Implemented a variant of 2-SUM algorithm for sums between 2500 and 4000
 * using a sorted vector. The task was to compute the number of target values t in the
 * interval [2500,4000] (inclusive) such that there are distinct numbers x,y in the input
 * file (./HashInt.txt) that satisfy x+y=t. The input file was taken from the Algorithms
 * and Analysis course taught by Tim Roughgarden on Coursera.
 *
 * Input file: The input file (HashInt.txt) is in the project directory. Each line of
 * the input file contains a positive integer.
 *
 * Output: The number of target values (t) in the interval [2500,4000] will be displayed
 * in stdout such that there are distinct numbers x,y in the input file that satisfy x+y=t.
 * For the input file, HashInt.txt, the number of target values is 1477.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <set>

#define LOWER  2500
#define HIGHER 4000

using namespace std;

/*
 * Precondition: Each line of the input file contains a positive integer.
 * The input file (HashInt.txt) is in the project directory.
 *
 * Postcondition: Every number in the file will be stored in vector V.
 * The ith entry in the file will be stored in index i-1.
 */

int ReadFile(vector<unsigned int>& V) {
	const char* inputfile = "./HashInt.txt";
	std::string line;
	std::ifstream infile;
	infile.open(inputfile);

	if(infile.fail())
	{
		cout << "Problem opening file.";
		return -1;
	}

	while (getline(infile, line)) {
		istringstream iss(line);
		unsigned int a;
		iss >> a;
		V.push_back(a);
	}

	return 0;
}

/*
 * Precondition: V is a vector of integers.
 *
 * Postcondition: Each integer in V will be printed to stdout.
 */
void PrintNum(const vector<unsigned int>& V) {
	for (auto it = V.begin(); it != V.end(); ++it) {
    	cout << *it << endl;
	}
}

/*
 * Precondition: V is a sorted vector of integers
 *
 * Postcondition: The number of target values (t) in the interval
 * [2500,4000] will be displayed in stdout such that there
 * are distinct numbers x,y in the input file that satisfy x+y=t.
 */
void TwoSum (vector<unsigned int>& V) {
	vector<unsigned int>::iterator x;
	vector<unsigned int>::iterator y;
	unsigned int count = 0;

	for (unsigned int i = LOWER; i <= HIGHER; ++i) {
		x = V.begin();
		y = V.end()-1;

		while (x != y) {
			unsigned int sum = *x + *y;

			if (sum == i) {
				count++;
				break;
			}

			else if(sum < i) {
				x+=1;
			}

			else {
				y-=1;
			}
		}
	}
	cout << "Count is: " << count << endl;
}
int main () {

	// Read integers and store in vector
	vector<unsigned int>V;
	if (ReadFile(V) < 0) return -1;

	// Erase duplicate numbers and sort vector
	set<unsigned int> s;
	unsigned int size = V.size();
	for( unsigned int i = 0; i < size; ++i ) s.insert( V[i] );
	V.assign(s.begin(),s.end() );
	sort(V.begin(), V.end());

	// Implement 2-SUM algorithm for numbers between 2500 and 4000
	TwoSum(V);

	return 0;
}
