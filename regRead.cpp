#include <windows.h>
#include <iostream>

void registry_read(LPCTSTR subkey, LPCTSTR name, DWORD type)
{
	HKEY key;
	TCHAR value[255];
	DWORD value_length = 255;
	RegOpenKey(HKEY_LOCAL_MACHINE, subkey, &key);
	RegQueryValueEx(key, name, NULL, &type, (LPBYTE)&value, &value_length);
	RegCloseKey(key);
	printf(value);
	//return value[255];
	
}

void registry_write(LPCTSTR subkey, LPCTSTR name, DWORD type, const char* value)
{
	HKEY key;
	RegOpenKey(HKEY_LOCAL_MACHINE, subkey, &key);
	RegSetValueEx(key, name, 0, type, (LPBYTE)value, strlen(value) * sizeof(char));
	RegCloseKey(key);
}