#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX_ALPHABETS 26
// Assume all alphabets are case insensitive. Go through every char in
// input string and search test_arr. If match, then present.

typedef struct pangram_checker_ {
    char alpha;
    bool hit_;
} pc_t;

pc_t alphabets[MAX_ALPHABETS] = {
    {'a', false}, {'b', false}, {'c', false}, {'d', false},
    {'e', false}, {'f', false}, {'g', false}, {'h', false},    
    {'i', false}, {'j', false}, {'k', false}, {'l', false},
    {'m', false}, {'n', false}, {'o', false}, {'p', false},    
    {'q', false}, {'r', false}, {'s', false}, {'t', false},
    {'u', false}, {'v', false}, {'w', false}, {'x', false},    
    {'y', false}, {'z', false}, 
};

bool set_alphabets_hit_(char *test)
{
    bool is_pangram = false;
    int i = 0, n_len = 0;
    
    // get string length
    n_len = strlen(test);

    // loop over the length and set hit_
    while (i < n_len) {
        printf("%c ", test[i]);
        for (int j = 0; j < MAX_ALPHABETS; j++) {
            if (alphabets[j].alpha == test[i]) alphabets[j].hit_ = true; continue;
        }
        i++;
    }
    return false;
}

bool check_alphabets_hit_() 
{
    int i = 0;
    for(i=0; i < MAX_ALPHABETS; i++)
        if (alphabets[i].hit_ == false) return false;
    return true;
}

void reset_alphabets_hit_() 
{
    int i = 0;
    for(i=0; i < MAX_ALPHABETS; i++)
        alphabets[i].hit_ = false;
    return ;
}

int main(int argc, char **argv) 
{
    char *s;
    int num_tests = 0, i = 0;
    bool is_pangram = false;

    // Make sure we have the right number of inputs
    if (argc < 3) 
    { 
        printf("Enter test cases as follows: ./pan <num-test-cases> 'test-1' 'test-2' .... \n ");
        return -1;
    }

    // extract the input
    num_tests = atoi(argv[1]); s = argv[2];
    printf("Number of tests: %d \n", num_tests);

    // Loop around test cases and check for pangram
    while (i < num_tests) {
        set_alphabets_hit_(argv[2+i]);
        is_pangram = check_alphabets_hit_();
        printf("\nString is %s pangram\n", (is_pangram ? "a": "not") );
        i++;
        is_pangram = false;
        reset_alphabets_hit_();
    }
    return 0;
}
