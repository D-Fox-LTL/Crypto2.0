#pragma once
#include "clsProtoCrypto.h"
#include <Windows.h>

class clsCryptoX :public clsProtoCrypto
{
public:
	clsCryptoX();
	//open file
	virtual bool OpenFile(const char* p_chNameSource, const char* p_chNameDest);

	//close file
	virtual bool CloseFile();

	// Crypt file
	virtual bool Crypt();

	// Decrypt file
	virtual bool Decrypt();
};

