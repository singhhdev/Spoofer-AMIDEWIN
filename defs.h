#include <iostream>
#include <Windows.h>

void cleaner(int x);
void spoofer();
void exit();
void download();
void art();
void cc();
void registry_read(LPCTSTR subkey, LPCTSTR name, DWORD type);
void registry_write(LPCTSTR subkey, LPCTSTR name, DWORD type, const char* value);
void fetchValuesFromRegistry();
void system_no_output1(std::string command);
void downloadCleaner();
void removeCleaner();
void removeSpoofer();
void finalCleanUp();
void compareBios();
bool compareSecondTime();
void downloadCleaner();
void downloadSpoofer();
void runFiles(std::string fileName);
void downloadMac();
void removeAll();
void dumpCurrentBios();
