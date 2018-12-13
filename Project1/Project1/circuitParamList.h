#include <iostream>
#include <fstream>
#include<string>
#include <list>
#include <algorithm>

using namespace std;


#pragma once
class circuitParamList
{
public:
	std::list<string> input;
	std::list<string> output;
	std::list<string> wire;
	std::list<string> and_gate;
	std::list<string> or_gate;
	std::list<string> xor_gate;


	void iplist(string param)
	{
	 // std::list<string> input;
		// comparing and sorting into the list 
		
			input.push_back(param);
		
	}
	void iplistdisplay()
	{
				
		//cout << input.size() << endl;
		for (auto v : input)
			std::cout << v << "\n";
		
	}
	
	
	int  size()
	{
		int x = input.size();
		return x;
		
	}

	void oplist( string param) 
	{
		//std::list<string> output;
		
			output.push_back(param);

	
	}

	void wirelist(string param)
	{
		//std::list<string> wire;
	
	
			wire.push_back(param);
	
	
	}

	void andGatelist( string param)
	{

		//std::list<string> and_gate;
	
			and_gate.push_back(param);



	}

	void orGatelist(string param)
	{

		//std::list<string> or_gate;
	
			or_gate.push_back(param);



	}

	void xorGatelist(string value, string param)
	{
		//std::list<string> xor_gate;
	
			xor_gate.push_back(param);


	}


};