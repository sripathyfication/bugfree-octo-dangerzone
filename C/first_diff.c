/*
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char alphabet[26] =
{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

bool validate(char *inp) 
{
    bool found = false;
    for (int i = 0; i < strlen(inp); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (inp[i] == alphabet[j])
                found = true;
        }
    }
    return found;
}

int different_index(char *inp)
{
    int max = 0;
    char *tmp, tmp2;
    tmp = &tmp2; 
    if (validate(inp)) 
    {
        printf("String is valid and of len: %lu\n", strlen(inp));
        for (int i= 0;i < strlen(inp); i++)
        {
            *tmp = toupper(*inp);
            printf("atoi(%c) : %d  max: %d i: %d %c \n", *tmp, atoi(tmp),max ,i ,*tmp);
#if 0
            if (atoi(tmp) < max) 
                return i;
            else 
                max = atoi(tmp);
#endif        
            inp++;
        }
    }

    return -1;
}

int main()
{
    char *s = "ABCDB";

    printf(" different index is at : %d\n", different_index(s));

    return 0;
}
