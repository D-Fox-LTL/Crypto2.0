#pragma once
#include <string.h>
#include <stdio.h>

#define MaxLen 1024
#define CryptKey 8



//abstraktn� t��da je t��da, kter� m� zakompovanou n�jakou abstraktn� fce			nelze ud�lat objekt
class clsProtoCrypto
{
public:
	//konstruktor
	clsProtoCrypto() {};

	//open file
	virtual bool OpenFile(const char* p_chNameSource, const char* p_chNameDest) = 0;		//virtual - bude nahrazena			...=0, t��da je abstraktn�

	//close file
	virtual bool CloseFile() = 0;

	// Crypt file
	virtual bool Crypt() = 0;

	// Decrypt file
	virtual bool Decrypt() = 0;
};

