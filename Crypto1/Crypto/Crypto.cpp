
#include <iostream>
#include <stdio.h>
#include "clsCrypto.h"
#include "clsProtoCrypto.h"
#include "clsCryptoX.h"

int main()
{
    clsCrypto * p_lobjCrypto;
    clsCryptoX* p_lobjCryptoX;
    clsProtoCrypto* p_lobjProtoCrypto;


    // vytvořit objekt
    p_lobjCrypto = new clsCrypto();
    p_lobjCryptoX = new clsCryptoX();

    p_lobjProtoCrypto = p_lobjCryptoX;

    // otevřít soubor
    p_lobjProtoCrypto->OpenFile("c:\\temp\\test.txt", "c:\\temp\\testcrypt.txt");

    //zašifrovat
    p_lobjProtoCrypto->Crypt();

    // zavřít soubor
    p_lobjProtoCrypto->CloseFile();

    //otevřít soubor
    p_lobjProtoCrypto->OpenFile("c:\\temp\\testcrypt.txt", "c:\\temp\\testdecrypt.txt");

    //dešifrovat
    p_lobjProtoCrypto->Decrypt();

    // zavřít soubor
    p_lobjProtoCrypto->CloseFile();

    // zlikvidovat objekt
    delete(p_lobjCrypto);
}


