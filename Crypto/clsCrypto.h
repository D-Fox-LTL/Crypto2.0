#pragma once
#include <string.h>
#include <stdio.h>
#include "clsProtoCrypto.h"

#define MaxLen 1024
#define CryptKey 8



class clsCrypto: public clsProtoCrypto		//zdìï public vìci z tøídy clsProtoCrypto
{
public:
	//konstruktor
	clsCrypto();

	//open file
	bool OpenFile(const char* p_chNameSource, const char* p_chNameDest);

	//close file
	bool CloseFile();

	// Crypt file
	bool Crypt();

	// Decrypt file
	bool Decrypt();

private:
	char* p_mchFileNameSource; // nazev souboru
	FILE* p_mFileSource;
	char* p_mchFileNameDest; // nazev souboru
	FILE* p_mFileDest;
};

