#include <stdio.h>
typedef unsigned long uint32_t;

uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for (int i = 0; i < 31; i++)
    {
        ans += (n % 2);
        ans = ans << 1;
        n = n >> 1;
    }
    ans += n;
    return ans;
}

int main(void)
{
    uint32_t n, input;
    scanf("%u", &input);
    n = reverseBits(input);
    
    printf("%u", n);
    return 0;
}