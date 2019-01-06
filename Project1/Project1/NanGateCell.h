#pragma once
#include<iostream>
#include<cmath>
#include<string>


using namespace std;


#pragma once
class NanGateCell
{
public:

	int gate(string gate, int A1, int A2, int B1, int B2, int out) {
		int result;
		
		if (gate == "INV_X1") {

			if (A1 == 1) {
				result = 0;
			}
			else {
				result = 1;
			}
		}

		if (gate == "AND2_X1") {

			if (A1 == 1 && A2 == 1) {
				result = 1;
			}
			else {
				result = 0;
			}
		}

		if (gate == "XOR2_X1") {

			if (A1 == A2 ) {
				result = 0;
			}
			else {
				result = 1;
			}
		}

		if (gate == "OR2_X1") {

			if (A1 == 1 || A2 == 1) {
				result = 1;
			}
			else {
				result = 0;
			}
		}

		if (gate == "NOR2_X1") {

			if (A1 == 0 && A2 == 0) {
				result = 1;
			}
			else {
				result = 0;
			}
		}

		if (gate == "NAND2_X1") {

			if (A1 == 1 && A2 == 1) {
				result = 0;
			}
			else {
				result = 1;
			}
		}
		
		if (gate == "AOI22_X1") {

			if (((A1 == 1 && A2 == 1) || (B1 ==1 && B2==1))) {
				result = 0;
			}
			else {
				result = 1;
			}
		}

		if (gate == "OAI22_X1") {

			if ((A1 == 1 || A2 == 1) && (B1 == 0 || B2 == 0)) {
				result = 0;
			}
			else {
				result = 1;
			}
		}


		
	return result;
}
};