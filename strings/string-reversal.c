#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) 
{
    char *s_r;
    char *begin, *end, tmp1, *tmp;
    int s_len =0, s_tmp =0;

    // ensure right params are in.
    if (argc < 2) return -1;

    // get input str, and strlen
    s_r = argv[1];
    s_len = strlen(s_r);
    printf("The string to be reversed is: %s \n", s_r);

    // doing the needful
    tmp = &tmp1;
    begin = s_r;
    end = begin + (s_len -1);
    while (begin <= end) {
        *tmp = *begin;
        *begin = *end;
        *end = *tmp;
        begin = begin +1;
        end = end - 1;
        s_tmp++;
    }

    printf("Reversed string is: %s \n", s_r);
    return 0;
}
