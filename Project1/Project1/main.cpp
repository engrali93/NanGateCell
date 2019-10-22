//("D:\\project arbeit\\files\\file1.txt");

#include <iostream>
#include <fstream>
#include<string>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <sstream>
#include <cctype>
#include <regex>
#include "NanGateCell.h"
#include <stdio.h>
#include "sdf.h"





using namespace std;



template<typename Out>

void split(const std::string &s, char delim, Out result) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

std::vector<std::vector<int> > truthtable(const unsigned num) {
	
	const unsigned n = num;
	std::vector<std::vector<int> > output(n, std::vector<int>(1 << n));

	unsigned num_to_fill = 1U << (n - 1);
	for (unsigned col = 0; col < n; ++col, num_to_fill >>= 1U)
	{
		for (unsigned row = num_to_fill; row < (1U << n); row += (num_to_fill * 2))
		{
			std::fill_n(&output[col][row], num_to_fill, 1);
		}
	}


	return output;
}


int main();

std::vector<string> funcVector_split(string function_data);

string spliting_port(string input_string) {
	std::string ipPort = "in std_logic;";
	
	std::string port = "port(";
	std::string line_ = input_string;
	line_.erase(line_.find(port), port.length());
	line_.erase(line_.find(ipPort), ipPort.length());
	line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
	
	return line_;

}


string spliting_input_port(string input_str) {
	std::string line_ = input_str;
	std::string ipVec1 = "in std_logic_vector";

	line_.erase(line_.find(ipVec1), ipVec1.length());
	line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
	std::string::size_type firstQuotePos = line_.find_first_of("(");
	std::string::size_type secondQuotePos = line_.find_first_of(")");

	return line_;
}

string spliting_output_port(string output_string) {
	std::string line_ = output_string;
	std::string opVec1 = "out std_logic_vector";
	line_.erase(line_.find(opVec1), opVec1.length());
	line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());

	return line_;
}

string spliting_signal(string signal) {
	std::string line_ = signal;
	std::string signalm = "signal";
	std::string signal_1 = ": std_logic;";
	//std::string::size_type i = line_.find(ipPort);
	
	//if (i != std::string::npos)
	line_.erase(line_.find(signalm), signalm.length());
	line_.erase(line_.find(signal_1), signal_1.length());
	line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
	
	return line_;
}

unordered_map<int, vector<int>> truthtable_map(int co, vector<std::vector<int> > truthtable_output) {
	unordered_map<int, vector<int>> result;
	vector<int> bit;
	for (unsigned x = 0; x < (1 << co); ++x)
	{
		for (unsigned y = 0; y < co; ++y)
		{
			bit.push_back(truthtable_output[y][x]);
			//std::cout << truthtable_output[y][x] << " " << "<=";

		}
		result.emplace(x, bit);
		bit.clear();
		//std::cout << std::endl;
	}

	return result;
}


