#include <stdio.h>

typedef unsigned long uint32_t;

int hammingWeight(uint32_t n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += (n % 2);
        n >>= 1;
    }
    return ans;
}

int main(void)
{

}