#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findKRotation(int nums[], int n)
    {
        int s = 0;
        int e = n - 1;
        int a = INT_MAX;
        int index = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[s] <= nums[mid])
            {
                if (nums[s] < a)
                {
                    a = nums[s];
                    index = s;
                }
                s = mid + 1;
            }
            else
            {
                if (nums[mid] < a)
                {
                    a = nums[mid];
                    index = mid;
                }
                e = mid - 1;
            }
        }
        return index;
    }
};