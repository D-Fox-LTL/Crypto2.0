#include "clsCryptoX.h"

clsCryptoX::clsCryptoX()
{
}
		//TODO: sifrovaci metoda a vse o ni, kontroly

//open file
bool clsCryptoX::OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest)
{
	//File opening
	hFile = CreateFile(p_chNameSource, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	//File mapping
	hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, NULL);

	//Mapping of file view
	p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping, FILE_MAP_COPY, 0, 0, 0);

	return false;
}

//close file
bool clsCryptoX::CloseFile()
{
	//save of changes
	FlushViewOfFile(p_mSourceFirstByte, 0);

	//Unmapping
	UnmapViewOfFile(p_mSourceFirstByte);

	//closing of handles
	CloseHandle(hFileMapping);
	CloseHandle(hFile);


	return false;
}

// Crypt file
bool clsCryptoX::Crypt()
{
	return false;
}

// Decrypt file
bool clsCryptoX::Decrypt()
{
	return false;
}