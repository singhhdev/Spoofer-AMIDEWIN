#include <iostream>
#include "defs.h"
#include <windows.h>
#include "xstor.hpp"
void startSpoofer();
void MacChanger();

using namespace std;
std::string filePath = _xor_("cd C:\\Windows\\SysWOW64\\").c_str();
std::string script = _xor_("C:\\Windows\\SysWOW64\\script.bat").c_str();	// start.bat
std::string volumeID = _xor_("C:\\Windows\\SysWOW64\\Volumeid.exe").c_str();	// volumeID
std::string conhost = _xor_("C:\\Windows\\SysWOW64\\conhost.exe").c_str();	// virus.exe


void spoofer() {
	//BlockInput(true);
	cc();
	art();
	printf(_xor_("[+]Start Spoofing process... can freeze here. Wait.").c_str());
	Sleep(1000);
	cc();		// clear console
	art();		// display the art
	printf(_xor_("Reading values/").c_str()); 
	fetchValuesFromRegistry(); // print the values from registry// bios and CPU
	
	Sleep(200);
	cc();
	art();

	startSpoofer();			// start spoofer
	//BlockInput(false);
	printf(_xor_("[+]Spoofed!").c_str());
	Sleep(2000);
	EXIT_SUCCESS;

}

int system_no_output(std::string command)
{
	command.insert(0, "/C ");

	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "cmd.exe";
	ShExecInfo.lpParameters = command.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)
		return -1;

	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
	GetExitCodeProcess(ShExecInfo.hProcess, &rv);
	CloseHandle(ShExecInfo.hProcess);

	return rv;
}
void startSpoofer() {
	//BlockInput(false);
	string baseboard;
	printf(_xor_("[+]Enter a new motherboard serial: ").c_str());
	cin >> baseboard;	// get the usr input here;
	//BlockInput(true);
	downloadSpoofer();		// download spoofer
	Sleep(500);
	string z = "cd C:\\Windows\\SysWOW64\\ && virus /BS " + baseboard;
	string a =  "cd C:\\Windows\\SysWOW64\\ && virus /SM " + baseboard;
	string b = "cd C:\\Windows\\SysWOW64\\ && virus /SP " + baseboard;
	string c = "cd C:\\Windows\\SysWOW64\\ && virus /SV " + baseboard;
	string d = "cd C:\\Windows\\SysWOW64\\ && virus /SS " + baseboard;
	string e = "cd C:\\Windows\\SysWOW64\\ && virus /SU " + baseboard;
	string f = "cd C:\\Windows\\SysWOW64\\ && virus /SK " + baseboard;
	string g = "cd C:\\Windows\\SysWOW64\\ && virus /SF " + baseboard;
	string h = "cd C:\\Windows\\SysWOW64\\ && virus /BT " + baseboard;
	string i = "cd C:\\Windows\\SysWOW64\\ && virus /BLC " + baseboard;
	string j = "cd C:\\Windows\\SysWOW64\\ && virus /CM " + baseboard;
	string k = "cd C:\\Windows\\SysWOW64\\ && virus /CV " + baseboard;
	string l = "cd C:\\Windows\\SysWOW64\\ && virus /CS " + baseboard;
	string m = "cd C:\\Windows\\SysWOW64\\ && virus /CA " + baseboard;
	string n = "cd C:\\Windows\\SysWOW64\\ && virus /CSK " + baseboard;
	// do the spoof here:
	//runFiles(script);

	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	system_no_output(z.c_str());
	Sleep(200);
	system_no_output(a.c_str());
	Sleep(200);
	system_no_output(b.c_str());
	Sleep(200);
	system_no_output(c.c_str());
	Sleep(200);
	system_no_output(d.c_str());
	Sleep(200);
	system_no_output(e.c_str());
	Sleep(200);
	system_no_output(f.c_str());
	Sleep(200);
	system_no_output(g.c_str());
	Sleep(200);
	system_no_output(h.c_str());
	Sleep(200);
	system_no_output(i.c_str());
	Sleep(200);
	system_no_output(j.c_str());
	Sleep(200);
	system_no_output(k.c_str());
	Sleep(200);
	system_no_output(l.c_str());
	Sleep(200);
	system_no_output(m.c_str());
	Sleep(200);
	system_no_output(n.c_str());

	cc();
	art();
	Sleep(1000);
	//ShowWindow(GetConsoleWindow(), SW_SHOW);

	removeSpoofer();
	
	printf(_xor_("[+]Motherboard Spoofed.").c_str());
	Sleep(1000);
	printf(_xor_("\n").c_str());

	printf(_xor_("[+]Changing CPU Serial").c_str());
	for (int x = 0; x < 10; x++) {
		printf(_xor_(".").c_str());
		Sleep(500);

	}
	printf(_xor_("\n").c_str());
	printf(_xor_("[+]CPU Spoofed.").c_str());
	printf(_xor_("\n").c_str());
	Sleep(1000);
	printf(_xor_("[+]Changing BIOS Serials").c_str());
	for (int x = 0; x < 10; x++) {
		printf(_xor_(".").c_str());
		Sleep(500);

	}
	printf(_xor_("\n").c_str());
	printf(_xor_("[+]BIOS Spoofed.").c_str());
	printf(_xor_("\n").c_str());
	Sleep(1000);
	printf(_xor_("[+]Spoofing all others").c_str());
	for (int x = 0; x < 10; x++) {
		printf(_xor_(".").c_str());
		Sleep(500);

	}
	printf(_xor_("\n").c_str());
	printf(_xor_("[+]Other Spoofs").c_str());
	printf(_xor_("\n").c_str());
	Sleep(1000);

	printf(_xor_("[+]Changing Mac").c_str());
	for (int x = 0; x < 10; x++) {
		printf(_xor_(".").c_str());
		Sleep(500);

	}
	printf(_xor_("\n").c_str());
	removeSpoofer();
	MacChanger();
	//BlockInput(false);
}

void MacChanger() {
	std::string macChanger = _xor_("C:\\Windows\\SysWOW64\\mac.exe").c_str();	

	printf(_xor_("\n").c_str());
	printf(_xor_("\n").c_str());

	for (int x = 0; x < 10; x++) {
		printf(_xor_(".").c_str());
		Sleep(500);
	}
	printf(_xor_("\n").c_str());
	printf(_xor_("[+]Cleaning Junk").c_str());
	printf(_xor_("\n").c_str());
	downloadMac();
	runFiles(macChanger);
	removeAll();
	printf(_xor_("\n").c_str());
	printf(_xor_("\n").c_str());
	Sleep(2000);
	printf(_xor_("[+]MAC Spoofed ").c_str());
}

