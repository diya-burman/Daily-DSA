#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    struct Meeting
    {
        int start;
        int end;
        int pos;
    };

    static bool comp(Meeting a, Meeting b)
    { // based on end time
        if (a.end == b.end)
            return a.pos < b.pos;
        return a.end < b.end;
    }

    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        int n = start.size();
        vector<Meeting> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i + 1;
        }

        sort(arr.begin(), arr.end(), comp);

        int cnt = 1;
        int freeTime = arr[0].end;

        for (int i = 1; i < n; i++)
        {
            if (arr[i].start > freeTime)
            {
                cnt++;
                freeTime = arr[i].end;
            }
        }
        return cnt;
    }
};