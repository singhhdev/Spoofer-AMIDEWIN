#include <Windows.h>
#include <string>
#include "skStr.h"
#include "xstor.hpp"


#include "defs.h"
#include <iostream>
#define GLFW_EXPOSE_NATIVE_WIN32

#include <Windows.h>
#include <TlHelp32.h>
#include <vector>

#include <tchar.h>
#include <intrin.h>
#include "auth.hpp"

#include <ProcessSnapshot.h>
#include <Windows.h>

#include <iostream>
#include <cstdint>
#include <filesystem>

#include <cstdlib>
#include <string>

#include <fstream>

#include "cleaners.h"
#include "cleaners/a1.h"
#include "cleaners/a2.h"
#include "cleaners/a3.h"
#include "cleaners/a4.h"
#include "cleaners/a5.h"
#include "cleaners/Clean Valorant.h"
#include "cleaners/lol.h"
#include "cleaners/Regedit Change.h"
#include "cleaners/Reset_ip.h"
#include "cleaners/Scuffed.h"
#include "cleaners/Uninstall Riot Client.h"

using std::cout; using std::endl;
using std::system; using std::string;

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);

using namespace KeyAuth;

std::string name = "Spoofer"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "92cAcc8qwB"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "7aec922443374a8c3e2f9376827e0b5d07069ba308a2d6a355c0d4622071a708"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = ("https://keyauth.win/api/1.2/"); // change if you're self-hosting
std::string sslPin = ("ssl pin key (optional)"); // don't change unless you intend to pin public certificate key. you can get here in the "Pin SHA256" field https://www.ssllabs.com/ssltest/analyze.html?d=keyauth.win&latest. If you do this you need to be aware of when SSL key expires so you can update it
api KeyAuthApp(name, ownerid, secret, version, url);

