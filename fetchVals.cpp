#include <iostream>
#include <windows.h>
#include "defs.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "xstor.hpp"

#include <fstream>
#include <string>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>

using namespace std;
void fetchValuesFromRegistry() {
	// let the user relax back and fetch the data for them. (no need for MSinfo32.)
	//Sleep(500);
	for (int x = 0; x < 10; x++) {
		printf(_xor_("/").c_str());Sleep(500);

	}
	// above code is pretty useless but looks cool for the user lol
	printf(_xor_("/").c_str());
	printf(_xor_("\n").c_str());
	printf(_xor_("\n").c_str());
	printf(_xor_("\n").c_str());
	printf("[+]Success");
	Sleep(1000);
	cc(); // clear it now
	Sleep(150);

	art(); // print the art again
	printf("----Current IDS: ----\n");
	// print cpu name + serial code
	printf("\n");
	printf(_xor_("[+]CPU: ").c_str());
	registry_read("Hardware\\Description\\System\\CentralProcessor\\0", "ProcessorNameString", REG_SZ);
	printf("\n");
	printf("[+]");
	system(_xor_("wmic cpu get serialnumber").c_str());
	printf("\n");
-
	// print motherboard name + serial
	printf(_xor_("[+]Motherboard: ").c_str());
	registry_read("Hardware\\Description\\System\\BIOS", "BaseBoardManufacturer", REG_SZ);
	printf("\n");
	printf("[+] ");
	system(_xor_("wmic baseboard get serialnumber").c_str());
	printf("\n");
-
	// print bios info here: 
	printf(_xor_("[+]BIOS: ").c_str());
	registry_read("Hardware\\Description\\System\\BIOS", "BIOSVendor", REG_SZ);
	printf("\n");
	printf("[+]");
	system(_xor_("wmic bios get serialnumber").c_str());
	printf("\n");
-
	// print bioso version here: 
	printf(_xor_("[+]BIOS Version: ").c_str());
	registry_read("Hardware\\Description\\System\\BIOS", "BIOSVersion", REG_SZ);

	Sleep(5000);
	/// finished displaying the current info of the user.
}