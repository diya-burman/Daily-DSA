#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canWePlace(vector<int> &stalls, int dist, int cows)
    {
        int cntCows = 1;
        int last = stalls[0];
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= dist)
            {
                cntCows++;
                last = stalls[i];
            }
        }
        if (cntCows >= cows)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int s = 1;
        int e = stalls[n - 1] - stalls[0]; //values in search space not indexes
        int ans = -1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (canWePlace(stalls, mid, k) == true)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};