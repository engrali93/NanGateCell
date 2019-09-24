
#ifndef _SDF_
#define _SDF_
#include <iostream>
#include <string.h>
#include <vector>
#include<string>
#include <unordered_map>
using namespace std;

void sdf(string file_location, std::vector<string> vhdlFunc_data,std::vector<string> All_ports, unordered_map<string, int> ports_values, vector<string> instance_str, list<string> opVectors,list<string> ipvectors);

//void file_location_sdf();



#endif // !_SDF_

