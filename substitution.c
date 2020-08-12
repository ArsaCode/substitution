#include <stdio.h>
#include "cs50.h"
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


/*
Caesar Key encrypter v1.0 - Developed by Arsalan Ghassemi
*/

// Variables and functions declarations
bool checkKey(string k);

/*
Hello ! This is the Substitution key encrypter made for the Problem Set 2 of CS50's Introduction to Computer Science course.
The user should input the key in the command prompt after the ./substitution key (key as a 26 characters long input) command.

The software works as follows :

1 . Get the users input and checks if it's valid
2 . Assigns the key entered by the user to an integer
3 . Gets the plain text from the user
4 . Ciphers the text using Substitution cipher method
5 . Prints back the ciphered text in result for the user.

Feel free to send any suggestions at contact@arsadevs.com 
*/

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!checkKey(argv[1]))
    {
        printf("Key should contain 26 characters.\n");
        return 1;
    }

    string plainText = get_string("plaintext: ");
    string diff = argv[1];
    for (int i = 'A'; i <= 'Z'; i++)
    {
        diff[i - 'A'] = toupper(diff[i - 'A']) - i;
    }
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plainText); i < len; i++)
    {
        if (isalpha(plainText[i]))
        {
            plainText[i] = plainText[i] + diff[plainText[i] - (isupper(plainText[i]) ? 'A' : 'a')];
        }
        printf("%c", plainText[i]);
    }
    printf("\n");
    return 0;
}

bool checkKey(string k)
{
    int len = strlen(k);
    if (len != 26)
    {
        return false;
    }
    int checkRepeat[26] = { 0 };
    for (int a = 0; a < len; a++)
    {
        if (!isalpha(k[a]))
        {
            return false;
        }
        int checkLetter = toupper(k[a]) - 'A';
        if (checkRepeat[checkLetter] > 0)
        {
            return false;
        }
        checkRepeat[checkLetter]++;
    }
    return true;
}