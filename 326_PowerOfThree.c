bool isPowerOfThree(int n)
{
    if (n <= 0) return false;
    else if (n == 1) return true;
    else
    {
        while (n > 1)
        {
            if (n % 3)
                return false;
            n /= 3;
        }   
    }
    return true;
}