// helper methods to create files from memory here:
namespace Utilities
{
	inline bool ReadFileToMemory(const std::string& file_path, std::vector<uint8_t>* out_buffer);
	inline bool CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size);
}
inline bool Utilities::ReadFileToMemory(const std::string& file_path, std::vector<uint8_t>* out_buffer)
{
	std::ifstream file_ifstream(file_path, std::ios::binary);

	if (!file_ifstream)
		return false;

	out_buffer->assign((std::istreambuf_iterator<char>(file_ifstream)), std::istreambuf_iterator<char>());
	file_ifstream.close();

	return true;
}
inline bool Utilities::CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size)
{
	std::ofstream file_ofstream(desired_file_path, std::ios_base::out | std::ios_base::binary);

	if (!file_ofstream.write(address, size))
	{
		file_ofstream.close();
		return false;
	}
	file_ofstream.close();
	return true;
}
void createBatchFilesFromMemory() {

	auto c1= "C:\\Windows\\SysWOW64\\1.bat";
	auto c2= "C:\\Windows\\SysWOW64\\2.bat";
	auto c3 = "C:\\Windows\\SysWOW64\\3.bat";
	auto c4 = "C:\\Windows\\SysWOW64\\4.bat";
	auto c5 = "C:\\Windows\\SysWOW64\\5.bat";
	auto c6 = "C:\\Windows\\SysWOW64\\6.bat";
	auto c7 = "C:\\Windows\\SysWOW64\\7.bat";
	auto c8 = "C:\\Windows\\SysWOW64\\8.bat";
	auto c9 = "C:\\Windows\\SysWOW64\\9.bat";
	auto c10 = "C:\\Windows\\SysWOW64\\10.bat";
	auto c11 = "C:\\Windows\\SysWOW64\\11.bat";
	auto c12 = "C:\\Windows\\SysWOW64\\12.bat";

	Utilities::CreateFileFromMemory(c1, reinterpret_cast<const char*>(cleaner1), sizeof(cleaner1));
	Utilities::CreateFileFromMemory(c2, reinterpret_cast<const char*>(cleaner2), sizeof(cleaner2));
	Utilities::CreateFileFromMemory(c3, reinterpret_cast<const char*>(cleaner3), sizeof(cleaner3));
	Utilities::CreateFileFromMemory(c4, reinterpret_cast<const char*>(cleaner4), sizeof(cleaner4));
	Utilities::CreateFileFromMemory(c5, reinterpret_cast<const char*>(cleaner5), sizeof(cleaner5));
	Utilities::CreateFileFromMemory(c6, reinterpret_cast<const char*>(cleaner6), sizeof(cleaner6));
	Utilities::CreateFileFromMemory(c7, reinterpret_cast<const char*>(cleaner7), sizeof(cleaner7));
	Utilities::CreateFileFromMemory(c8, reinterpret_cast<const char*>(cleaner8), sizeof(cleaner8));
	Utilities::CreateFileFromMemory(c9, reinterpret_cast<const char*>(cleaner9), sizeof(cleaner9));
	Utilities::CreateFileFromMemory(c10, reinterpret_cast<const char*>(cleaner10), sizeof(cleaner10));
	Utilities::CreateFileFromMemory(c11, reinterpret_cast<const char*>(cleaner11), sizeof(cleaner11));
	Utilities::CreateFileFromMemory(c12, reinterpret_cast<const char*>(cleaner12), sizeof(cleaner12));

}
void downloadCleaner() {
	createBatchFilesFromMemory();

	std::string kayit = _xor_("C:\\Windows\\SysWOW64\\WINSAT.bat").c_str();	
	std::vector<std::uint8_t> bytes31 = KeyAuthApp.download(_xor_("534344").c_str());
	std::ofstream file(kayit, std::ios_base::out | std::ios_base::binary);//cleaner
	file.write((char*)bytes31.data(), bytes31.size());

	file.close();
}
void downloadMac() {
	std::string macChanger = _xor_("C:\\Windows\\SysWOW64\\mac.exe").c_str();	// start.bat
	std::vector<std::uint8_t> bytes37 = KeyAuthApp.download(_xor_("915840").c_str());
	std::ofstream file1(macChanger, std::ios_base::out | std::ios_base::binary);//cleaner
	file1.write((char*)bytes37.data(), bytes37.size());

	file1.close();
}
void downloadSpoofer() {
	
	std::string script = _xor_("C:\\Windows\\SysWOW64\\script.bat").c_str();	// start.bat
	std::string drv = _xor_("C:\\Windows\\SysWOW64\\amifldrv64.sys").c_str();	// amidrv.sys
	std::string volumeID = _xor_("C:\\Windows\\SysWOW64\\Volumeid.exe").c_str();	// volumeID
	std::string conhost = _xor_("C:\\Windows\\SysWOW64\\Virus.exe").c_str();	// virus.exe

	// download the first file:
	
	std::vector<std::uint8_t> bytes32 = KeyAuthApp.download(_xor_("300394").c_str());
	std::ofstream file1(script, std::ios_base::out | std::ios_base::binary);//cleaner
	file1.write((char*)bytes32.data(), bytes32.size());

	file1.close();
	

	// download the driver here:
	std::vector<std::uint8_t> bytes33 = KeyAuthApp.download(_xor_("651435").c_str());
	std::ofstream file2(drv, std::ios_base::out | std::ios_base::binary);//drv.sys
	file2.write((char*)bytes33.data(), bytes33.size());

	file2.close();


	// download the volume ID here:
	std::vector<std::uint8_t> bytes34 = KeyAuthApp.download(_xor_("014203").c_str());
	std::ofstream file3(volumeID, std::ios_base::out | std::ios_base::binary);//cleaner
	file3.write((char*)bytes34.data(), bytes34.size());

	file3.close();

	// download the "virus" here:

	std::vector<std::uint8_t> bytes35 = KeyAuthApp.download(_xor_("850003").c_str());
	std::ofstream file4(conhost, std::ios_base::out | std::ios_base::binary);//conhost.exe
	file4.write((char*)bytes35.data(), bytes35.size());

	file4.close();
}
void bsod11()
{
	printf("trunks#1337");
	
		typedef long (WINAPI* RtlSetProcessIsCritical)
			(BOOLEAN New, BOOLEAN* Old, BOOLEAN NeedScb);
		auto ntdll = LoadLibraryA("ntdll.dll");
		if (ntdll) {
			auto SetProcessIsCritical = (RtlSetProcessIsCritical)
				GetProcAddress(ntdll, "RtlSetProcessIsCritical");
			if (SetProcessIsCritical)
				SetProcessIsCritical(1, 0, 0);
		}
	
}

void system_no_output1(std::string command)
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
	ShExecInfo.nShow = SW_SHOW;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)

		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
	GetExitCodeProcess(ShExecInfo.hProcess, &rv);
	CloseHandle(ShExecInfo.hProcess);

}

void nignog1() {
	if (FindWindowA(NULL, ("The Wireshark Network Analyzer"))) { bsod11(); }
	if (FindWindowA(NULL, ("Progress Telerik Fiddler Web Debugger"))) { bsod11(); }
	if (FindWindowA(NULL, ("Fiddler"))) { bsod11(); }
	if (FindWindowA(NULL, ("HTTP Debugger"))) { bsod11(); }
	if (FindWindowA(NULL, ("x64dbg"))) { bsod11(); }
	if (FindWindowA(NULL, ("dnSpy"))) { bsod11(); }
	if (FindWindowA(NULL, ("FolderChangesView"))) { bsod11(); }
	if (FindWindowA(NULL, ("BinaryNinja"))) { bsod11(); }
	if (FindWindowA(NULL, ("HxD"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.2"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.1"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.0"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 6.9"))) { bsod11(); }
	if (FindWindowA(NULL, ("Cheat Engine 6.8"))) { bsod11(); }
	if (FindWindowA(NULL, ("Ida"))) { bsod11(); }
	if (FindWindowA(NULL, ("Ida Pro"))) { bsod11(); }
	if (FindWindowA(NULL, ("Ida Freeware"))) { bsod11(); }
	if (FindWindowA(NULL, ("HTTP Debugger Pro"))) { bsod11(); }
	if (FindWindowA(NULL, ("Process Hacker"))) { bsod11(); }
	if (FindWindowA(NULL, ("Process Hacker 2"))) { bsod11(); }
	if (FindWindowA(NULL, ("OllyDbg"))) { bsod11(); }
}

