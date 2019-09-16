#include<iostream>
#include "sdf.h"
#include <string>
#include <fstream>
#include <regex>
#include<thread>
#include<ctime>
#include <vector>
#include <algorithm>
#include "NanGateCell.h"
#include <unordered_map>
#include <ostream>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <windows.h>



using namespace std;
//char const*printvector();
void regex_match(string line) {
	//file_location_sdf();
	std::string s(line);
	std::smatch m;
	std::regex e("((CELL)(.*)");               //("(CELLTYPE)(.*)");   // matches words beginning by "sub"
	/*vector<string> temp;
	string modify;
	string modify1;*/
	/*std::cout << "Target sequence: " << s << std::endl;
	std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
	std::cout << "The following matches and submatches were found:" << std::endl;*/
	/*if (std::regex_search(s, m, e) && m.size() > 1) {
		result = m.str(1);
	}*/
	while (std::regex_search(s, m, e)) {
		for (auto x : m) 	
			std::cout << x << " ";
		std::cout << std::endl;
		s = m.suffix().str();
		
	}


	
}



string celltype_name(string line) {
	string str = line;
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	str.erase(0, 10);
	str.erase(str.size() - 2, 2);
	return str;
}

std::vector<string> dataVector(std::vector<string> data, string chipName) {
	size_t pos=0;
	string temp_val;
	NanGateCell nangatecell;
	vector<string> output_in;
	vector<string> output_block;
	string instance;
	unordered_map<string, string> cell_block;
	//map<string, std::vector<string>> cell_block2;
	
	for (int i = 0; i < data.size(); i++) {
		//((pos = a.find("port map")) != std::string::npos)
		/*string str = data.at(i);
		string str1 = data.at(i+1);*/
		if (((pos = data.at(i).find("CELL")) != std::string::npos) && 
			((pos = data.at(i+1).find("CELLTYPE")) != std::string::npos) && 
			((pos = data.at(i + 2).find(chipName)) != std::string::npos)) {
			temp_val = data.at(i + 1);
			string temp_val_instance = data.at(i + 2);
			string new_str=celltype_name(temp_val);
			//string newStr= regex_match(temp_val);
			
			if (nangatecell.GateType(new_str) == "YES") {
				//output_block.clear();
				for (int x = i; x < data.size(); x++) {
					string tempstr = data.at(x);
					
					/*tempstr.erase(data.at())*/
					tempstr.erase(remove_if(tempstr.begin(), tempstr.end(), isspace), tempstr.end());
					/*if ((!(pos = data.at(i).find("(")) != std::string::npos) && ((pos = data.at(i).find(")")) != std::string::npos)) {
						break;
					}*/
					if(tempstr == ")")
					{
						//output_in.push_back(data.at(x));
						break;
					}
					else {
						output_in.push_back(data.at(x));
						output_block.push_back(data.at(x));
						//cell_block[temp_val_instance].push_back(data.at(x));
					}

				}
			}
		}

		//cell_block.emplace(instance, output_block);
	}

	
	
	return output_in ;

}
	
std::vector<string> sort_data(std::vector<string> for_data) {
	size_t pos = 0;
	vector<string> cer_data;
	for (int i = 0; i < for_data.size(); i++) {
		if ((pos = for_data.at(i).find("CELL")) != std::string::npos) {
			for (int u = i; u < for_data.size(); u++)
			{
				
				cer_data.push_back(for_data.at(u));
				
			}
			
			break;
		}
		
	}
	
	return cer_data;
}

std::vector<string> sort_cell(std::vector<string> for_data, int j) {
	size_t pos = 0;
	vector<string> cer_data;
	cer_data.push_back(for_data.at(j));
	for (int i = j+1; i < for_data.size(); i++) { 
		
		if (((pos = for_data.at(i).find("CELL")) != std::string::npos) && ((pos = for_data.at(i).find("CELLTYPE")) == std::string::npos)) {
			break;
		}
		cer_data.push_back(for_data.at(i));


			}

			
		

	

	return cer_data;
}




