#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int x)
{
    int s = 0;
    int e = n - 1;
    int ans = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int even[10] = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
    cout << "Lower bound is " << lowerBound(even, 10, 1) << endl;

    return 0;
}