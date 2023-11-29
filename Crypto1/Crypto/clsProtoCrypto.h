#pragma once
#include <string.h>
#include <stdio.h>

#define MaxLen 1024
#define CryptKey 8



//abstraktní tøída je tøída, která má zakompovanou nìjakou abstraktní fce			nelze udìlat objekt
class clsProtoCrypto
{
public:
	//konstruktor
	clsProtoCrypto() {};

	//open file
	virtual bool OpenFile(const char* p_chNameSource, const char* p_chNameDest) = 0;		//virtual - bude nahrazena			...=0, tøída je abstraktní

	//close file
	virtual bool CloseFile() = 0;

	// Crypt file
	virtual bool Crypt() = 0;

	// Decrypt file
	virtual bool Decrypt() = 0;
};