vector<string> PrintMatches1(std::string str, std::regex reg) {
	
	
	std::sregex_iterator currentMatch(str.begin(),str.end(), reg);
	
	// Used to determine if there are any more matches
	std::sregex_iterator lastMatch;
	vector<string> time;
	vector<string> temp;
	// While the current match doesn't equal the last
	while (currentMatch != lastMatch) {
		std::smatch match = *currentMatch;
		//std::cout << match.str() << "\n";
		currentMatch++;
		string tempVal = match.str();
		//cout << tempVal <<"sssss"<< endl;
		temp.push_back(tempVal);
	}
	int vecInt = temp.size();
	string stra1;
	string stra2;
	vector<string> temp2;
	
	stra1 = "(" + temp.at(0) + ":" + temp.at(1) + ":" + temp.at(2) + ")";
	stra2 = "(" + temp.at(3) + ":" + temp.at(4) + ":" + temp.at(5) + ")";
	temp2.push_back(stra1);
	temp2.push_back(stra2);
	
	//cout << "time"<<endl;
	
	//cout << "time"<<endl;
	

	//cout << finalTime << " success" << endl;
	//for (auto v:time) cout << v<<endl;
	//std::cout << std::endl;
	return temp2;
}
string PrintMatches2(std::string str, std::regex reg) {
	std::sregex_iterator currentMatch(str.begin(),
		str.end(), reg);

	// Used to determine if there are any more matches
	std::sregex_iterator lastMatch;
	vector<string> time;
	vector<string> temp;
	// While the current match doesn't equal the last
	while (currentMatch != lastMatch) {
		std::smatch match = *currentMatch;
		//std::cout << match.str() << "\n";
		currentMatch++;
		string tempVal = match.str();
		//cout << tempVal << endl;
		temp.push_back(tempVal);
	}
	int vecInt = temp.size();
	//cout << "time"<<endl;
	for (int i = 0; i < (vecInt/2); i++) {
		//char *strr = temp.at(i);
		double n1 = std::stod(temp.at(i));
		
		double n2 = std::stod(temp.at(i + 3));
		double a;
		if(n1>n2){ // subtract time delay propagation
			a = n1 - n2;
		}
		if (n2 > n1) {
			a = n2 - n1;
		}
		//double a = n1 - n2; //substract time
		string s;
		if (n1 == n2) {
			s = "0.000";
			
		}
		else {
			ostringstream str11;
			str11 << a;
			s = str11.str();
			//cout << s << "double" << endl;

			//cout << s << "  string" << endl;
		}
		time.push_back(s);
	}
	//cout << "time"<<endl;
	string finalTime;
	
		finalTime =  time.at(0)+":"+time.at(1)+":"+time.at(2);
	
	//cout << finalTime << " success" << endl;
	//for (auto v:time) cout << v<<endl;
	//std::cout << std::endl;
	return finalTime;
}

std::string sub_delay(std::string data) {
	size_t pos = 0;
	string final_time;
	
	//for (int i = 0; i < data.size(); i++) {
		//if ((pos = data.at(i).find("IOPATH") != std::string::npos) || (pos = data.at(i).find("INTERCONNECT") != std::string::npos)) {
		if ((pos = data.find("IOPATH") != std::string::npos) || (pos = data.find("INTERCONNECT") != std::string::npos)) {

			std::string str1 = data;
			std::regex reg7("(\[0-9]+\.[0-9]+)");
			final_time =PrintMatches2(str1, reg7);
		

		//}


	}
	return final_time;
}

vector<string> PrintMatches3(std::string str, std::regex reg) {
	std::sregex_iterator currentMatch(str.begin(),str.end(), reg);

	// Used to determine if there are any more matches
	std::sregex_iterator lastMatch;
	vector<string> time;
	vector<string> temp;
	// While the current match doesn't equal the last
	while (currentMatch != lastMatch) {
		std::smatch match = *currentMatch;
		//std::cout << match.str() << "\n";
		currentMatch++;
		string tempVal = match.str();
		//cout << tempVal <<"sssss"<< endl;
		temp.push_back(tempVal);
	}


	return temp;
}

