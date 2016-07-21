/*
 * Simple string reversal
 *
 */
#include <string.h>
#include <stdio.h>

char *reverse_string(char *inp)
{
    char *begin, *end ;
    char tmp;
    int len = 0; 
    
    len = strlen(inp);
    begin = inp;
    end = inp + (len -1);

    while (begin <= end) {

        tmp = *end;
        *end = *begin;
        *begin = tmp;
        begin = begin+ 1;
        end = end -1;
    }

    return inp;
}

int main()
{
    char *inp = "sripathy";
    char *out;

    printf("Input string: %s\n", inp);
    printf(" Output string: %s\n", reverse_string(inp));

}
