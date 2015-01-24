#include <tchar.h>
#include <stdio.h>
#include <windows.h>
int main(void)
{
    TCHAR szPath[MAX_PATH];
    DWORD pathLen = 0;

    // GetModuleFileName returns the number of characters
    // written to the array.
    pathLen = GetModuleFileName(NULL, szPath, MAX_PATH);
    if (pathLen == 0)
    {
	_tprintf(TEXT("Unable to get module file name; last error = %lu\n"), GetLastError());
	return -1;
    }

    HKEY newValue;

    if (RegOpenKey(HKEY_LOCAL_MACHINE,
	TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"),
	&newValue) != ERROR_SUCCESS)
    {
	_tprintf(TEXT("Unable to open registry key; last error = %lu\n"), GetLastError());
	system("pause");
    }
 
    // Need to pass the length of the path string in bytes,
    // which may not equal the number of characters due to
    // character set.
    DWORD pathLenInBytes = pathLen * sizeof(*szPath);
    if (RegSetValueEx(newValue,
	TEXT("name_me"),
	0,
	REG_SZ,
	(LPBYTE)szPath,
	pathLenInBytes) != ERROR_SUCCESS)
    {
	RegCloseKey(newValue);
	_tprintf(TEXT("Unable to set registry value; last error = %lu\n"), GetLastError());
	return -1;
    }

    RegCloseKey(newValue);

    return 0;
}
