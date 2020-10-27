#include <stdio.h>

bool isHappy(int n)
{
    while (n > 0)
    {
        int tmp = n;
        n = 0;
        while(tmp > 0)
        {
            n += (tmp % 10) * (tmp % 10);
            tmp /= 10;
        }
        if (n == 4)
        {
            return false;
        }
        else if (n == 1)
        {
            return true;
        }
    }
    return false;
}

int main(void)
{

}