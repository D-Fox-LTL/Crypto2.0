#include "clsCryptoX.h"
//#include <stdio.h>
#include <Windows.h>

clsCryptoX::clsCryptoX()
{
}
		//TODO: sifrovaci metoda a vse o ni, kontroly

int clsCryptoX::Animat()
{
	printf("\n.");
	Sleep(1000);
	printf("\n..");
	Sleep(1000);
	printf("\n...");
	Sleep(1000);
	printf("\n....\n");
	Sleep(1000);
	return 0;
}


//open file
bool clsCryptoX::OpenFile(LPCWSTR p_chNameSource, LPCWSTR p_chNameDest)
{
	printf("Opening file\n");

	//File opening
	hFile = CreateFile(p_chNameSource, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);


	//File mapping
	hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, NULL);

	//Mapping of file view
	p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping, FILE_MAP_COPY, 0, 0, 0);

	//File opening
	hFile = CreateFile(p_chNameDest, GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);


	//File mapping
	hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, NULL);


	DWORD fileSize = GetFileSize(hFile, NULL);
	printf("FileSize is: %u", fileSize);
	Animat();


	return false;
}

//close file
bool clsCryptoX::CloseFile()
{
	printf("Closing file");

	//save of changes
	FlushViewOfFile(p_mSourceFirstByte, 0);

	//Unmapping
	UnmapViewOfFile(p_mSourceFirstByte);

	//closing of handles
	CloseHandle(hFileMapping);
	CloseHandle(hFile);

	Animat();
	system("cls");

	return false;
}

// Crypt file
bool clsCryptoX::Crypt()
{
	printf("Encrypting file");
	Animat();

	GetFileSizeEx(hFile, &pintFileSize);

	SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

		for (int i = 0; i < pintFileSize.QuadPart; i++) {

			p_mSourceFirstByte[i] += 3;
		}

		SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

		WriteFile(hFile, p_mSourceFirstByte, pintFileSize.QuadPart, &dwBytesWritten, NULL);

	return true;
}

// Decrypt file
bool clsCryptoX::Decrypt()
{
	printf("Decrypting file");
	Animat();

	GetFileSizeEx(hFile, &pintFileSize);

	SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

	for (int i = 0; i < pintFileSize.QuadPart; i++) {

		p_mSourceFirstByte[i] -= 3;
	}

	SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

	WriteFile(hFile, p_mSourceFirstByte, pintFileSize.QuadPart, &dwBytesWritten, NULL);

	return true;
}