vector<string> Routing(std::string str,vector<string>vhdl, list<string>output) {
	//vector<string> opVec;
	//for (auto v : output) opVec.push_back(v);
	vector<string> duplicate;
	vector<string> temp;
	string value = str;
	string recheck = str;
	size_t pos = 0;
	//size_t place = 0;
	string A1;
	string A2;
	string B1;
	string B2;
	string ZN;
	string A;
	string B;
	string Z;
	string instance;
	int ZNN;
	int x;

		
	for ( x = 0; x <= vhdl.size(); x++) {
		//cout << "Value " << value << endl;
		if ((pos = vhdl.at(x).find("A1") != std::string::npos)) {
			string strNew = vhdl.at(x);
			string strIns = vhdl.at(x);
			//cout << strNew << endl;
				size_t place = strNew.find("A1 => ");
				
				strNew=strNew.erase(0, place+6);
				place = strNew.find(",");
				A1 = strNew.substr(0, place);
				
				place = strNew.find("A2 => ");
				strNew = strNew.erase(0, place+6);
				place = strNew.find(",");
				A2 = strNew.substr(0, place);

				place = strNew.find("B1 => ");
				strNew = strNew.erase(0, place+6);
				place = strNew.find(",");
				B1 = strNew.substr(0, place);

				place = strNew.find("B2 => ");
				strNew = strNew.erase(0, place + 6);
				place = strNew.find(",");
				B2 = strNew.substr(0, place);

				place = strNew.find("ZN => ");
				strNew = strNew.erase(0, place+6);
				ZN = strNew.substr(0,strNew.size()-1);
				Z = "";

				place = strIns.find(" :");
				instance = strIns.substr(0, place );
				instance.erase(remove_if(instance.begin(), instance.end(), isspace), instance.end());
				//cout << instance << endl;
				ZNN = 1;
				/*cout << "A1 =" << A1 << endl;
				cout << "B1 =" << B1 << endl;
				cout << "A2 =" << A2 << endl;
				
				cout << "B2 =" << B2 << endl;
				cout << "ZN =" << ZN << endl;
				cout << "-----------------------------" << endl;*/
							
		}
		if ((pos = vhdl.at(x).find("A") != std::string::npos) && (pos = vhdl.at(x).find("B") == std::string::npos)) {

			string strNew = vhdl.at(x);
			string strIns = vhdl.at(x);
			//cout << strNew << endl;
			size_t place = strNew.find("A => ");

			strNew = strNew.erase(0, place + 5);
			place = strNew.find(",");
			A = strNew.substr(0, place);

			place = strNew.find("ZN => ");
			strNew = strNew.erase(0, place + 5);
			ZN = strNew.substr(0, strNew.size() - 1);
			Z = "";

			place = strIns.find(" :");
			instance = strIns.substr(0, place);
			instance.erase(remove_if(instance.begin(), instance.end(), isspace), instance.end());
			//cout << instance << endl;
			ZNN = 1;

			/*cout << "A =" << A << endl;
			cout << "ZN =" << ZN << endl;
			cout << "-----------------------------" << endl;*/
		}
		if ((pos = vhdl.at(x).find("A") != std::string::npos) && (pos = vhdl.at(x).find("B =>") != std::string::npos)) {
			string strNew = vhdl.at(x);
			string strIns = vhdl.at(x);
			//cout << strNew << endl;
			size_t place = strNew.find("A => ");
			
			strNew = strNew.erase(0, place + 5);
			place = strNew.find(",");
			A = strNew.substr(0, place);

			place = strNew.find("B => ");
			strNew = strNew.erase(0, place + 5);
			place = strNew.find(",");
			B = strNew.substr(0, place);
			cout << B << endl;
			place = strNew.find("Z => ");
			strNew = strNew.erase(0, place + 5);
			Z = strNew.substr(0, strNew.size() - 1);
			ZN = "";

			place = strIns.find(" :");
			instance = strIns.substr(0, place);
			instance.erase(remove_if(instance.begin(), instance.end(), isspace), instance.end());
			//cout << instance << endl;
			ZNN = 0;
			/*cout << "A =" << A << endl;
			cout << "B =" << B << endl;
			cout << "Z =" << Z << endl;
			cout << "-----------------------------" << endl;*/
		}
		
		
		
		
		if ((pos = vhdl.at(x).find(value) != std::string::npos) && (std::find(temp.begin(), temp.end(), instance) == temp.end())) {
			
			
				if ((ZNN == 1) && (ZN != value && Z != value) && (std::find(temp.begin(), temp.end(), instance) == temp.end())) {
					temp.push_back(instance);
					
						value = ZN;
						x = -1;
					
				}
				
			
				if ((ZNN == 0) && (ZN != value && Z != value) && (std::find(temp.begin(), temp.end(), instance) == temp.end())) {
					temp.push_back(instance);
					
						value = Z;
						x = -1;
					
					
				}

		}

		cout << instance <<" : "<<value<< endl;
		//cout << value << endl;
		if (std::find(output.begin(), output.end(), value) != output.end()) {
			value = recheck;
			cout << "RECHECK  :" << value << endl;
			x = -1;
			temp.push_back("Next routing");
			//break;
		}
		if (x == vhdl.size()-1) { break; }
	}

	return temp;
}

