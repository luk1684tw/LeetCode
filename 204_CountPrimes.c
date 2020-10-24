#include <stdio.h>

int countPrimes(int n)
{
    bool record[5000000] = {0};
    if (n < 3) return 0;
    
    int ans = 1;
    for (int i = 3; i < n; i += 2)
    {
        if (!record[i])
        {
            ans++;
            for (int j = 2 * i; j < n; j += i)
            {
                record[j] = true;
            }
        }
    }

    return ans;
}

int main(void)
{

}