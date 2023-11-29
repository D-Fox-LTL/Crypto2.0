#include "clsCryptoX.h"

clsCryptoX::clsCryptoX()
{
}


//open file
bool clsCryptoX::OpenFile(const char* p_chNameSource, const char* p_chNameDest)
{
	HANDLE hFile;

	hFile = CreateFile(L"p_chNameSource", GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	return false;
}

//close file
bool clsCryptoX::CloseFile()
{
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