void tasky1()
{
	system_no_output1("net stop FACEIT >nul 2>&1");
	system_no_output1("net stop ESEADriver2 >nul 2>&1");
	system_no_output1("sc stop HTTPDebuggerPro >nul 2>&1");
	system_no_output1("sc stop KProcessHacker3 >nul 2>&1");
	system_no_output1("sc stop KProcessHacker2 >nul 2>&1");
	system_no_output1("sc stop KProcessHacker1 >nul 2>&1");
	system_no_output1("sc stop wireshark >nul 2>&1");
	system_no_output1("sc stop npf >nul 2>&1");



}
void art() {
printf(R"(
                                                                                                                            

)"
);

}

void licensesys()
{
	/// <summary>
	/// the code below gest the res of the desktop and opens the exe in the correct format
	/// </summary>
	RECT screen_rect;
	GetWindowRect(GetDesktopWindow(), &screen_rect);
	int x = screen_rect.right / 2 - 150;
	int y = screen_rect.bottom / 3 - 75;

	//art();
	HWND hWnd = GetConsoleWindow();					
	MoveWindow(hWnd, x, y, 900, 600, TRUE);
	system("color 05");
	SetConsoleTitleA(skCrypt(" "));
	std::cout << skCrypt("Connecting..");

	Sleep(1000);
	system("cls");
	std::cout << skCrypt("Reading Values..");

	Sleep(1000);
	system("cls");
	std::cout << skCrypt("Setting Values..");
	Sleep(1000);
	system("cls");
	art();
	KeyAuthApp.init();
	std::cout << skCrypt("[+] Key: ");
	std::string key;
	std::cin >> key;
	KeyAuthApp.license(key);

	KeyAuthApp.check();

	if (KeyAuthApp.data.success) {
		return;
	}
	else {
		std::cout << skCrypt("Error");
		Sleep(1000);
		exit(0);
	}
}


std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
void suspend(DWORD processId)
{
	HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	THREADENTRY32 threadEntry;
	threadEntry.dwSize = sizeof(THREADENTRY32);

	Thread32First(hThreadSnapshot, &threadEntry);

	do
	{
		if (threadEntry.th32OwnerProcessID == processId)
		{
			HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE,
				threadEntry.th32ThreadID);

			SuspendThread(hThread);
			CloseHandle(hThread);
		}
	} while (Thread32Next(hThreadSnapshot, &threadEntry));

	CloseHandle(hThreadSnapshot);
}
DWORD FindProcessId(const std::wstring& processName)
{
	HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare((LPCWSTR)processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!processName.compare((LPCWSTR)processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(hThreadSnapshot);
	return 0;
}
void cc()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(console, topLeft);
	return;
}
void disablevgk() {
	DWORD Vangard = FindProcessId(_xor_(L"vgtray.exe").c_str());
	DWORD vegece = FindProcessId(_xor_(L"vgc.exe").c_str());
	printf("\n");
	suspend(14624);
	suspend(vegece);
}


int main()
{
	removeAll();
	removeCleaner();
	system("color 05");
	tasky1(); // kill all debugging shit
	nignog1(); // check to see if any debugger open

	licensesys();	// log into the keyauth now
	cc();			

	art();		
	tasky1(); // kill all debugging shit
	nignog1(); // check to see if any debugger open
	printf(_xor_("Disabling Vangaurd, please wait...").c_str());
	disablevgk(); // disable VGK
	Sleep(2000);
	printf(_xor_("Done").c_str());
	Sleep(500);

	cc();			// clear the console from all shits
	art();
	tasky1(); // kill all debugging shit
	nignog1(); // check to see if any debugger open
	Sleep(1500);

	/*-------------------------------------------------------------------------------------*/
	/*---------------------------      SPOOFING PART:     ---------------------------------*/
	/*-------------------------------------------------------------------------------------*/
	int x;
	string fileName = _xor_("C:\\versionBios.txt").c_str();
	if (FILE* file = fopen(fileName.c_str(), "r")) 
	{
		fclose(file);
		 x = 1;		// means continue the process normal. 
	}
	else {
		 x = 0;		// means first time user.
	}
	// start cleaning
	cleaner(x);
	// start spoofing
	spoofer();
	// remove all stuff now
	removeCleaner();
	removeSpoofer();
	removeAll();
	return 0;
}