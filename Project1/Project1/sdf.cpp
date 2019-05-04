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

void PrintMatches2(std::string str, std::regex reg) {
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
		cout << tempVal << endl;
		temp.push_back(tempVal);
	}
	int vecInt = temp.size();
	cout << "time"<<endl;
	for (int i = 0; i < (vecInt/2); i++) {
		//char *strr = temp.at(i);
		double n1 = std::stod(temp.at(i));
		
		double n2 = std::stod(temp.at(i + 3));
		double a = n1 - n2;
		double b = 4.23 - 1.11;
		//cout << a << "  here  " <<endl;
		ostringstream str11;
		str11 << a;
		string s = str11.str();
		//cout << s << "double" << endl;
		
		//cout << s << "  string" << endl;
		
		time.push_back(s);
	}
	cout << "time"<<endl;
	for (auto v:time) cout << v<<endl;
	std::cout << std::endl;

}

vector<string> sub_delay(std::vector<string> data) {
	size_t pos = 0;
	vector<string> final_vector;
	
	for (int i = 0; i < data.size(); i++) {
		if ((pos = data.at(i).find("IOPATH") != std::string::npos) || (pos = data.at(i).find("INTERCONNECT") != std::string::npos)) {
			std::string str1 = data.at(i);
			std::regex reg7("(\[0-9]+\.[0-9]+)");
			PrintMatches2(str1, reg7);
		

		}


	}
	return final_vector;
}

void  sdf(string file_location, vector<string> vhdlFunc_data)
	{
		std::string line_;
		vector<string> vhdl = vhdlFunc_data; ;
		vector<string> vhdl_chip_list;
		vector<string> iopath;
		std::string read_line;
		string jo = file_location;
		size_t pos = 0;
		ifstream in_sdf_file(file_location);
		std::vector<string> fordata_Vec;
		
		
		unordered_map<string, vector<string>> output_cell_block;
		if (in_sdf_file.is_open())
		{
			while (getline(in_sdf_file, line_))
			{
				read_line = line_;
			    fordata_Vec.push_back(read_line);

			}
			//for(auto v: sort_data(fordata_Vec)) cout<<v<<endl;
			vector<string> newRw = sort_data(fordata_Vec);

			for (auto v : sub_delay(newRw)) cout << v << endl;
			/*std::string str7 = "(INTERCONNECT U10/ZN U5/B (0.018:0.024:0.024) (0.021:0.022:0.022))";
			std::regex reg7("(\[0-9]+\.[0-9]+)");
			PrintMatches2(str7, reg7);
			*/
			
			/*for (int i = 0; i < fordata_Vec.size(); i++) {
				cout << "shukar"<<fordata_Vec.at(i) << endl;*/
			////	//string ok=printvector(fordata_Vec);
			////	cout << dataVector(fordata_Vec).size() << "pp" << endl;;
			////	vector<string> ol = dataVector(fordata_Vec);
			////	
			////	//cout << ok.size() << endl;
			//}
			/*cout << fordata_Vec.at(39) << endl;
			cout << celltype_name(fordata_Vec.at(97)) << endl;*/
			//regex_match(fordata_Vec.at(39));
			//output_cell_block = dataVector(fordata_Vec);
			/*for (int i = 0; i < output_cell_block.size(); i++)
			{
				vector<string> ok= out
				
			}*/
			//vector<string> ok = output_cell_block["(INSTANCE U12)"];
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
			
			//return ;
	}

	