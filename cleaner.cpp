#include "defs.h"
#include <iostream>
#include <Windows.h>
#include "xstor.hpp"
#include <tchar.h>
using namespace std;
std::string WINSAT = _xor_("C:\\Windows\\SysWOW64\\WINSAT.bat").c_str();	
std::string cleaner1 = _xor_("C:\\Windows\\SysWOW64\\1.bat").c_str();
std::string cleaner2 = _xor_("C:\\Windows\\SysWOW64\\2.bat").c_str();
std::string cleaner3 = _xor_("C:\\Windows\\SysWOW64\\3.bat").c_str();
std::string cleaner4 = _xor_("C:\\Windows\\SysWOW64\\4.bat").c_str();
std::string cleaner5 = _xor_("C:\\Windows\\SysWOW64\\5.bat").c_str();
std::string cleaner6 = _xor_("C:\\Windows\\SysWOW64\\6.bat").c_str();
std::string cleaner7 = _xor_("C:\\Windows\\SysWOW64\\7.bat").c_str();
std::string cleaner8 = _xor_("C:\\Windows\\SysWOW64\\8.bat").c_str();
std::string cleaner9 = _xor_("C:\\Windows\\SysWOW64\\9.bat").c_str();
std::string cleaner10 = _xor_("C:\\Windows\\SysWOW64\\10.bat").c_str();
std::string cleaner11= _xor_("C:\\Windows\\SysWOW64\\11.bat").c_str();
std::string cleaner12 = _xor_("C:\\Windows\\SysWOW64\\12.bat").c_str();

void runFiles(string fileName)
{
	string newFile = fileName.c_str();

	SHELLEXECUTEINFO ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = newFile.c_str();
	ShExecInfo.lpParameters = "";
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
	CloseHandle(ShExecInfo.hProcess);
	//removeCleaner();

}
void cleaner(int x) {
	//(true);
	/*
				if x = 0, then it is the first time,
				if x = 1, then user has already used the program.
	*/
	if (x == 0) {
		cc();
		art();
		printf(_xor_("[+]First Time Usage!\n").c_str());
		Sleep(300);
		downloadCleaner();
		printf("\n\n\n");
		printf(_xor_("[+]Cleaning... will take time and can freeze. Please wait.\n").c_str());
		runFiles(WINSAT);
		runFiles(cleaner1);
		runFiles(cleaner2);
		runFiles(cleaner3);
		runFiles(cleaner4);
		runFiles(cleaner5);
		runFiles(cleaner6);
		runFiles(cleaner7);
		runFiles(cleaner8);
		runFiles(cleaner9);
		runFiles(cleaner10);
		runFiles(cleaner11);
		runFiles(cleaner12);
		removeCleaner();
		printf(_xor_("[+]Cleaned").c_str());
		printf(_xor_("\n").c_str());
		Sleep(500);
		cc();
		art();

		printf(_xor_("[+]Dumping BIOS Version").c_str());
		printf(_xor_("/").c_str());Sleep(200);
		printf(_xor_("/").c_str());Sleep(200);
		printf(_xor_("/").c_str());Sleep(200);
		printf(_xor_("/").c_str());Sleep(200);
		printf(_xor_("/").c_str());Sleep(200);
		printf(_xor_("/").c_str());Sleep(200);
		printf(_xor_("/").c_str());Sleep(200);
		printf(_xor_("/").c_str());Sleep(200);
		printf(_xor_("/").c_str());Sleep(200);
		printf(_xor_("/").c_str());Sleep(200);
		Sleep(1000);
		printf(_xor_("\n").c_str());
		printf(_xor_("\n").c_str());
		printf(_xor_("\n").c_str());
		// dump the bios version first:
		compareBios();
		printf(_xor_("[+]Bios Version Stored\n").c_str());
		Sleep(1000);
		removeCleaner();
		cc();
		printf(_xor_("[+]FLASH YOUR BIOS NOW!").c_str());
		Sleep(3000);		
		exit(0);
		
	} 

	if (x == 1) {	// bios has been changed detected
		//BlockInput(true);
		// open the current bios file and compare.
		cc();
		art();
		printf(_xor_("[+]Comparing BIOS Vers \n").c_str());
		Sleep(1000);
		//dumpCurrentBios();
		bool isSame = compareSecondTime();
		if (isSame = true) {
			printf(_xor_("[+]Bios Changed. Success!").c_str());
			printf(_xor_("\n").c_str());
			Sleep(1000);
			downloadCleaner();
			cc();
			art();
			printf(_xor_("[+]Cleaning... will take time and can freeze. Please wait.\n").c_str());
			runFiles(WINSAT);
			runFiles(cleaner1);
			runFiles(cleaner2);
			runFiles(cleaner3);
			runFiles(cleaner4);
			runFiles(cleaner5);
			runFiles(cleaner6);
			runFiles(cleaner7);
			runFiles(cleaner8);
			runFiles(cleaner9);
			runFiles(cleaner10);
			runFiles(cleaner11);
			runFiles(cleaner12);
			removeCleaner();
			printf(_xor_("[+]Cleaned").c_str());
			Sleep(1000);
			printf(_xor_("[+]Cleaned BIOS Files").c_str());
			Sleep(1000);

			cc();
			art();
			
			printf(_xor_("[+]Dumping The Current BIOS Version").c_str());
			Sleep(500);
			printf(_xor_("/").c_str());Sleep(500);
			printf(_xor_("/").c_str());Sleep(500);
			printf(_xor_("/").c_str());Sleep(500);
			printf(_xor_("/").c_str());Sleep(500);
			printf(_xor_("/").c_str());Sleep(500);
			printf(_xor_("/").c_str());Sleep(200);
			printf(_xor_("/").c_str());Sleep(200);
			printf(_xor_("/").c_str());Sleep(200);
			printf(_xor_("/").c_str());Sleep(200);
			printf(_xor_("/").c_str());Sleep(200);
			printf(_xor_("\n").c_str());Sleep(200);
			Sleep(200);
			// dump the bios version first:
			//compareBios();
			printf(_xor_("[+]Done ").c_str());
			printf(_xor_("\n").c_str());

			Sleep(2000);
			printf(_xor_("[+]Now Spoofing. ").c_str());
			spoofer();

			printf(_xor_("[+]Done ").c_str());


			EXIT_SUCCESS;
		}
		else if(isSame = false) {
			cc();			// dumbos
			art();
			printf(_xor_("[+]Comparing BIOS Vers ").c_str());
			printf(_xor_("\n").c_str());

			Sleep(1000);
			printf(_xor_("[+]Failed. Please FLASH Bios Correctly! \n Make a ticket on Trunks Server for help!").c_str());
			Sleep(1000);
			//BlockInput(false);
			exit(0);
		}
		//BlockInput(false);


	}
	
}



