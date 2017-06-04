#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_sub_string_len(char * s) {
    int s_len = strlen(s);
    char *seen = (char *) malloc(s_len);
    int i = 0;
    printf(" %s: len: %d\n",__FUNCTION__,s_len);
    for (i = 0; i < s_len; i++) {
        printf(" %s: %d\n",__FUNCTION__,__LINE__);
        if (i == 0) {
            seen[i] = s[i];
            continue;
        }
        if (s[i] != seen[i]) {
            seen[i] = s[i];
        } else {
            seen[i] = '\0';
            break;
        } 
    } 

    return strlen(seen);
}

int longest_substring(char *s) {
    int max_=0, max_so_far=0;
    int s_len = strlen(s);
    printf(" %s: len: %d\n",__FUNCTION__,s_len);
    for (int i=0; i < s_len; i++) {
        max_ = get_sub_string_len(s);
        if (max_ > max_so_far) {
            max_so_far = max_;
        }
    }

    return max_so_far;
}

int main() {
    char *s = "abcabcabcbb";

    printf(" input string is : %s\n", s);
    printf(" longest substring len is %d\n", longest_substring(s));

    return 0;
}
