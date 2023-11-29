#include "clsCrypto.h"

//konstruktor
clsCrypto::clsCrypto()
{
	// nastavit, že soubor není otevøený
	p_mFileSource = NULL;
}

//open file
bool clsCrypto::OpenFile(const char* p_chNameSource, const char * p_chNameDest)
{
	int lintLen;

	// kopie nazvu souboru
	lintLen = strnlen_s(p_chNameSource, MaxLen);
	p_mchFileNameSource = new char[lintLen+1];
	strcpy_s(p_mchFileNameSource, lintLen+1, p_chNameSource);

	// otevøení souboru
	fopen_s(&p_mFileSource, p_mchFileNameSource, "r");
	//if (p_mFileSource != NULL)
	//{
	//	return true;
	//}

		// kopie nzvu souboru
	lintLen = strnlen_s(p_chNameDest, MaxLen);
	p_mchFileNameDest = new char[lintLen + 1];
	strcpy_s(p_mchFileNameDest, lintLen + 1, p_chNameDest);

	// otevøení souboru
	fopen_s(&p_mFileDest, p_mchFileNameDest, "w");
	

	// Test zda se všechno otevøelo

	if ((p_mFileSource == NULL || p_mchFileNameDest == NULL))
	{
		//zavøít soubory
		CloseFile();

		return false;
	}

	return true;
}

//close file
bool clsCrypto::CloseFile()
{
	if (p_mFileSource != NULL)
	{
		fclose(p_mFileSource);
		p_mFileSource = NULL;
	}

	// test zda je cílový soubor 
	if (p_mFileDest != NULL)
	{
		fclose(p_mFileDest);
		p_mFileDest = NULL;
	}

	if (p_mFileSource == NULL && p_mchFileNameDest == NULL)
	{
		return true;
	}

	return false;
}

// šifrování souboru
bool clsCrypto::Crypt()
{
	unsigned char lchBufferCrypt;
	int lintCountCrypt;

	// test zda je soubor otevøen
	if (p_mFileSource == NULL || p_mchFileNameDest == NULL)
	{
		return false;
	}

	do
	{
		//ètení jednoho bytu ze souboru
		lintCountCrypt =fread_s(&lchBufferCrypt, 1, 1, 1, p_mFileSource);

		// jsem na konci souboru
		if (lintCountCrypt == 0) break;

		// šífrování
		lchBufferCrypt = lchBufferCrypt - CryptKey;

		// zapis jednoho byte do souboru
		fwrite(&lchBufferCrypt, 1, 1, p_mFileDest);
	} while (lintCountCrypt != EOF); // end of file

	return true;
}

bool clsCrypto::Decrypt()
{
	unsigned char lchBufferDecrypt;
	int lintCountDecrypt;

	// test zda je soubor otevøen
	if (p_mFileSource == NULL || p_mchFileNameDest == NULL)
	{
		return false;
	}

	do
	{
		//ètení jednoho bytu ze souboru
		lintCountDecrypt = fread_s(&lchBufferDecrypt, 1, 1, 1, p_mFileSource);

		// jsem na konci souboru
		if (lintCountDecrypt == 0) break;

		// dešífrování
		lchBufferDecrypt = lchBufferDecrypt + CryptKey;

		// zapis jednoho byte do souboru
		fwrite(&lchBufferDecrypt, 1, 1, p_mFileDest);
	} while (lintCountDecrypt != EOF); // end of file

	return true;
}