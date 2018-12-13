#include<iostream>
#include<cmath>
#include<string>


using namespace std;


#pragma once
class gateFunction
{
public:
	int result;
	size_t pos = 0;
	void andGate(int a, int b)
	{
		if (a == 1 && b == 1)
		{
			result = 1;
		}
		else
		{
			result = 0;
		}

	}

	void orGate(int a, int b)
	{

		if (a == 1 || b == 1)
		{
			result = 1;
		}
		else
		{
			result = 0;
		}

	}

	void notGate(int a)
	{

		result = !a;
	}

	void NandGate(int a, int b)
	{

		if (a == 1 && b == 1)
		{
			result = 0;
		}
		else
		{
			result = 1;
		}
		
	}

	void NorGate(int a, int b)
	{
		if (a == 1 || b == 1)
		{
			result = 0;
		}
		else
		{
			result = 1;
		}

	}

	void xorGate(int a, int b)
	{
		if (a == b)
		{
			result = 0;
		}
		else
		{
			result = 1;
		}

	}
	
	int gate(int a, int b, string str) {
		int result1;
		//if ((pos = str.find("and")) != std::string::npos) {
		if ((str == "and") || (str == "AND")) {
			if (a == 1 && b == 1)
			{
				result1 = 1;
				//cout << result<<endl;
				//return result1;
			}
			else
			{
				result1 = 0;
				//cout << result << endl;
				//return result1;
			}
		}

		//if (((pos = str.find("xor")) != std::string::npos) && ((pos = str.find("x")) != std::string::npos)) {
		if ((str=="xor") || (str=="XOR")){
			if (a == b)
			{
				result1 = 0;
				//cout << result << endl;
				//return result1;
			}
			else
			{
				result1 = 1;
				//cout << result << endl;
				//return result1;
			}
		}

		//if ((pos = str.find("or")) != std::string::npos) {
		if ((str == "or") || (str =="OR")) {
			if (a == 1 || b == 1)
			{
				result1 = 1;
				//cout << result << endl;
				//return result1;
			}
			else
			{
				result1 = 0;
				//cout << result << endl;
				//return result1;
			}
		}

		if ((str == "not") || (str == "NOT")) {
			if (a == 1)
			{
				result1 = 0;
				//cout << result << endl;
				//return result1;
			}
			else
			{
				result1 = 1;
				//cout << result << endl;
				//return result1;
			}
		}

			if ((str == "nor") || (str == "NOR")) {
				if (a == 0 && b == 0)
				{
					result1 = 1;
					//cout << result << endl;
					//return result1;
				}
				else
				{
					result1 = 0;
					//cout << result << endl;
					//return result1;
				}
			}

			if ((str == "nand") || (str == "NAND")) {
				if (a == 1 && b == 1)
				{
					result1 = 0;
					//cout << result << endl;
					//return result1;
				}
				else
				{
					result1 = 1;
					//cout << result << endl;
					//return result1;
				}
			}

			if ((str == "xnor") || (str == "XNOR")) {
				if ( a== b )
				{
					result1 = 1;
					//cout << result << endl;
					//return result1;
				}
				else
				{
					result1 = 0;
					//cout << result << endl;
					//return result1;
				}
			}
		
		return result1;
	}
};