unordered_map<string, string> interconnect_value(std::vector<string> interconnect_string, std::vector<string> vhdl_function, vector<string> All_ports,std::list<string>op_vectors) {
	//cout << interconnect_string.size();
	//cout << "okokok";
	int co = 5;
	std::string valnet;
	size_t pos = 0;
	std::regex reg7("\[0-9]+\.[0-9]+");
	unordered_map<string, string> interconnect_hashmap;
	for (int i = 0; i < interconnect_string.size(); i++) {
		std::string value = interconnect_string.at(i);
		value.erase(std::remove(value.begin(), value.end(), '\\'), value.end());
		value.erase(0, 18);
		

		std::sregex_iterator currentMatch(value.begin(), value.end(), reg7);

		// Used to determine if there are any more matches
		std::sregex_iterator lastMatch;
		vector<string> time;
		vector<string> temp;
		// While the current match doesn't equal the last
		while (currentMatch != lastMatch) {
			std::smatch match = *currentMatch;
			//std::cout << match.str() << "\n";
			currentMatch++;
			string tempVal = match.str();
			//cout << tempVal <<"ooooo"<< endl;
			temp.push_back(tempVal);
		}
		std::string time_temp = "(" + temp.at(0) + ":" + temp.at(1) + ":" + temp.at(2) + ")";
		
		std::size_t posa = value.find_first_of(" ");
		std::string net = value.substr(0, posa);

		if ((pos = net.find("/") != std::string::npos)) {
			pos = net.find("/");
			std::string instance = net.substr(0, pos);
			std::string outval = net.substr(pos + 1, net.length() - pos);
			for (int k = 0; k < vhdl_function.size(); k++) {
				if ((pos = vhdl_function.at(k).find(instance) != std::string::npos)) {
					std::size_t posb = vhdl_function.at(k).find_last_of(outval + " => ");
					valnet = vhdl_function.at(k).substr(posb + 1);
					valnet.erase(std::remove(valnet.begin(), valnet.end(), ')'), valnet.end());
					//cout << "XXXXXX" + valnet << endl;
					if (std::find(op_vectors.begin(), op_vectors.end(), valnet) == op_vectors.end()) {
						//cout << "not present ===" + valnet <<" tim : "+time_temp<< endl;
						interconnect_hashmap.emplace(valnet, time_temp);
						
					}
					else {
						
					}
						
					
					
				}
			}
		}
		else {
			valnet = net;
			//cout << "pppp===" + valnet;
			if (interconnect_hashmap.find(valnet) == interconnect_hashmap.end()) {
				interconnect_hashmap.emplace(valnet, time_temp);
				//cout <<"pppp==="+ valnet;
			}
			
			
		}
		
		//cout << " check it " + value << endl;
	}
	//cout << "ok size : " + interconnect_hashmap.size() << endl;
	/*for (int j = 0; j < All_ports.size(); j++) {
		cout << All_ports.at(j) << " : " << interconnect_hashmap[All_ports.at(j)] << endl;

	}*/
	return interconnect_hashmap;
}

