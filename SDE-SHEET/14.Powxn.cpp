// https://leetcode.com/problems/powx-n/

// this is very standard algorthim which is known as binary exponentiation

class Solution
{
public:
    double power(double x, long long int n)
    {
        double ans = 1.0;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans = ans * x;
                n = n - 1;
            }
            else
            {
                x = x * x;
                n = n / 2;
            }
        }
        return ans;
    }
    double myPow(double x, int n)
    {
        long long nm = n;
        if (nm < 0)
            nm = abs(n);
        double ans = power(x, nm);
        if (n < 0)
        {
            ans = double(1.0) / double(ans);
        }
        return ans;
    }
};

// recursive approach
class Solution
{
public:
    double power(double x, long long int n)
    {
        if (n == 0)
            return 1.0;
        if (n % 2 == 0)
        {
            return power(x * x, n / 2);
        }
        else
        {
            return x * power(x, n - 1);
        }
    }
    double myPow(double x, int n)
    {
        long long nm = n;
        if (nm < 0)
            nm = abs(n);
        double ans = power(x, nm);
        if (n < 0)
        {
            ans = double(1.0) / double(ans);
        }
        return ans;
    }
};