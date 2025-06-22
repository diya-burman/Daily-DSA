#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k) {
        if (n > m)
            return kthElement(arr2, arr1, m, n ,k); // ensures n1 contains smaller number of elements
        int s = max(0,k-m);
        int e = min(k,n);
        int left = k;
        int size = n + m;
        while (s <= e) {
            int mid1 = (s + e)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n)
                r1 = arr1[mid1];
            if (mid2 < m)
                r2 = arr2[mid2];
            if (mid1 - 1 >= 0)
                l1 = arr1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = arr2[mid2 - 1];
            if (l1 <= r2 && l2 <= r1) {
                    return max(l1, l2); 
            } else if (l1 > r2) {
                e = mid1 - 1;
            } else {
                s = mid1 + 1;
            }
        }
        return 0;
}