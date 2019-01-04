//("D:\\project arbeit\\files\\file1.txt");

#include <iostream>
#include <fstream>
#include<string>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "circuitParamList.h"
#include "gateFunction.h"
#include "gataData.h"
#include "inputVector.h"
#include <sstream>
#include "commonFunction.h"
#include <cctype>
#include <regex>
#include "moreFunc.h"





using namespace std;



int main()
{
	moreFunc moreFunc;
	commonFunction comFun;
	circuitParamList inputList;
	circuitParamList outputList;
	circuitParamList wireList;
	circuitParamList andGateList;
	circuitParamList orGateList;
	circuitParamList xorGateList;
	gateData gateData;
	gateFunction gatefunction;
	inputVector inputVectorNew;
	unordered_map<string, int> hashGateValue;
	unordered_map<string, int, int> hashFunction2in;
	unordered_map<string, int, int,int> hashFunction3in;
	unordered_map<string, string, string, string> hashsorting;
	std::list<string> sort_acc_ip;
	std::list<string> functionSeparate;
	
	std::vector<int> Vector;
	std::vector<int> vect;
	std::list<string> result;
	std::list<string> op_result;
	std::list<string> ip_Vec;
	std::list<string> op_Vec;
	std::list<string> sorting_list;
	std::list<string> sorting_list2;
	std::list<string> sorting_list3;
	std::list<string> sorting_Nomatch_list;
	std::string line_;
	std::string read_line;
	std::string delimiter = ",";
	std::string ip_vector;
	std::string op_vector;
	int vect_size;
	int result_temp;
	int io = 0;
	size_t pos = 0;
	std::string token;
	//ifstream file_("D:/project arbeit/files/full_adder_vhdl/full_add.vhd");
	ifstream file_("D:/project arbeit/files/2-bit/exact_adder_cla_T=2_TECH=freepdk45tc_B=2.vhd");
	if (file_.is_open())
	{
		while (getline(file_, line_))
		{
			//std::cout << "here is the line" << '\n';
			read_line = line_;
			std::string ipPort="in std_logic;";
			std::string ipPort1 = "IN STD_LOGIC;";
			std::string ipVec1 = "in std_logic_vector";
			std::string opVec1 = "out std_logic_vector";
			std::string opPort = "out std_logic";
			std::string opPort1 = "out STD_LOGIC";
			std::string port = "port(";
			
			///////////////////////////////////
			// extracting input port
			////////////////////////////////////
			/*transform(read_line.begin(), read_line.end(), read_line.begin(), tolower);
			cout << read_line << endl;*/
			


			if (read_line.find(ipPort) != std::string::npos)
			{
				//std::string::size_type i = line_.find(ipPort);
				std::cout << "\nINPUT" << endl;
				//if (i != std::string::npos)
				line_.erase(line_.find(port), port.length());
				line_.erase(line_.find(ipPort), ipPort.length());
				line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
				
				//std::cout << line_ << '\n';
				while ((pos = line_.find(delimiter)) != std::string::npos) 
				{
					//line_.erase(std::remove(line_.begin(), line_.end(), ' '));
					token = line_.substr(0, pos);
					//std::cout << token << std::endl;
					line_.erase(0, pos + delimiter.length());
					std::cout << line_ << std::endl;
					//result.push_back(token);
					//listing("input",token);
					token.erase(remove_if(token.begin(), token.end(), isspace), token.end());
					inputList.iplist(token);//right one
					result.push_back(token);
					ip_Vec.push_back(token);
				}
				//std::cout << line_ << std::endl;
				//result.push_back(line_);
				//listing("input", line_);
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				inputList.iplist(line_);
				result.push_back(line_);
				ip_Vec.push_back(line_);
				/*std::list<std::string>::iterator it = result.begin();
				std::advance(it, 4);
				std::cout << "3rd element = " << *it << std::endl;
				
				for (auto v : result)
					std::cout << v << "\n";*/
				//listing ();
				/*int co;
				co= inputList.size();
				inputList.iplistdisplay();*/
				//cout << "here" << co << endl;
				//inputVectorNew.myVector;
				/*cout << "Type in a list of inputs (" << co << " ) " << endl;
				std::list<std::string>::iterator it = result.begin();*/

				//auto it1 = std::next(result.begin(), 2);

				//std::cout << "3rd element = " << *it1 << std::endl;

////////#########################################

				//int input = 0;
				//for (int i = 0; i < co; i++)
				//{
				//	auto it1 = std::next(result.begin(), i);
				//	cin >> input;
				//	Vector.push_back(input);
				//	//cout << result.front(i) << "ioi" << endl;
				//	hashGateValue.emplace(*it1, input);
				//}
				//cin.get();
				//
				//inputVectorNew.myVector(co);
				
				
				
				
			}

			
			
			
			////////////////////////////////////
			//////// input Vector
			/////////////////////////

			if (read_line.find(ipVec1) != std::string::npos)
			{
				std::cout << "\nINPUT Vector" << endl;
				//line_.erase(line_.find(port), port.length());
				line_.erase(line_.find(ipVec1), ipVec1.length());
				line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
				std::string::size_type firstQuotePos = line_.find_first_of("(");
				std::string::size_type secondQuotePos = line_.find_first_of(")");
				if (firstQuotePos != std::string::npos)
				{
					string strNew = line_.substr(firstQuotePos, secondQuotePos);
					strNew.erase(strNew.begin()+0);
					stringstream ss;
					ss << strNew;
					string temp;
					int found;
					/*std::vector<int> vect;*/
					cout << "downto" << endl;
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
					if (vect.size() > 2)  vect.erase(vect.begin() + 2,vect.end()) ;
					/*for (int x : vect)
						cout << x << " ";*/
					cout <<vect.size()<<"yr"<< endl;
					vect_size = vect.size();
					
					//cout << strNew << "  <= " << endl;
					line_.erase(firstQuotePos,secondQuotePos );
				}
				//std::cout << line_ <<'\n';
				while ((pos = line_.find(delimiter)) != std::string::npos)
				{
					token = line_.substr(0, pos);
					line_.erase(0, pos + delimiter.length());
					//std::cout << line_ << std::endl;
					token.erase(remove_if(token.begin(), token.end(), isspace), token.end());
					inputList.iplist(token);//right one
					//result.push_back(token);
					//ip_Vec.push_back(token);
					//cout << token << endl;
					for (int a = 0; a < vect_size; a++) {
						std::stringstream str;
						str << token << "(" << a << ")";
						ip_vector = str.str();
						ip_Vec.push_back(ip_vector);
						//cout << ip_vector<< endl;
					}
				}
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				for (int a = 0; a < vect_size; a++) {
					std::stringstream str;
					str << line_ << "(" << a << ")";
					ip_vector = str.str();
					ip_Vec.push_back(ip_vector);
					//cout << ip_vector << endl;
				}
				//inputList.iplist(line_);
				//result.push_back(line_);
				//ip_Vec.push_back(line_);
				//cout << line_ << endl;


				for (auto v : ip_Vec)
					std::cout << v << "\n";

				int co;
				co = ip_Vec.size();
				

				cout << "Type in a list of inputs (" << co << " ) " << endl;
				std::list<std::string>::iterator it = ip_Vec.begin();


				int input = 0;
				for (int i = 0; i < co; i++)
				{
					auto it1 = std::next(ip_Vec.begin(), i);
					cout << *it1 << " : ";
					cin >> input;
					Vector.push_back(input);
					//cout << result.front(i) << "ioi" << endl;
					
					hashGateValue.emplace(*it1, input);
				}
				cin.get();
				
				//inputVectorNew.myVector(co);	
			}

			
			
			//////////////////////////////////
			//////// output vector
			///////////////////////////////////

			if (read_line.find(opVec1) != std::string::npos)
			{
				vect.clear();
				std::cout << "\nOUTPUT Vector" << endl;
				//line_.erase(line_.find(port), port.length());
				line_.erase(line_.find(opVec1), opVec1.length());
				line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
				std::string::size_type firstQuotePos = line_.find_first_of("(");
				std::string::size_type secondQuotePos = line_.find_first_of(")");
				if (firstQuotePos != std::string::npos)
				{
					//line_.erase(firstQuotePos, secondQuotePos);

					string strNew = line_.substr(firstQuotePos, secondQuotePos);
					strNew.erase(strNew.begin() + 0);
					stringstream ss;
					ss << strNew;
					string temp;
					int found;
					///*std::vector<int> vect;*/
					//cout << "downto" << endl;
					while (!ss.eof()) {

						//	/* extracting word by word from stream */
						ss >> temp;

						//	/* Checking the given word is integer or not */
						if (stringstream(temp) >> found)
							//cout << found << " ";
							vect.push_back(found);

						//	/* To save from space at the end of string */
						//temp = "";
					}
					if (vect.size() > 2)  vect.erase(vect.begin() + 2, vect.end());
					/*for (int x : vect)
						cout << x << " ";*/
					//cout << vect.size() << "or" << endl;
					vect_size = vect.size();

					//cout << strNew << "  <= " << endl;
					line_.erase(firstQuotePos, secondQuotePos);
				}
				//std::cout << line_ << '\n';

				//if (line_.find(delimiter) != std::string::npos) {
					while ((pos = line_.find(delimiter)) != std::string::npos)
					{
						token = line_.substr(0, pos);
						line_.erase(0, pos + delimiter.length());
						//std::cout << line_ << std::endl;
						token.erase(remove_if(token.begin(), token.end(), isspace), token.end());
						//inputList.iplist(token);//right one
						//result.push_back(token);
						//op_Vec.push_back(token);
						//cout << token << endl;
						for (int a = 0; a < vect_size; a++) {
							std::stringstream str;
							str << token << "(" << a << ")";
							op_vector = str.str();
							op_Vec.push_back(op_vector);
							//cout << op_vector << endl;
						}
					
					
					}
				//}
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				for (int a = 0; a < vect_size; a++) {
					std::stringstream str;
					str << line_ << "(" << a << ")";
					op_vector = str.str();
					op_Vec.push_back(op_vector);
					//cout << op_vector << endl;
				}
				//inputList.iplist(line_);
				//result.push_back(line_);
				//op_Vec.push_back(line_);
				//cout << line_ << endl;

				
			}
			
			//////////////////////////////
			//extracting output port
			///////////////////////////

			if ((read_line.find(opPort) != std::string::npos) && (read_line.find(opVec1) == std::string::npos))
			{
				//std::string::size_type i = line_.find(ipPort);
				std::cout << "\nOUTPUT PORT" << '\n';
				std::string regex = ");";
				//if (i != std::string::npos)
				
				line_.erase(line_.find(regex), regex.length());
				line_.erase(line_.find(opPort), opPort.length());

				line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
				//cout << line_ << "okk" << endl;

				//std::cout << line_ << '\n';
				while ((pos = line_.find(delimiter)) != std::string::npos)
				{
					//line_.erase(std::remove(line_.begin(), line_.end(), ' '));
					token = line_.substr(0, pos);
					token.erase(remove_if(token.begin(), token.end(), isspace), token.end());
					std::cout << token << std::endl;
					line_.erase(0, pos + delimiter.length());
					//std::cout << line_ << std::endl;
					//result.push_back(token);
					//listing("output", token);
					//op_result.push_back(token);
					//outputList.oplist(token);
					op_Vec.push_back(token);
				}
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				op_Vec.push_back(line_);
				//std::cout << line_ << std::endl;
				//result.push_back(line_);
				//outputList.oplist(token);
				//op_result.push_back(line_);
				//listing("output", line_);
				/*std::list<std::string>::iterator it = result.begin();
				std::advance(it, 4);
				std::cout << "3rd element = " << *it << std::endl;

				for (auto v : result)
					std::cout << v << "\n";*/
					//listing ();
				for (auto v : op_Vec)
					std::cout << v << "\n";
			}


			//////////////////////////
			//exreating wire or signal
			////////////////////////////

			if ((read_line.find("signal") != std::string::npos) || (read_line.find(": std_logic") != std::string::npos))
			{
				std::string signal = "signal";
				std::string signal_1 = ": std_logic;";
				//std::string::size_type i = line_.find(ipPort);
				std::cout << "\nSIGNAL PIN" << '\n';
				//if (i != std::string::npos)
				line_.erase(line_.find(signal), signal.length());
				line_.erase(line_.find(signal_1), signal_1.length());
				line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());

				//std::cout << line_ << '\n';
				while ((pos = line_.find(delimiter)) != std::string::npos)
				{
					//line_.erase(std::remove(line_.begin(), line_.end(), ' '));
					token = line_.substr(0, pos);
					token.erase(remove_if(token.begin(), token.end(), isspace), token.end());
					std::cout << token << std::endl;
					line_.erase(0, pos + delimiter.length());
					//std::cout << line_ << std::endl;
					result.push_back(token);
					//listing("wire", token);
					wireList.wirelist(token);
				}
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				std::cout << line_ << std::endl;
				result.push_back(line_);
				wireList.wirelist(token);
				//listing("wire", line_);
				/*std::list<std::string>::iterator it = result.begin();
				std::advance(it, 4);
				std::cout << "3rd element = " << *it << std::endl;

				for (auto v : result)
					std::cout << v << "\n";*/
					//listing ();

			}

		
			//////////////////
			// sorting list information
			////////////////////////
			if ((read_line.find("begin") != std::string::npos)) 
			{
				std::cout << "\nFunction" << endl;
				std::string delimiter = "begin";
				std::string data_ = accumulate(istream_iterator<char>{ file_ >> noskipws }, {}, string{});
				while ((pos = data_.find(delimiter)) != std::string::npos) {
					token = data_.substr(0, pos);
					//std::cout << token <<"okk"<<endl;
					data_.erase(0, pos + delimiter.length());
				}
				//std::cout << data_ << std::endl;
				std::string mystr = data_.substr(0, data_.find("end", 0));
				//std::cout <<"uff" << mystr << std::endl;
				
				std::string token_n;
				std::string delimiter1 = ";";
				std::string delimiter2 = ":";
				std::string delimiter3 = " ";
				std::string delimiter4 = "A => ";
				std::string delimiter5 = "B => ";
				std::string delimiter6 = "Z => ";
				std::string delimiter7 = "A1 => ";
				std::string delimiter8 = "B1 => ";
				std::string delimiter9 = "ZN => ";
				//std::string delimiter9 = "A2 => ";
				//std::string delimiter9 = "B2 => ";

				while ((pos = mystr.find(delimiter1)) != std::string::npos) {
					token = mystr.substr(0, pos);
					token = token + ";";
					//token.erase(remove_if(token.begin(), token.end(), isspace), token.end());
					//std::cout <<" yeh " << token << std::endl;
					mystr.erase(0, pos + delimiter1.length());
					//cout << "looo" << mystr << endl;
					
					if ((pos = token.find(delimiter1)) != std::string::npos) {
						token_n = token.substr(0, pos);
						string output = token_n.substr(token_n.find_last_of(':') + 1);
						string strNew1;
						string strNew2;
						string strNew3;
						string strNew4;
						string strNew5;
						string strNew6;
						string tempstr;
						
						if ((pos = output.find(delimiter4)) != std::string::npos) {
						unsigned first = output.find(delimiter4);
						unsigned last = output.find_first_of(",");
						strNew1 = output.substr(first, last - first);
						strNew1.erase(0, 5);
						cout <<delimiter4<<" "<< strNew1 << endl;
						if ((pos = output.find(delimiter5)) != std::string::npos) {
							unsigned first = output.find(delimiter5);
							unsigned last = output.find_last_of(",");
							strNew2 = output.substr(first, last - first);
							strNew2.erase(0, 5);
							cout <<delimiter5<<" "<< strNew2 << endl;
						}

					    }
						if ((pos = output.find(delimiter7)) != std::string::npos) {
							unsigned first = output.find(delimiter7);
							unsigned last = output.find_first_of(",");
							strNew3 = output.substr(first, last - first);
							strNew3.erase(0, 6);
							cout << delimiter7 << " " << strNew3 << endl;
							if ((pos = output.find("A2")) != std::string::npos) {
								//unsigned first = output.find("A2");
								std::size_t pos = output.find("A2 => ");
								
								tempstr = output.substr(pos);
								unsigned first = tempstr.find("A2 => ");
								unsigned last = tempstr.find_first_of(",");
								strNew4 = tempstr.substr(first, last - first);
								strNew4.erase(0, 6);
								cout << "A2 =>" << " " << strNew4 << endl;
							}
							if ((pos = output.find(delimiter8)) != std::string::npos) {
								tempstr.clear();
								std::size_t pos = output.find(delimiter8);
								tempstr = output.substr(pos);
								unsigned first = tempstr.find(delimiter8);
								unsigned last = tempstr.find_first_of(",");
								strNew5 = tempstr.substr(first, last - first);
								strNew5.erase(0, 6);
								cout << delimiter8 << " " << strNew5 << endl;
							}
							if ((pos = output.find("B2")) != std::string::npos) {
								unsigned first = output.find("B2 =>");
								unsigned last = output.find_last_of(",");
								strNew6 = output.substr(first, last - first);
								strNew6.erase(0, 6);
								cout << "B2 => " << " " << strNew6 << endl;
							}

						}
					/*	std::list<string> error;
						std::list<string> error1;
						error.clear();
						if ((pos = output.find(delimiter4)) == std::string::npos) {
							for (int a = 0; a < ip_Vec.size(); a++) {
								auto it1 = std::next(ip_Vec.begin(), a);
								//cout << delimiter5 << " " << strNew2 << endl;
								if (output.find(*it1) != std::string::npos) {
									error.push_back(output);
									cout << " poo" << output << endl;
									//sorting_list2.push_front(output);
								}
							}
						}
						*/
						//cout << strNew1 <<";p;"<< endl;
						/*std::list<std::string>::iterator it;
						it = std::find(ip_Vec.begin(), ip_Vec.end(), strNew1);*/
						bool foundA = (std::find(ip_Vec.begin(), ip_Vec.end(), strNew1) != ip_Vec.end());
						bool foundB = (std::find(ip_Vec.begin(), ip_Vec.end(), strNew2) != ip_Vec.end());
						bool foundC = (std::find(ip_Vec.begin(), ip_Vec.end(), strNew3) != ip_Vec.end());
						bool foundD = (std::find(ip_Vec.begin(), ip_Vec.end(), strNew4) != ip_Vec.end());
						bool foundE = (std::find(ip_Vec.begin(), ip_Vec.end(), strNew5) != ip_Vec.end());
						bool foundF = (std::find(ip_Vec.begin(), ip_Vec.end(), strNew6) != ip_Vec.end());
						/*if (foundA == true && strNew2.empty()) { 
							sorting_list.push_front(output); }*/
						
						if (!strNew1.empty()) {
							if ((foundA == true && strNew2.empty()) || (foundA==true && foundB==true)) {
								sorting_list.push_front(output);
								/*if (strNew2.empty()) sorting_list.push_front(output);
								else if (foundB == true) sorting_list.push_front(output);
								else if (foundB != true) sorting_list.push_back(output);
								else sorting_list.push_back(output);*/
								//sorting_list.push_front(output);
								//cout << "hmmm" << output << endl;
							}
							
							else if (foundA != true && foundB != true) {

								sorting_Nomatch_list.push_back(output);
							}
							else if((foundA==true && foundB !=true) || (foundA !=true && foundB ==true)) { 
								std::list<std::string>::iterator it;

								// Fetch the iterator of element with value 'output'
								it = std::find(sorting_list.begin(), sorting_list.end(), output);

								// Check if iterator points to end or not
								if (it != sorting_list.end())
								{
									// It does not point to end, it means element exists in list
									//std::cout << "'the' exists in list " << std::endl;
								}
								else
								{
									// It points to end, it means element does not exists in list
									sorting_list.push_back(output);
								}
								
							}
							//strNew1.empty();
							//strNew1.clear();
						}
						
						
						/*if ((foundA == true && foundB != true) || (foundA != true && foundB == true)) {
							sorting_list.push_back(output);
						}*/
						std::list<string> error;
						std::list<string> error1;
						error.clear();
						int out_str;
						if (!strNew3.empty()) {
							if (foundC == true && foundD == true && foundE == true && foundF == true) {
								sorting_list.push_front(output);
							}
							else if (foundC != true && foundD != true && foundE != true && foundF != true) {
								sorting_Nomatch_list.push_back(output);
							}
							else if ((foundC == true && foundD == true) && (foundE == true || foundF == true)) {
								sorting_list.push_back(output);

								//	for (int a = 0; a < ip_Vec.size(); a++){
							//		auto it1 = std::next(ip_Vec.begin(), a);
							//		cout << "lk" << *it1 << endl;
							//	if (output.find(*it1) != std::string::npos) {
							//		error.push_back(output);
							//		cout << " poo" << output << endl;
							//		//sorting_list2.push_front(output);
							//	}
							//	else { error1.push_back(output); }
							//	
							//	
							//}
							//	if (error.empty()) { sorting_list2.push_back(output); }
							//	if (error.size() > 0) for (auto v : error) sorting_list2.push_front(v);
							}
							else if ((foundC == true || foundD == true) && (foundE == true && foundF == true)) {
								sorting_list.push_back(output); // 3 known entities
							}
							else if ((foundC != true && foundD != true) && (foundE == true && foundF == true)) {
								sorting_list2.push_front(output); // 2 known entities
							}
							else if ((foundC == true && foundD == true) && (foundE != true && foundF != true)) {
								sorting_list2.push_front(output); // 2 known entities
							}
							
							else if (!(foundC == true && foundE == true) && (foundD == true && foundF == true)) {
								sorting_list2.push_front(output); // 2 known entities
							}

							else if ((foundC == true && foundE == true) && !(foundD == true && foundF == true)) {
								sorting_list2.push_front(output); // 2 known entities
							}
							else if ((foundC == true && foundF == true) && !(foundD == true && foundE == true)) {
								sorting_list2.push_front(output); // 2 known entities
							}
							else if ((foundD == true && foundE == true) && !(foundC == true && foundF == true)) {
								sorting_list2.push_front(output); // 2 known entities
							}
							else if ((foundC == true || foundD == true) && !(foundE == true && foundF == true) && !(foundC ==true && foundD ==true)) {
								sorting_Nomatch_list.push_front(output); // 1 known entities
							}
							else if (!(foundC == true && foundD == true) && (foundE == true || foundF == true) && !(foundE == true && foundF == true)) {
								sorting_Nomatch_list.push_front(output); // 1 known entities
							}
							

						}
						//else sorting_list2.push_back(output);

						//sorting_list.push_back(output);
						//cout << " token1 : "<< output << endl;
						////token_n.erase(remove_if(token_n.begin(), token_n.end(), isspace ), token_n.end());
						//cout << " token1 : " << token_n << endl;
						//cout << " token1 :" << token_n << endl;
						//token.substr(token.find("<=") + 1);
						//**functionSeparate.push_back(token_n);
						//std::cout << token1 << " " << token<<std::endl;
						//**std::string extension = "";
						//**size_t pos = token.find_last_of(delimiter2);
						// make sure the poisition is valid
						/*if (pos != string::npos)
							extension = token.substr(pos + 1);*/
						//////////////////
						// split function
						/////////////
						
						//std::istringstream buf(extension);
						//std::istream_iterator<std::string> beg(buf), end;

						//std::vector<std::string> listArrayVector(beg, end); // done!

						/*for (auto& s : listArrayVector)
							std::cout << s << '\n';*/
						////if (listArrayVector.size() <= 3) {
						////	std::string gate = listArrayVector[1];
						////	int val1 = hashGateValue[listArrayVector[0]];
						////	int val2 = hashGateValue[listArrayVector[2]];
						////	cout << gate << endl; //"   oooooooo  :" << token_n << endl;
						////	int new_value = gatefunction.gate(val1, val2, gate);
						////	//hashGateValue.insert(token_n, new_value);
						////	hashGateValue.insert_or_assign(token_n, new_value);
						////	
						////	//hashGateValue.emplace(token_n, new_value);
						////	
						////	cout<< new_value<<endl;
						//////	cout << hashGateValue["a1"] << "   " << hashGateValue["a2"] << "  " << hashGateValue["a3"] << endl;
						////}
						
						//cout << hashGateValue["a1"] << "   " << hashGateValue["a2"] << "  " << hashGateValue["a3"] << endl;
						//cout << listArrayVector[1] <<listArrayVector.size() << endl;
						//cout << "S " << hashGateValue["S"] << "== Cout:   " << hashGateValue["Cout"] << endl;
						


						//cout << extension<<" l" << endl;

					}
					
					//gateData.dataTostore(token);
					
				}
				//std::cout << mystr << std::endl;
				//gateData.dataTostore(token);
			//display the result
				cout << "\nRESULT" << endl;
				
				
				for (auto v : sorting_list2)
					sorting_list.push_back(v);
				for (auto v : sorting_Nomatch_list)
					sorting_list.push_back(v);
					//std::cout << v << endl;
				for (auto v : sorting_list)
					std::cout << v << endl;
				/*cout << "\nRESULT 2" << endl;
				for (auto v : sorting_list2)
					std::cout << v << endl;
				cout << "\nRESULT No" << endl;
				for (auto v : sorting_Nomatch_list)
					std::cout << v << endl;*/
				/*for (auto v : op_result)
					std::cout << v << ": " << hashGateValue[v] << endl;*/
				for (int a = 0; a < sorting_list.size(); a++) {// (read_line.find("begin") != std::string::npos));
				
					//cout << a << sorting_list.get_allocator(a) << endl;
					auto it1 = std::next(sorting_list.begin(), a);

					std::cout << "3rd element = " << *it1 << std::endl;
				
				}


				
			}
			
		}
		file_.close();

	}
	
	else
	
		std::cout << "file is not open" << '\n';
		std::cin.get();
		return 0;
	
}