/*
 * Naive, quadratic time pattern matching solution.
 *
 * Given a larger string (l), find and return the start
 * index of smaller string (s)
 *
 */

#include <stdio.h>
#include <string.h>

int pattern_match (char *l, char *s) 
{
    int i, j;

    int m = strlen(s);
    int n = strlen(l);

    for (i = 0; i <= (n); i++)
    {
        j = 0;
        while (j < m && (s[j] == l[i+j])) 
            j++;

        if (j == m) return i;
    }

    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2) return -1;

    char *l = argv[1];
    char *s = argv[2];

    printf(" Find %s in %s \n", s, l);

    int x = pattern_match(l, s);

    if (x)
        printf(" Found %s in %s at %d\n",s,l,x);
    else
        printf(" %s doesn't exist in %s\n", s , l);

    return 0;
}
