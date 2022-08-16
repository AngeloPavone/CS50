#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string user_input();
void rotate(int int_argv, string plaintext);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int int_argv = atoi(argv[1]);
    rotate(int_argv, user_input());

    return 0;
}

void rotate(int int_argv, string plaintext)
{
    int key = int_argv;

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            int p = plaintext[i] - 65;
            plaintext[i] = ((p + key) % 26) + 65;
        }
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            int p = plaintext[i] - 97;
            plaintext[i] = ((p + key) % 26) + 97;
        }
    }
    printf("ciphertext: %s\n", plaintext);
}

string user_input()
{
    string plaintext = get_string("Plaintext:  ");
    return plaintext;
}
