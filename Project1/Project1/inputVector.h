#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#include<list>
#include "circuitParamList.h"



using namespace std;
#pragma once

class inputVector
{
public:
	//circuitParamList param;
	std::vector<int> Vector;
	void myVector(int x)
	{
		
		cout << "Type in a list of inputs (" << x <<" ) " << endl;

		int input = 0;
		for (int i = 0; i < x; i++)
		{
			cin >> input;
			Vector.push_back(input);

		}
		cout << "Vector Result: " << endl;
		for (int i = 0; i < x; i++)
		{
			
			cout << Vector[i] << endl;
			
		}
		cin.get();
		
		
	}

	


};
