#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void mergeSort(vector<int> &arr, int l, int r)
    {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }

    void merge(vector<int> &arr, int l, int mid, int r)
    {
        vector<int> temp;
        int left = l, right = mid + 1;

        // Merge the two halves into temp[]
        while (left <= mid && right <= r)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // Copy remaining elements from left half, if any
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from right half, if any
        while (right <= r)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy sorted elements back into original array
        for (int i = l; i <= r; ++i)
        {
            arr[i] = temp[i - l];
        }
    }
};
