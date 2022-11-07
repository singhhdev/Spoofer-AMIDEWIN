#include <iostream>
#include <windows.h>
#include "defs.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "xstor.hpp"

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
using namespace std;		

void compareBios() {
	// read the old bios version here:

	array<char, 128> buffer;
	string result;

	//FILE * popen(const char* command, const char* type);
	// use popen here and then 

	string command = _xor_("wmic bios get smbiosbiosversion").c_str();

	FILE* pipe = _popen(command.c_str(), "r");
	if (!pipe)
	{
		printf("Error... contact admin.");

	}
	while (fgets(buffer.data(), 128, pipe) != NULL) {
		//std::cout << "Reading..." << std::endl;
		result += buffer.data();
	}
	// need to compare the bios file for later, so write the file to .txt

	string returnCode = result.c_str();
	std::ofstream out("C:\\versionBios.txt");
	out << returnCode;
	out.close();
	Sleep(1000);

}
string readFileIntoString(const string& path) {
	ifstream input_file(path);
	if (!input_file.is_open()) {
		cerr << "Could not open the file - '"
			<< path << "'" << endl;
		exit(EXIT_FAILURE);
	}
	return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

bool compareSecondTime() {
	string oldFile("C:\\versionBios.txt");
	string oldCode = readFileIntoString(oldFile);		// read the old smbois value into here

	array<char, 128> buffer;
	string result;

	string command = _xor_("wmic bios get smbiosbiosversion").c_str();

	FILE* pipe = _popen(command.c_str(), "r");
	if (!pipe)
	{
		printf("Error... contact admin.");

	}
	while (fgets(buffer.data(), 128, pipe) != NULL) {
		//std::cout << "Reading..." << std::endl;
		result += buffer.data();
	}
	// need to compare the bios file for later, so write the file to .txt

	string newFile = result.c_str();						// new file holds the content of the smbiosversion
	printf("% s", newFile.c_str());
	printf("% s", oldCode.c_str());

	Sleep(1000);


	if (oldCode.c_str() == newFile.c_str()) {
		return true;
	}
	else {
		return false;
	}

	

}

