#pragma once
#include <iostream> 
#include <sstream> 
using namespace std;

class moreFunc
{
public:


	string extractIntegerWords(string str) {
		stringstream ss;

		/* Storing the whole string into string stream */
		ss << str;

		/* Running loop till the end of the stream */
		string temp;
		int found;
		vector<int> vect;
		while (!ss.eof()) {

			/* extracting word by word from stream */
			ss >> temp;

			/* Checking the given word is integer or not */
			if (stringstream(temp) >> found)
				cout << found << " ";
			vect.push_back(found);

			/* To save from space at the end of string */
			temp = "";
		}

		cout << endl;
		return "pop";
	}

};