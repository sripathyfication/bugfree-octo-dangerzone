#include <stdio.h>
struct something {
    char c;
    int i; 
    double d;
    void *p;
    int a[0];
};

int main() {

    printf(" Sizeof something: %lu\n", sizeof(struct something));
    return 0;
}
