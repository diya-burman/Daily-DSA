#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int func(vector<int> &arr, int pages)
    {
        int student = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (pagesStudent + arr[i] <= pages)
            {
                pagesStudent += arr[i];
            }
            else
            {
                student++;
                pagesStudent = arr[i];
            }
        }
        return student;
    }

    int findPages(vector<int> &arr, int k)
    {
        if (arr.size() < k)
            return -1;
        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            int cntStudents = func(arr, mid);
            if (cntStudents > k)
            {
                s = mid + 1;
            }
            else
            {
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
};