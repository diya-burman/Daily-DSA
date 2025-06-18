#include <iostream>
#include <cmath>
using namespace std;

// return 1 if == m
// return 0 if < m
// return 2 if > m

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans = ans * mid; // mid^n
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int nthRoot(int n, int m)
{
    int s = 1;
    int e = m;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of m: ";
    cin >> m;

    int result = nthRoot(n, m);
    if (result != -1)
    {
        cout << "The " << n << "th root of " << m << " is: " << result << endl;
    }
    else
    {
        cout << "No integer root found." << endl;
    }
    return 0;
}
