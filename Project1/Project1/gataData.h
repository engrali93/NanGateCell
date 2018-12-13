#include <iostream>
#include <fstream>
#include<string>
#include <list>
#include <algorithm>
#include <unordered_map>

//#include <boost/algorithm/string.hpp>
using namespace std;

#pragma once
class gateData
{
public:


	void dataTostore(string str) 
	{
	if((str.find(" or") != std::string::npos )||(str.find("and") != std::string::npos))
		{
		
		//boost::iterator_range<std::string::const_iterator> rng;

		//rng = boost::ifind_first(str, std::string("EL"));

		//return rng;
		//std::cout << str <<" lol" << endl;
		
		

		}
	}


	void hashForInput(string str, int val, int legth) {
	
		unordered_map<string, int> hashGateValue;
		for (int i = 0; i < legth; i++) {
			hashGateValue.emplace(str, val);

		}
		//cout << inputList.size() << endl;


		cout << "IP Address: " << hashGateValue["v2"] << hashGateValue["v1"] << endl;
	}
};
