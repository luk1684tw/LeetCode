#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int test = 0x12345678;
    char *a = (char*) &test;
    printf("%x", *a);

    return 0;
}