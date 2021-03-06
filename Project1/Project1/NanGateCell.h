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
		if (gate == "OAI21_X1") {

			if ((A1 == 0 && A2 == 0) || (B1 == 0 )) {
				result = 1;
			}
			else {
				result = 0;
			}
		}

		if (gate == "AOI21_X1") {

			if ((A1 == 0 || A2 == 0) && (B1 == 0)) {
				result = 1;
			}
			else {
				result = 0;
			}
		}
		if (gate == "XNOR2_X1") {

			if (A1 == A2 ) {
				result = 1;
			}
			else {
				result = 0;
			}
		}

		if (gate == "FA_X1") {
			int count = A1 + A2 + B1;
			//*cout <<"lib : "<< count << endl;
			if (count == 1) {
				//*cout << "liba : " << count << endl;
				result = 1;
			}
			if (count == 2) {
				//*cout << "libb : " << count << endl;
				result = 2;
			}
			if (count == 3) {
				//*cout << "libc : " << count << endl;
				result = 3;
			}
			if(count == 0) {
				//*cout << "libd : " << count << endl;
				result = 0;
			}
		}
		
	return result;
}

	string GateType(string gate) {
		string gate_type[8] = { "OAI22_X1" ,"AOI22_X1" ,"NAND2_X1","NOR2_X1","OR2_X1" ,"XOR2_X1","AND2_X1","INV_X1" };
		size_t pos = 0;
		string answer;
		for (int i = 0; i < 8; i++) {
			if ((pos = gate_type[i].find(gate)) != std::string::npos) {
				answer = "YES";
			}
		}
		return answer;
	}
};