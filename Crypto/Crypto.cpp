
#include <iostream>
#include <stdio.h>
#include "clsCrypto.h"
#include "clsProtoCrypto.h"
#include "clsCryptoX.h"

int main()
{
    //clsCrypto * p_lobjCrypto;
    clsCryptoX* p_lobjCryptoX;
    //clsProtoCrypto* p_lobjProtoCrypto;


    // vytvořit objekt
    //p_lobjCrypto = new clsCrypto();
    p_lobjCryptoX = new clsCryptoX();

    //p_lobjProtoCrypto = p_lobjCryptoX;

    // otevřít soubor
    p_lobjCryptoX->OpenFile(L"c:\\temp\\test.txt", L"c:\\temp\\testcrypt.txt");

    //zašifrovat
    /*p_lobjProtoCrypto*/p_lobjCryptoX->Crypt();

    // zavřít soubor
    /*p_lobjProtoCrypto*/p_lobjCryptoX->CloseFile();

    //otevřít soubor
    p_lobjCryptoX->OpenFile(L"c:\\temp\\testcrypt.txt", L"c:\\temp\\testdecrypt.txt");

    //dešifrovat
    /*p_lobjProtoCrypto*/p_lobjCryptoX->Decrypt();

    // zavřít soubor
    /*p_lobjProtoCrypto*/p_lobjCryptoX->CloseFile();

    // zlikvidovat objekt
    delete(/*p_lobjProtoCrypto*/p_lobjCryptoX);
}