string single_cell_value(vector<string> vhdl_data, vector<string> single_cell_data, unordered_map<string, int> ports_values) {
	string IOPath;
	string str;
	string str_final;
	size_t pos=0;
	size_t posa = 0;
	size_t posb = 0;
	string cond;
	vector<string> splited;
	vector<string> key;
	vector<string> temp_replace;
	vector<string> final_timing_delay;
	string value;
	unordered_map<string, int> current_temp;
	unordered_map<string, string> confirm12;
	std::string token1;
	string instance;
	string instance_str;
	vector<string> mycheck;
	vector<string> mychecknew;
	mycheck.push_back("A1");
	mycheck.push_back("A2");
	mycheck.push_back("B1");
	mycheck.push_back("B2");
	mycheck.push_back("ZN");
	std::string A1 = instance + " : A1 ZN (0.000:0.000:0.000)";
	std::string A2 = instance + " : A2 ZN (0.000:0.000:0.000)";
	std::string B1 = instance + " : B1 ZN (0.000:0.000:0.000)";
	std::string B2 = instance + " : B2 ZN (0.000:0.000:0.000)";
	unordered_map<string, string> temp_data_type;
	
	for (int i = 0; i< single_cell_data.size(); i++)
	{
		if ((pos = single_cell_data.at(i).find("INSTANCE") != std::string::npos)) {
			std::size_t pos1 = single_cell_data.at(i).find_last_of("INSTANCE ");
			std::size_t pos2 = single_cell_data.at(i).find("INSTANCE ");
			
			str = single_cell_data.at(i).erase(0, pos1+1);
			str = str.substr(0, str.size() - 1);
			instance = str;
			instance_str = str;
			for (int j = 0; j < vhdl_data.size(); j++) {
				if ((pos = vhdl_data.at(j).find(str) != std::string::npos)) {
					if ((posa = vhdl_data.at(j).find("COND") != std::string::npos)) 
					{ cond = "y"; }
					else { cond = "n"; }
					string str1 = vhdl_data.at(j);
					std::size_t pos3 = vhdl_data.at(j).find("map");
				
					//cout << str1.length() << endl;
					string str2 = str1.erase(0, pos3);
					str2.erase(remove_if(str2.begin(), str2.end(), isspace), str2.end());
					string strn22 = str2.erase(0, 3);
					
					
					str2 = str2.erase(0, 1);
					str2 = str2.erase(str2.size() - 1, str2.size());
					
					//cout << str2 << endl;
					string delimiter = ",";
					
					std::string token;
					while ((pos = str2.find(delimiter)) != std::string::npos) {
						token = str2.substr(0, pos);
						splited.push_back(token);
						str2.erase(0, pos + delimiter.length());
					}
					
					splited.push_back(str2);
					string delimiter2 = "=>";
					for (int k = 0;k<splited.size();k++) {
						string tempstr1 = splited.at(k);// instance string
						//cout << tempstr1 << endl;
						
						size_t pos4 = tempstr1.find(delimiter2);
							token1 = tempstr1.substr(0, pos4);
							
							value= tempstr1.erase(0, pos4 + delimiter2.length());
							//cout << "value + token 1===+++++" << value + token1 << endl;
							//cout << value << " " << ports_values[value] << endl;// value value
							temp_data_type.emplace(token1,value);
							key.push_back(token1);
						
					}
					//for (auto v : splited2) cout << v << endl;
				}

			}
		}
		// for NOT gate as it doesnt have COND
		if ((posb = single_cell_data.at(i).find("IOPATH") != std::string::npos) && (posb = single_cell_data.at(i).find("COND") == std::string::npos)) {
			string temp1=single_cell_data.at(i);
			size_t place = single_cell_data.at(i).find_last_of("IOPATH");
			temp1.erase(0, place);
			temp1.erase(temp1.size() - 1, temp1.size());
			std::regex reg7("\[A-Z]+");
			vector<string> temp_replace = PrintMatches3(temp1, reg7);
			IOPath = temp1;
			
			for (auto v : temp_replace) {
				string a = v;
				
				std::regex target(a);
				std::string replacement = temp_data_type[a];
				
				IOPath = std::regex_replace(IOPath, target, replacement);
				
				

			} 
	
		}
		// for rest of the gate where COND is present
		if ((posb = single_cell_data.at(i).find("IOPATH") != std::string::npos) && (posb = single_cell_data.at(i).find("COND") != std::string::npos)) {
			string temp1 = single_cell_data.at(i);
			string ioplaceNew = single_cell_data.at(i);
			size_t ioTimePlaceNew = ioplaceNew.find("IOPATH");
			
			ioplaceNew=ioplaceNew.erase(0, ioTimePlaceNew);// ioTime.size()-1);
			
			ioplaceNew=ioplaceNew.substr(6, ioplaceNew.size() - 8);
			
			size_t place1 = single_cell_data.at(i).find("IOPATH");
			temp1=temp1.substr(0, place1-1);
			size_t place2 = temp1.find_last_of("COND");
			temp1 = temp1.erase(0, place2 + 1);
			temp1.erase(remove_if(temp1.begin(), temp1.end(), isspace), temp1.end());
			std::regex reg7("\[A-Z]+\[0-9]*");
			std::regex reg8("\[1]\[']\[b]\[0-1]");
			temp_replace = PrintMatches3(temp1, reg7);
			vector<string> temp_replace1 = PrintMatches3(temp1, reg8);
			std::replace(temp_replace1.begin(), temp_replace1.end(), std::string("1'b0"), std::string("0"));
			std::replace(temp_replace1.begin(), temp_replace1.end(), std::string("1'b1"), std::string("1"));
			current_temp.clear();
			for (int l = 0; l < temp_replace.size(); l++) {
				//current_temp.emplace(temp_replace.at(l), stoi(temp_replace1.at(l)));
				
					int val1 = stoi(temp_replace1.at(l));
					string val2 = temp_replace1.at(l);
					string temp_str = temp_replace.at(l);
					//cout << "olo---" + temp_str << val1 << endl;
					current_temp.emplace(temp_str, val1);

					//cout << temp_replace.at(l) << " " << temp_replace1.at(l) << endl; // decoded values of sdf

				
				//cout << temp_replace.at(l) <<"ioi"<< endl;
			}
			
			
			cout << " VHDL"  << endl;
			for (auto v : temp_replace) cout << v <<" "<< ports_values[temp_data_type[v]] << endl;// vhdl port values
			cout << "--------------------------";
			
			
			if (temp_replace.size() <= 2) {
				
					for (int i = 0; i < temp_replace.size(); i++) {
						if (temp_replace.at(i) != "Z") {
						int match_1 = current_temp[temp_replace.at(i)];
						int match_2 = ports_values[temp_data_type[temp_replace.at(i)]];
						if (match_1 == match_2) {
							cout << temp_replace.at(i) << " " << current_temp[temp_replace.at(i)] << " " << ports_values[temp_data_type[temp_replace.at(i)]] << endl;

							cout << "================================================" << endl;
							cout << "matched" << endl;
							cout << instance << " :k " << ioplaceNew<< endl;
							cout << "================================================" << endl;
							cout << endl;
						}
						else {
							//cout << "NOT match" << endl;
						}
					}
				}
				}

			if (temp_replace.size() > 2) {
				

				for (int i = 0; i < 1; i++) {
					if (temp_replace.at(i) != "Z") {
						int match_1n = current_temp[temp_replace.at(i)];
						int match_1a = ports_values[temp_data_type[temp_replace.at(i)]];

						int match_2n = current_temp[temp_replace.at(i+1)];
						int match_2a = ports_values[temp_data_type[temp_replace.at(i+1)]];

						int match_3n = current_temp[temp_replace.at(i+2)];
						int match_3a = ports_values[temp_data_type[temp_replace.at(i+2)]];
						if ((match_1n == match_1a) && (match_2n == match_2a) && (match_3a== match_3n)) {
							cout << temp_replace.at(i) << " " << current_temp[temp_replace.at(i)] << " " << ports_values[temp_data_type[temp_replace.at(i)]] << endl;
							cout << temp_replace.at(i + 1) << " " << current_temp[temp_replace.at(i + 1)] << " " << ports_values[temp_data_type[temp_replace.at(i + 1)]] << endl;
							cout << temp_replace.at(i + 2) << " " << current_temp[temp_replace.at(i + 2)] << " " << ports_values[temp_data_type[temp_replace.at(i + 2)]] << endl;

									cout << "================================================" << endl;
									cout << "matched" << endl;
									cout << instance << " : " << ioplaceNew << endl;
									size_t pok = 0;
									if (pok = ioplaceNew.find("A1") != std::string::npos) {
										
										A1.clear();
										A1 = " :" + ioplaceNew;
									}
									if (pok = ioplaceNew.find("A2") != std::string::npos) {
										
										A2.clear();
										A2 = " :" + ioplaceNew;
									}
									if (pok = ioplaceNew.find("B1") != std::string::npos) {
										
										B1.clear();
										B1 =  " :" + ioplaceNew;
									}
									if (pok = ioplaceNew.find("B2") != std::string::npos) {
										
										B2.clear();
										B2 =  " :" + ioplaceNew;
									}

									size_t iop = ioplaceNew.find(" ZN");
									string ionew = ioplaceNew;
									ionew.erase(iop, ionew.length());
									ionew.erase(0, 1);
									//########################33
									std::vector<string>::iterator pend;
									pend = std::remove(mycheck.begin(), mycheck.end(), ionew);
									for (std::vector<string>::iterator p = mycheck.begin(); p != pend; ++p)
										std::cout << ' ' << *p; std::cout << '\n';


									final_timing_delay.push_back(instance + " : " + ioplaceNew);
									cout << "================================================" << endl;
									cout << endl;
									
							
						}
						else {
							cout << "NOT match" << endl;
							cout << temp_replace.at(i) << " " << current_temp[temp_replace.at(i)] << " " << ports_values[temp_data_type[temp_replace.at(i)]] << endl;
							cout << temp_replace.at(i + 1) << " " << current_temp[temp_replace.at(i + 1)] << " " << ports_values[temp_data_type[temp_replace.at(i + 1)]] << endl;
							cout << temp_replace.at(i + 2) << " " << current_temp[temp_replace.at(i + 2)] << " " << ports_values[temp_data_type[temp_replace.at(i + 2)]] << endl;
						}
					}
					

				}
			}
			
		}
	
		
	}
	cout <<instance_str+ A1 << endl;
	cout << instance_str + A2 << endl;
	cout << instance_str + B1 << endl;
	cout << instance_str + B2 << endl;
	//for (auto v : key) cout << ports_values[temp_data_type[v]] << endl;
	/*cout << "ololo" << temp_replace.size() << endl;
	for (auto v : temp_replace) cout << v << endl;*/
	
	
	str_final = instance + " : " + IOPath;
	
	return str_final;
}
void  sdf(string sdffile, vector<string> vhdlFunc_data,vector<string> All_ports, unordered_map<string, int> ports_values,vector<string> instance_str,std::list<string> opVectors)
	{
	//for (auto v : instance_str) cout << v << "shai";
	//for (auto v : All_ports) cout << v << " : " << ports_values[v] << endl; //all values
		std::string line_;
		vector<string> vhdl = vhdlFunc_data; ;
		vector<string> vhdl_chip_list;
		vector<string> iopath;
		std::string read_line;
		int count = 0;
		//string jo = file_location;
		size_t pos = 0;
		//std::string sdffile =  "D:/project arbeit/files/2-bit/exact_adder_cla_T=2_TECH=freepdk45tc_B=2.sdf";
		ifstream in_sdf_file(sdffile);
		std::vector<string> fordata_Vec;
		std::vector<string> interconnect_table;
		std::vector<string> cell_table;
		std::vector<string> single_cell;
		
		
		unordered_map<string, vector<string>> output_cell_block;
		if (in_sdf_file.is_open())
		{
			while (getline(in_sdf_file, line_))
			{
				read_line = line_;
				

				if ((pos = read_line.find("IOPATH") != std::string::npos) || (pos = read_line.find("INTERCONNECT") != std::string::npos)) {
					string temp_time= sub_delay(read_line);// final time
					
					//std::regex reg7("\\(\[0-9]+\.\[0-9]+\:\[0-9]+\.\[0-9]+\:\[0-9]+\.\[0-9]+\\)");
					std::regex reg7("\[0-9]+\.[0-9]+");
					vector<string> temp_replace= PrintMatches1(read_line, reg7);
					string rem_str1 = temp_replace.at(0);
					string rem_str2 = temp_replace.at(1);
					
					std::regex target("("+rem_str1+")");
					std::regex target2("(" + rem_str2 + ")");
					std::string replacement = temp_time;
					std::string replacement2 = "";
					std::string s2 = std::regex_replace(read_line, target, replacement);
					std::string s3 = std::regex_replace(s2, target2, replacement2);
					std::size_t pos = s3.find_last_of(temp_time);      // position of "live" in str
					
					std::string str3 = s3.erase(pos+1,3); // final embedded time
					
					fordata_Vec.push_back(str3);
					if (pos = read_line.find("INTERCONNECT") != std::string::npos) {
						interconnect_table.push_back(str3); //for saving all the interconnect
					}

				}
				else {
					fordata_Vec.push_back(read_line);

				}
			}
			unordered_map<string, string> interconnect_net_time = interconnect_value(interconnect_table, vhdl,All_ports,opVectors);
			//for(auto v: sort_data(fordata_Vec)) cout<<v<<endl;
			vector<string> newRw = sort_data(fordata_Vec);
			
			//for (auto v :newRw) cout << v << endl; // main data
			for (int i = 0; i < newRw.size(); i++) {
				if ((pos = newRw.at(i).find("CELL") != std::string::npos) && (pos = newRw.at(i).find("CELLTYPE") == std::string::npos)) {
					count++;
				}
				if (count > 1) {
					cell_table.push_back(newRw.at(i));
				}
			}
			//cout << " cellllllllllllllll" << endl;
			//for (auto v : cell_table) cout << v << endl; //this one is for print cells 
			//for (auto v : interconnect_table) cout << v << endl; //display of interconnect

			for (int i = 0; i < cell_table.size(); i++) {

				if (((pos = cell_table.at(i).find("CELL")) != std::string::npos) && ((pos = cell_table.at(i).find("CELLTYPE")) == std::string::npos)) {
					single_cell=sort_cell(cell_table, i);
					
					cout << " single cell \n" << endl;
					//for (auto v : single_cell) cout << v << endl;
					cout<< single_cell_value(instance_str, single_cell,ports_values);// << "okiloiko" << endl;
					
				}
			}
			//cout << " single cell " << endl;
			for (int x = 0; x < 5; x++ ) {
				string ipValues = All_ports.at(x);
				cout << endl;
				cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
				cout << ipValues << endl;
				vector<string> li=Routing(ipValues, vhdl,opVectors);
				for (auto v : li) cout << v << endl;

			}
		/*	for (auto v : single_cell) cout << v << endl;
			cout << single_cell_value(instance_str, single_cell) << "okiloiko" << endl;  */
			//for(auto v: sub_delay(newRw)) cout<<v << endl;
			
			//for (auto v : cell_table) cout << v << endl;


			//vector<string> ok = output_cell_block["(INSTANCE U12)"];

			//###########################################
			//###########################################

			for (int u = 0; u < vhdl.size(); u++) {

				
				std::string mystr = vhdl.at(u).substr(0, vhdl.at(u).find(" :", 0));
				
				mystr.erase(remove_if(mystr.begin(), mystr.end(), isspace), mystr.end());
				vhdl_chip_list.push_back(mystr);
				vector<string> blockcell=dataVector(fordata_Vec, mystr);
				iopath.clear();
				for (int u = 0; u < blockcell.size(); u++) {
					
					if ((pos = blockcell.at(u).find("IOPATH")) != std::string::npos) {
						iopath.push_back(blockcell.at(u));
					}
				}
				//cout << mystr<<blockcell.size() << endl;
				//--for (auto v : iopath) cout << v << endl;
				//--cout << "end" << endl;
			}
			/*unordered_map<string, string> okl = dataVector(fordata_Vec);
			cout << okl["(INSTANCE U12)"] << endl;*/
			in_sdf_file.close();
		}
	

			else

			std::cout << "file is not open" << '\n';
			
			//return 0 ;
	}

	