int main()
{
	
	

	
	
	NanGateCell nangatecell;
	unordered_map<string, int> hashGateValue;
	unordered_map<string, int, int> hashFunction2in;
	unordered_map<string, int, int,int> hashFunction3in;
	unordered_map<string, string, string, string> hashsorting;
	unordered_map<int, vector<int>> running_loop;
	unordered_map<string, int> hash_Temp;
	unordered_map<string, string> pin_port;
	std::list<string> sort_acc_ip;
	std::list<string> functionSeparate;
	vector<string> vhdlfunction_data;
	std::vector<int> Vector;
	std::vector<int> vect;
	std::vector<string> all_possible_ports;
	unordered_map<int, unordered_map<string, int>> truth_sheet;
	std::vector<string> instance_str;
	std::list<string> result;
	std::list<string> op_result;
	std::vector<string> ip_Vec;
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
	std::string for_sdf;
	int vect_size;
	int result_temp;
	int io = 0;
	size_t pos = 0;
	std::string token;
	//ifstream file_("D:/project arbeit/files/full_adder_vhdl/full_add.vhd");
	
	
	string loc = "D:/project arbeit/files/2-bit/exact_adder_cla_T=2_TECH=freepdk45tc_B=2.sdf";
	string out_result = "D:/project arbeit/Output_Result/result.txt";
	string sdf_result = "D:/project arbeit/Output_Result/sdf_result.txt";


	ifstream file_("D:/project arbeit/files/2-bit/exact_adder_cla_T=2_TECH=freepdk45tc_B=2.vhd"); // 2 BIT
	//ifstream file_("D:/project arbeit/files/2-bit/4-bit/exact_adder_rpl_T=2_TECH=freepdk45tc_B=4.vhd"); // 4 BIT
	//ifstream file_("D:/project arbeit/files/2-bit/8-bit/exact_adder_rpl_T=2_TECH=freepdk45tc_B=8.vhd"); // 8 bit
	
	if (file_.is_open())
	{
		while (getline(file_, line_))
		{
			//std::cout << "here is the line" << '\n';
			read_line = line_;
			std::string ipPort = "in std_logic;";
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
				line_ = spliting_port(line_);
				//std::string::size_type i = line_.find(ipPort);
			

				//std::cout << line_ << '\n';
				while ((pos = line_.find(delimiter)) != std::string::npos)
				{
					//line_.erase(std::remove(line_.begin(), line_.end(), ' '));
					token = line_.substr(0, pos);
					//std::cout << token << std::endl;
					line_.erase(0, pos + delimiter.length());
					std::cout << line_ << std::endl;
					
					token.erase(remove_if(token.begin(), token.end(), isspace), token.end());
				
					result.push_back(token);
					ip_Vec.push_back(token);
					//cout << token;



				}
				
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
		
				result.push_back(line_);
				ip_Vec.push_back(line_);

			}




			////////////////////////////////////
			//////// input Vector
			/////////////////////////

			if (read_line.find(ipVec1) != std::string::npos)
			{
				std::cout << "\nINPUT Vector" << endl;
				//line_.erase(line_.find(port), port.length());

				/*line_.erase(line_.find(ipVec1), ipVec1.length());
				line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
				*/
				line_ = spliting_input_port(line_);
				std::string::size_type firstQuotePos = line_.find_first_of("(");
				std::string::size_type secondQuotePos = line_.find_first_of(")");


				if (firstQuotePos != std::string::npos)
				{
					string strNew = line_.substr(firstQuotePos, secondQuotePos);
					strNew.erase(strNew.begin() + 0);
					stringstream ss;
					ss << strNew;
					string temp;
					int found;
					/*std::vector<int> vect;*/
					//*cout << "downto" << endl;
					while (!ss.eof()) {

						/* extracting word by word from stream */
						ss >> temp;

						/* Checking the given word is integer or not */
						if (stringstream(temp) >> found)
						//*#	cout << found << " ";

						vect.push_back(found);
						//cout << vect.size();
						/* To save from space at the end of string */
						temp = "";
					}
					//cout << "for" << vect.size();
					//int str = vect.at(0);


					if (vect.size() > 2)  vect.erase(vect.begin() + 2, vect.end());
					
						//*cout <<vect.size()<<"yr"<< endl;
					//#cout << "\n";
					//vect_size = vect.size();
					vect_size = vect.at(0) + 1; //calulating bit
					//cout << vect_size;
					//cout << strNew << "  <= " << endl;
					line_.erase(firstQuotePos, secondQuotePos);
				}
				//std::cout << line_ <<'\n';
				while ((pos = line_.find(delimiter)) != std::string::npos)
				{
					token = line_.substr(0, pos);
					line_.erase(0, pos + delimiter.length());

					token.erase(remove_if(token.begin(), token.end(), isspace), token.end());
				

					for (int a = 0; a < vect_size; a++) {
						std::stringstream str;
						str << token << "(" << a << ")";
						ip_vector = str.str();
						ip_Vec.push_back(ip_vector);
						all_possible_ports.push_back(ip_vector);
						//cout << ip_vector<< endl;
					}
				}
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				for (int a = 0; a < vect_size; a++) {
					std::stringstream str;
					str << line_ << "(" << a << ")";
					ip_vector = str.str();
					ip_Vec.push_back(ip_vector);
					all_possible_ports.push_back(ip_vector);
					//cout << ip_vector << endl;
				}



				for (auto v : ip_Vec)
					std::cout << v << "\n";

				int co;

				co = ip_Vec.size();
				//*cout << co << endl;
				///////////////////////////
				std::vector<std::vector<int> > truthtable_output = truthtable(co);
				
				
				// These loops just print out the results, nothing more.
				 running_loop = truthtable_map(co, truthtable_output);
				int loop_wrt_answer = running_loop.size();
				
				//for (int u = 0; u < loop_wrt_answer; u++) {
					//vector<int> bits_vec = running_loop[u];

					//==============================================
				//*	cout << "\nType in a list of inputs (" << co << " ) " << endl;
					//std::list<std::string>::iterator it = ip_Vec.begin();


					int input = 0;
				
					//cin.get();

					//inputVectorNew.myVector(co);	
				}

			

				


				//////////////////////////////////
				//////// output vector
				///////////////////////////////////

				if (read_line.find(opVec1) != std::string::npos)
				{
					vect.clear();
					line_ = spliting_output_port(line_);
					//*std::cout << "\nOUTPUT Vector" << endl;
					//line_.erase(line_.find(port), port.length());
				
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
						//*#cout << vect.size() << "or" << endl;
						//vect_size = vect.size();
						vect_size = vect.at(0) + 1;
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

						op_Vec.push_back(token);
					}
					line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
					op_Vec.push_back(line_);

					for (auto v : op_Vec)
						std::cout << v << "\n";
				}


				//////////////////////////
				//extracting wire or signal
				////////////////////////////

				if ((read_line.find("signal") != std::string::npos) || (read_line.find(": std_logic") != std::string::npos))
				{
					//*std::string signal = "signal";
					//*std::string signal_1 = ": std_logic;";
					//std::string::size_type i = line_.find(ipPort);
					std::cout << "\nSIGNAL PIN" << '\n';
					//if (i != std::string::npos)
					//*line_.erase(line_.find(signal), signal.length());
					//*line_.erase(line_.find(signal_1), signal_1.length());
					//*line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
					line_ = spliting_signal(line_);
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
						//*wireList.wirelist(token);
					}
					line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
					std::cout << line_ << std::endl;
					result.push_back(line_);

					//*wireList.wirelist(token);
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
					//*std::cout << "\nFunction" << endl;
					std::string delimiter = "begin";
					std::string data_ = accumulate(istream_iterator<char>{ file_ >> noskipws }, {}, string{});
					while ((pos = data_.find(delimiter)) != std::string::npos) {
						token = data_.substr(0, pos);
						//std::cout << token <<"okk"<<endl;
						data_.erase(0, pos + delimiter.length());
					}
					//std::cout << data_ << std::endl;
					std::string mystr = data_.substr(0, data_.find("end", 0));
					for_sdf = mystr;
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
							instance_str.push_back(token_n);
							string strNew1;
							string strNew2;
							string strNew3;
							string strNew4;
							string strNew5;
							string strNew6;
							string strNew7;
							string strNew8;
							string tempstr;

							if ((pos = output.find(delimiter4)) != std::string::npos) {
								unsigned first = output.find(delimiter4);
								unsigned last = output.find_first_of(",");
								strNew1 = output.substr(first, last - first);
								strNew1.erase(0, 5);
								//*pin_port.emplace(strNew1, "A");
								//*cout <<delimiter4<<" "<< strNew1 << endl;
								if ((pos = output.find(delimiter5)) != std::string::npos) {
									unsigned first = output.find(delimiter5);
									unsigned last = output.find_last_of(",");
									strNew2 = output.substr(first, last - first);
									strNew2.erase(0, 5);
									//*pin_port.emplace(strNew2, "B");
								//*	cout <<delimiter5<<" "<< strNew2 << endl;
								}
								if ((pos = output.find(delimiter9)) != std::string::npos) {
									unsigned first = output.find(delimiter9);
									unsigned last = output.find_last_of(",");
									strNew8 = output.substr(first, last - first);
									strNew8.erase(0, 5);
									//cout << strNew8.size();
									strNew8.erase(strNew8.size() - 1, 1);

									//pin_port.emplace(strNew8, "ZN");
									//*cout << delimiter9 << " " << strNew8 << endl;
								}

								if ((pos = output.find(delimiter6)) != std::string::npos) {
									unsigned first = output.find(delimiter6);
									unsigned last = output.find_last_of(",");
									strNew7 = output.substr(first, last - first);
									strNew7.erase(0, 5);
									//cout << strNew7.size();
									strNew7.erase(strNew7.size() - 1, 1);
									//pin_port.emplace(strNew7, "Z");
										//*cout <<delimiter6<<" "<< strNew7 << endl;
								}

							}
							if ((pos = output.find(delimiter7)) != std::string::npos) {
								unsigned first = output.find(delimiter7);
								unsigned last = output.find_first_of(",");
								strNew3 = output.substr(first, last - first);
								strNew3.erase(0, 6);
								//*pin_port.emplace(strNew3, "A1");
								//*cout << delimiter7 << " " << strNew3 << endl;
								if ((pos = output.find("A2")) != std::string::npos) {
									//unsigned first = output.find("A2");
									std::size_t pos = output.find("A2 => ");

									tempstr = output.substr(pos);
									unsigned first = tempstr.find("A2 => ");
									unsigned last = tempstr.find_first_of(",");
									strNew4 = tempstr.substr(first, last - first);
									strNew4.erase(0, 6);
									//*pin_port.emplace(strNew4, "A2");
									//*cout << "A2 =>" << " " << strNew4 << endl;
								}
								if ((pos = output.find(delimiter8)) != std::string::npos) {
									tempstr.clear();
									std::size_t pos = output.find(delimiter8);
									tempstr = output.substr(pos);
									unsigned first = tempstr.find(delimiter8);
									unsigned last = tempstr.find_first_of(",");
									strNew5 = tempstr.substr(first, last - first);
									strNew5.erase(0, 6);
									//*pin_port.emplace(strNew5, "B1");
									//*cout << delimiter8 << " " << strNew5 << endl;
								}
								if ((pos = output.find("B2")) != std::string::npos) {
									unsigned first = output.find("B2 =>");
									unsigned last = output.find_last_of(",");
									strNew6 = output.substr(first, last - first);
									strNew6.erase(0, 6);
									//*pin_port.emplace(strNew6, "B2");
									//cout << "B2 => " << " " << strNew6 << endl;
								}
								if ((pos = output.find(delimiter9)) != std::string::npos) {
									unsigned first = output.find(delimiter9);
									unsigned last = output.find_last_of(",");
									strNew8 = output.substr(first, last - first);
									strNew8.erase(0, 5);
									//cout << strNew8.size();
									strNew8.erase(strNew8.size() - 1, 1);

									//pin_port.emplace(strNew8, "ZN");
									//*cout <<delimiter9<<" "<< strNew8 << endl;
								}
							}

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
								if ((foundA == true && strNew2.empty()) || (foundA == true && foundB == true)) {
									sorting_list.push_front(output);
									
								}

								else if (foundA != true && foundB != true) {

									sorting_Nomatch_list.push_back(output);
								}
								else if ((foundA == true && foundB != true) || (foundA != true && foundB == true)) {
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
								
							}


							
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
								else if ((foundC == true || foundD == true) && !(foundE == true && foundF == true) && !(foundC == true && foundD == true)) {
									sorting_Nomatch_list.push_front(output); // 1 known entities
								}
								else if (!(foundC == true && foundD == true) && (foundE == true || foundF == true) && !(foundE == true && foundF == true)) {
									sorting_Nomatch_list.push_front(output); // 1 known entities
								}


							}



						}



					}

					//for sorting the result

					cout << "\nSORTING RESULT" << endl;


					for (auto v : sorting_list2)
						sorting_list.push_back(v);
					for (auto v : sorting_Nomatch_list)
						sorting_list.push_back(v);
					//std::cout << v << endl;
					for (auto v : sorting_list)
						std::cout << v << endl;

					



				}


				

				

				


			}
			file_.close();
			cout << endl;
			cout << "====== PLEASE WAIT ======" << endl;
			for (int u = 0; u < running_loop.size(); u++) {
				vector<int> bits_vec = running_loop[u];
				hashGateValue.clear();
				Vector.clear();
				//cout << u << " huwa " << endl;
				for (int h = 0; h < bits_vec.size(); h++) {

					//cout << ip_Vec.at(h) << " lll " << bits_vec.at(h) << endl;
					hashGateValue.emplace(ip_Vec.at(h), bits_vec.at(h));
					Vector.push_back(bits_vec.at(h));
				}


				for (auto v : sorting_list) {
					std::string a;
					a = v;



					if ((pos = a.find("port map")) != std::string::npos) {
						//std::size_t position = a.find(":");
						//a.erase(remove_if(a.begin(), a.end(), isspace), a.end());

						size_t pos = a.find("port map");
						//size_t pos1 = a.find("(");
						string str = a.substr(pos + 8); // gate data
						string str1 = a.erase(pos);//gate name
						/*str.erase(0,1);
						str.erase(str.size()-1);*/
						str = str.substr(1, str.size() - 2);
						str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
						str1.erase(remove_if(str1.begin(), str1.end(), isspace), str1.end());


						//*cout << str <<endl;
						//*cout << str1 << endl;
						//nangatecell.gate(str, str1);
						std::vector<std::string> x = split(str, ',');
						std::vector<std::string> port_data;
						//cout << "vector size " << x.size();
						//for (auto v : x)  cout << v << endl;
						for (int i = 0; i < (int)x.size(); i++) {
							size_t pos = x.at(i).find("=>");
							port_data.push_back(x.at(i).substr(pos + 2));
							//cout << x.at(i).substr(pos+2) << endl;
						}
						/*for (int i = 0; i< port_data.size(); i++) {
							cout << port_data.at(i) << endl;
						}*/
						if (port_data.size() == 2) {
							for (int i = 0; i < 3; i++)
								port_data.push_back("NULL");
						}
						if (port_data.size() == 3) {
							for (int i = 0; i < 2; i++)
								port_data.push_back("NULL");
						}
						if (port_data.size() == 4) {
							for (int i = 0; i < 1; i++)
								port_data.push_back("NULL");
						}
						string special_gate;

						string gate_type = " FA_X1 , HA_X1 ";
						if ((port_data.size() == 5) && ((pos = gate_type.find(str1)) != std::string::npos)) {

							special_gate = "yes";
						}
						//cout << special_gate << endl;
						//cout << port_data.size();

						//*for (auto v : port_data)cout << v << endl;
						int mycount = std::count(port_data.begin(), port_data.end(), "NULL");
						//cout <<"\n"<< mycount << endl;


						if (mycount == 3) { // values


							if ((hashGateValue.find(port_data.at(0)) != hashGateValue.end())) {

								int x_temp = nangatecell.gate(str1, hashGateValue[port_data[0]], 0, 0, 0, 0);

								hashGateValue.emplace(port_data.at(1), x_temp);
								//cout << " matched " <<hashGateValue[port_data[1]] << port_data.at(1)<<endl;

							}


						}

						if (mycount == 2) {

							//cout << port_data.at(i) << endl;

							if ((hashGateValue.find(port_data.at(0)) != hashGateValue.end()) && (hashGateValue.find(port_data.at(1)) != hashGateValue.end())) {

								int x_temp = nangatecell.gate(str1, hashGateValue[port_data[0]], hashGateValue[port_data[1]], 0, 0, 0);
								hashGateValue.emplace(port_data.at(2), x_temp);
								//cout << " matched " << hashGateValue[port_data[2]] << port_data.at(2) <<","<<port_data.at(0)<<port_data.at(1)<< endl;

							}

						}

						if (mycount == 1) {

							//cout << port_data.at(i) << endl;

							if ((hashGateValue.find(port_data.at(0)) != hashGateValue.end()) && (hashGateValue.find(port_data.at(1)) != hashGateValue.end()) && (hashGateValue.find(port_data.at(2)) != hashGateValue.end())) {

								int x_temp = nangatecell.gate(str1, hashGateValue[port_data[0]], hashGateValue[port_data[1]], hashGateValue[port_data[2]], 0, 0);
								hashGateValue.emplace(port_data.at(3), x_temp);
								//cout << " matched " << hashGateValue[port_data[3]] << port_data.at(3) << "," << port_data.at(0) << port_data.at(1) << port_data.at(2)<< endl;

							}

						}
						if ((mycount == 0) && (special_gate == "yes")) {



							if ((hashGateValue.find(port_data.at(0)) != hashGateValue.end()) && (hashGateValue.find(port_data.at(1)) != hashGateValue.end())
								&& (hashGateValue.find(port_data.at(2)) != hashGateValue.end()))
							{

								int x_temp = nangatecell.gate(str1, hashGateValue[port_data[0]], hashGateValue[port_data[1]], hashGateValue[port_data[2]], 0, 0);
								cout << "1xtemp" << x_temp << endl;
								if (x_temp == 1) {
									cout << "xtemp" << x_temp << endl;
									hashGateValue.emplace(port_data.at(3), 0);
									hashGateValue.emplace(port_data.at(4), 1);
								}
								if (x_temp == 2) {
									hashGateValue.emplace(port_data.at(3), 1);
									hashGateValue.emplace(port_data.at(4), 0);
								}
								if (x_temp == 3) {
									hashGateValue.emplace(port_data.at(3), 1);
									hashGateValue.emplace(port_data.at(4), 1);
								}
								else {
									hashGateValue.emplace(port_data.at(3), 0);
									hashGateValue.emplace(port_data.at(4), 0);
								}

								//cout << " matched " << hashGateValue[port_data[3]] << port_data.at(3) << hashGateValue[port_data[4]] << port_data.at(4)<< endl;

							}



						}
						if ((mycount == 0) && (special_gate.empty())) {

							/*cout << port_data.at(0) << endl;
							cout << port_data.at(1) << endl;
							cout << port_data.at(2) << endl;
							cout << port_data.at(3) << endl;*/
							/*cout << hashGateValue[port_data.at(0)] << endl;
							cout << hashGateValue[port_data.at(1)] << endl;
							cout << hashGateValue[port_data.at(2)] << endl;
							cout << hashGateValue[port_data.at(3)] << endl;
	*/
							if ((hashGateValue.find(port_data.at(0)) != hashGateValue.end()) && (hashGateValue.find(port_data.at(1)) != hashGateValue.end())
								&& (hashGateValue.find(port_data.at(2)) != hashGateValue.end())
								&& (hashGateValue.find(port_data.at(3)) != hashGateValue.end()))
							{

								int x_temp = nangatecell.gate(str1, hashGateValue[port_data[0]], hashGateValue[port_data[1]], hashGateValue[port_data[2]], hashGateValue[port_data[3]], 0);
								hashGateValue.emplace(port_data.at(4), x_temp);
								//cout << " matched " << hashGateValue[port_data[4]] << port_data.at(4) << endl;

							}

							else {
								cout << " Error: values are missing" << endl;
							}

						}

						//nangatecell.gate(str1,)
					}
					//cout << "next"<< endl;
				}

			//*#	cout << "\n~~THE OUTPUT RESULTS ARE~~" << endl;
			//*#	for (auto v : op_Vec)
			//*#		cout << v << " : " << hashGateValue[v] << endl;

				for (auto v : result) all_possible_ports.push_back(v);
				//for (auto v : instance_str) cout<<v<<"success";
				//for (auto v : all_possible_ports) cout << v << endl;
				//for (auto v : all_possible_ports) cout << v << " : " << hashGateValue[v] << endl;

				//for (auto v : all_possible_ports) cout << v << " : " << pin_port[v] << endl;


				//cout << "\n ~~~~~SDF~~~~~" << endl;
				truth_sheet.emplace(u, hashGateValue);
				vhdlfunction_data = funcVector_split(for_sdf);


				std::ofstream ofsr;
				ofsr.open(out_result, std::ofstream::out | std::ofstream::app);

				ofsr << "=============== VHDL Result " <<(u+1)<<" =================="<< endl;
				ofsr << "----------------Input Vector-----------------" << endl;
				for (auto v : ip_Vec)
					ofsr << v << " : " << hashGateValue[v] << endl;
				//ofsr << "----------------NETS-----------------" << endl;

				ofsr << "--------Output--------" << endl;
				for (auto v : op_Vec)
					ofsr << v << " : " << hashGateValue[v] << endl;


				ofsr.close();

			}// end here
			
	
				
			sdf(loc, vhdlfunction_data, all_possible_ports, hashGateValue, instance_str, op_Vec, ip_Vec,truth_sheet);	
				

	}
	
	else
	
		std::cout << "file is not open" << '\n';
		std::cin.get();
		return 0 ;
	
}

std::vector<string> funcVector_split(string function_data) {
	std::string s = function_data;
	std::string delimiter = ";";
	vector<string> split_list;
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		//std::cout << token << std::endl;
		s.erase(0, pos + delimiter.length());
		split_list.push_back(token);
	}
	//std::cout << s << std::endl;
	//split_list.push_back(s);
	return split_list;
}