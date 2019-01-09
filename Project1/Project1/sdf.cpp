#include<iostream>
#include "sdf.h"
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <algorithm>
#include "NanGateCell.h"



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


std::vector<string> dataVector(vector<string> data) {
	size_t pos=0;
	string temp_val;
	NanGateCell nangatecell;
	vector<string> output_in;
	
	for (int i = 0; i < data.size(); i++) {
		//((pos = a.find("port map")) != std::string::npos)
		/*string str = data.at(i);
		string str1 = data.at(i+1);*/
		if (((pos = data.at(i).find("CELL")) != std::string::npos) && ((pos = data.at(i+1).find("CELLTYPE")) != std::string::npos)) {
			temp_val = data.at(i + 1);
			string new_str=celltype_name(temp_val);
			//string newStr= regex_match(temp_val);
			
			if (nangatecell.GateType(new_str) == "YES") {
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
					}

				}
			}
		}
	}

	
	
	return output_in ;

}
	

void  sdf(string file_location)
	{
		std::string line_;
		std::string read_line;
		string jo = file_location;
		size_t pos = 0;
		ifstream in_sdf_file(file_location);
		std::vector<string> fordata_Vec;
		vector<string> output_cell;
		if (in_sdf_file.is_open())
		{
			while (getline(in_sdf_file, line_))
			{
				read_line = line_;
			    fordata_Vec.push_back(read_line);

			}
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
			output_cell = dataVector(fordata_Vec);
			for (int i = 0; i < output_cell.size(); i++)
			{
				cout << output_cell.at(i) << endl;
			}
			
			in_sdf_file.close();
		}
	

			else

			std::cout << "file is not open" << '\n';
			
			//return ;
	}

	