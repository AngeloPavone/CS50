#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string user_input();
void encipher(string plaintext, char **argv);

int main(int argc, char **argv)
{
    // validate input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][j] == argv[1][i])
            {
                printf("Key must not contain any duplicates.\n");
                return 1;
            }
        }
    }
    for (int i = 0; i <= 26; i++)
    {
        argv[1][i] = tolower(argv[1][i]);
    }
    encipher(user_input(), argv);
    return 0;
}

string user_input()
{
    string plaintext = get_string("plaintext: "); // get user input
    return plaintext;
}

void encipher(string plaintext, char **argv)
{
    char lower_key[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char upper_key[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char ciphertext[50] = {};
    for (int i = 0, n = strlen(lower_key); i < n; i++)
    {
        for (int j = 0, p = strlen(plaintext); j < p; j++)
        {
            if (isalpha(plaintext[j]))
            {
                if (lower_key[i] == plaintext[j])
                {
                    ciphertext[j] = argv[1][i];
                }
                if (upper_key[i] == plaintext[j])
                {
                    ciphertext[j] = toupper(argv[1][i]);
                }
            }
            else if (!isalpha(plaintext[j]))
            {
                ciphertext[j] = plaintext[j];
            }
        }
    }
    printf("ciphertext: ");
    for (int i = 0, n = strlen(ciphertext); i < n; i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}