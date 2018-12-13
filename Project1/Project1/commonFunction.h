#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>
using namespace std;

class commonFunction
{
public:
	inline bool caseInsCharCompSingle(char a, char b) {
		return(toupper(a) == b);
	}

	string::const_iterator caseInsFind(string& line, const string& word) {
		string tmp;

		transform(word.begin(), word.end(),             // Make the pattern
			back_inserter(tmp),                 // upper-case
			toupper);

		//return(search(line.begin(), line.end(),         // Return the iter- 
		//	tmp.begin(), tmp.end(),     // ator returned by
		//	caseInsCharCompSingle));        // search
	}

	int main( string line, string word) {
		//string s = "row, row, row, your boat";
		//string p = "YOUR";
		string::const_iterator it = caseInsFind(line, word);
		int true_;
		if (it != line.end()) {
			true_ = 1;
			//cout << "Found it!\n";
			return true_;
		}
		else {
			true_ = 0;
			return true_;
		}
	}
};