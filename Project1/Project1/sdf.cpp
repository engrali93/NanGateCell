#include<iostream>
#include "sdf.h"
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <algorithm>



using namespace std;
//char const*printvector();
void regex_match(string line) {
	//file_location_sdf();
	std::string s(line);
	std::smatch m;
	std::regex e("((CELL)(.*)");               //("(CELLTYPE)(.*)");   // matches words beginning by "sub"

	/*std::cout << "Target sequence: " << s << std::endl;
	std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl;
	std::cout << "The following matches and submatches were found:" << std::endl;*/

	while (std::regex_search(s, m, e)) {
		for (auto x : m) std::cout << x << " ";
		std::cout << std::endl;
		s = m.suffix().str();
		
	}

	
	return ;
}


std::vector<string> dataVector(vector<string> data) {
	size_t pos=0;
	
	vector<string> output_in;
	
	for (int i = 0; i < data.size(); i++) {
		//((pos = a.find("port map")) != std::string::npos)

		if (((pos = data.at(i).find("CELL")) != std::string::npos) && ((pos = data.at(i + 1).find("CELLTYPE")) != std::string::npos)) {
			for (int x = 0; x < 3; x++) {
				output_in.push_back(data.at(i));
				i++;
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
			//for (int i = 0; i < fordata_Vec.size(); i++) {
			//	cout << "shukar"<<fordata_Vec.at(i) << endl;
			////	//string ok=printvector(fordata_Vec);
			////	cout << dataVector(fordata_Vec).size() << "pp" << endl;;
			////	vector<string> ol = dataVector(fordata_Vec);
			////	
			////	//cout << ok.size() << endl;
			//}
			output_cell = dataVector(fordata_Vec);
			for (int i = 0; i < output_cell.size(); i++)
			{
				cout << output_cell.at(i) << "good" << endl;
			}
			
			in_sdf_file.close();
		}
	

			else

			std::cout << "file is not open" << '\n';
			
			//return ;
	}

	