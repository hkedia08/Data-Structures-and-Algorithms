// https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

double esp = 1e-7;
double findNthRootOfM(int n, long long m)
{
    // Write your code here.
    double low = 1.0;
    double high = m * 1.0;
    double mid;
    while ((high - low) > esp)
    {
        mid = (low + high) / 2;
        if (pow(mid, n) < double(m))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}
