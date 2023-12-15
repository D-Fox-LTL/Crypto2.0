#pragma once
#include "clsProtoCrypto.h"
#include <Windows.h>

class clsCryptoX :public clsProtoCrypto
{
public:
	clsCryptoX();
	//open file
	bool OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest);

	//close file
	virtual bool CloseFile();

	// Crypt file
	virtual bool Crypt();

	// Decrypt file
	virtual bool Decrypt();
private:
	//	Animation
	virtual int Animat();
	PBYTE p_mSourceFirstByte;
	PBYTE p_mDestFirstByte;
	HANDLE hFile, hFileMapping;		/*Handle je manipulacni cislo			H / Address		->		1	/	/\ / \ / \ / \ / \ / \ / \ / \ / \ / \ / \*/
	LARGE_INTEGER pintFileSize;
	DWORD dwBytesWritten;
};

