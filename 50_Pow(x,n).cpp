

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1)
        {
            return (double)1;
        }
        long pow = abs(n);
        double ans = 1;
        while (pow)
        {
            if (pow & 1)
            {
                ans *= x;
            }

            x *= x;
            pow >> 1;
        }

        return ((n > 0) ? ans : (double)(1 / ans));
    }
};