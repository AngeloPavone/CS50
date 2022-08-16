#include <cs50.h>
#include <stdio.h>

int prompt_user_for_size();
int medium_pyramid(int size);

int main(void)
{
    int size = prompt_user_for_size();
    medium_pyramid(size);
}

int prompt_user_for_size()
{
    int size = 0;
    do
    {
        size = get_int("Please input the size of the stairs: ");
    } while (size > 8 || size < 1);
    return size;
}

int medium_pyramid(int size)
{
    for (int i = 1; i < size + 1; i++)1
    {
        for (int k = size; k > i; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}