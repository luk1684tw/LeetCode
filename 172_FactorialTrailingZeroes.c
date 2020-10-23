#include <stdio.h>

int decompose(int n, int base)
{
    int ans = 0;
    while(n % base == 0)
    {
        ans++;
        n /= base;
    }
    return ans;
}

int trailingZeroes(int n)
{
    int n_2 = 0, n_5 = 0;
    for (int i = 1; i <= n; i++)
    {
        // n_2 += decompose(i, 2);
        n_5 += decompose(i, 5);
    }
    return  n_5;
}

int main(void) 
{
    int n;
    n = 0;
    printf("%d\n", trailingZeroes(n));

    return 0;
}