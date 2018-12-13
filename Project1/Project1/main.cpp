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
	std::list<string> functionSeparate;
	std::vector<int> Vector;

	std::list<string> result;
	std::list<string> op_result;
	std::list<string> ip_Vec;
	std::list<string> op_Vec;
	std::string line_;
	std::string read_line;
	std::string delimiter = ",";
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
				}
				//std::cout << line_ << std::endl;
				//result.push_back(line_);
				//listing("input", line_);
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				inputList.iplist(line_);
				result.push_back(line_);
				/*std::list<std::string>::iterator it = result.begin();
				std::advance(it, 4);
				std::cout << "3rd element = " << *it << std::endl;
				
				for (auto v : result)
					std::cout << v << "\n";*/
				//listing ();
				int co;
				co= inputList.size();
				inputList.iplistdisplay();
				//cout << "here" << co << endl;
				//inputVectorNew.myVector;
				cout << "Type in a list of inputs (" << co << " ) " << endl;
				std::list<std::string>::iterator it = result.begin();

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
					std::vector<int> vect;
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
					cout <<vect.size()<< endl;
					
					
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
					result.push_back(token);
					ip_Vec.push_back(token);
					cout << token << endl;
				}
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				inputList.iplist(line_);
				result.push_back(line_);
				ip_Vec.push_back(line_);
				cout << line_ << endl;
			}

			
			
			//////////////////////////////////
			//////// output vector
			///////////////////////////////////

			if (read_line.find(opVec1) != std::string::npos)
			{
				std::cout << "\nOUTPUT Vector" << endl;
				//line_.erase(line_.find(port), port.length());
				line_.erase(line_.find(opVec1), opVec1.length());
				line_.erase(std::remove(line_.begin(), line_.end(), ':'), line_.end());
				std::string::size_type firstQuotePos = line_.find_first_of("(");
				std::string::size_type secondQuotePos = line_.find_first_of(")");
				if (firstQuotePos != std::string::npos)
				{
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
						inputList.iplist(token);//right one
						result.push_back(token);
						op_Vec.push_back(token);
						cout << token << endl;
					}
				//}
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				inputList.iplist(line_);
				result.push_back(line_);
				op_Vec.push_back(line_);
				cout << line_ << endl;
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
					result.push_back(token);
					//listing("output", token);
					op_result.push_back(token);
					outputList.oplist(token);
				}
				line_.erase(remove_if(line_.begin(), line_.end(), isspace), line_.end());
				std::cout << line_ << std::endl;
				result.push_back(line_);
				outputList.oplist(token);
				op_result.push_back(line_);
				//listing("output", line_);
				/*std::list<std::string>::iterator it = result.begin();
				std::advance(it, 4);
				std::cout << "3rd element = " << *it << std::endl;

				for (auto v : result)
					std::cout << v << "\n";*/
					//listing ();

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
			// gate information
			////////////////////////
			if ((read_line.find("begin") != std::string::npos)) 
			{
				std::cout << "\nFunction" << endl;
				std::string delimiter = "begin";
				std::string data_ = accumulate(istream_iterator<char>{ file_ >> noskipws }, {}, string{});
				while ((pos = data_.find(delimiter)) != std::string::npos) {
					token = data_.substr(0, pos);
					//std::cout << token << std::endl;
					data_.erase(0, pos + delimiter.length());
				}
				//std::cout << data_ << std::endl;
				std::string mystr = data_.substr(0, data_.find("end", 0));
				//std::cout <<"uff" << mystr << std::endl;
				
				std::string token_n;
				std::string delimiter1 = ";";
				std::string delimiter2 = "<=";
				std::string delimiter3 = " ";
				while ((pos = mystr.find(delimiter1)) != std::string::npos) {
					token = mystr.substr(0, pos);
					//token.erase(remove_if(token.begin(), token.end(), isspace), token.end());
					//std::cout <<" yeh " << token << std::endl;
					mystr.erase(0, pos + delimiter1.length());
					if ((pos = token.find(delimiter2)) != std::string::npos) {
						token_n = token.substr(0, pos);
						//cout << " token1 : " << token_n << endl;
						token_n.erase(remove_if(token_n.begin(), token_n.end(), isspace ), token_n.end());
						
						//cout << " token1 :" << token_n << endl;
						//token.substr(token.find("<=") + 1);
						functionSeparate.push_back(token_n);
						//std::cout << token1 << " " << token<<std::endl;
						std::string extension = "";
						size_t pos = token.find_last_of(delimiter2);
						// make sure the poisition is valid
						if (pos != string::npos)
							extension = token.substr(pos + 1);
						//////////////////
						// split function
						/////////////
						
						std::istringstream buf(extension);
						std::istream_iterator<std::string> beg(buf), end;

						std::vector<std::string> listArrayVector(beg, end); // done!

						/*for (auto& s : listArrayVector)
							std::cout << s << '\n';*/
						if (listArrayVector.size() <= 3) {
							std::string gate = listArrayVector[1];
							int val1 = hashGateValue[listArrayVector[0]];
							int val2 = hashGateValue[listArrayVector[2]];
							cout << gate << endl; //"   oooooooo  :" << token_n << endl;
							int new_value = gatefunction.gate(val1, val2, gate);
							//hashGateValue.insert(token_n, new_value);
							hashGateValue.insert_or_assign(token_n, new_value);
							
							//hashGateValue.emplace(token_n, new_value);
							
							cout<< new_value<<endl;
						//	cout << hashGateValue["a1"] << "   " << hashGateValue["a2"] << "  " << hashGateValue["a3"] << endl;
						}
						
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
				for (auto v : op_result)
					std::cout << v << ": " << hashGateValue[v] << endl;
			}
		}
		file_.close();

	}
	
	else
	
		std::cout << "file is not open" << '\n';
		std::cin.get();
		return 0;
	
}