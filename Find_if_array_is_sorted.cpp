#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        // Bubble sort
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                // In every pass, the max element bubbles up to the rightmost index
                if (nums[j] <= nums[j + 1]) {
                    continue;
                } else { // For sure nums[j] > nums[j+1]
                    // Swap is required if both have the same number of set bits
                    if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])) {
                        swap(nums[j], nums[j + 1]);
                    } else {
                        // Not able to swap, hence can't sort it
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {1,2,3,4,5}; // Example input

    bool result = solution.canSortArray(nums);

    if (result) {
        cout << "The array can be sorted." << endl;
    } else {
        cout << "The array cannot be sorted." << endl;
    }

    return 0;
}
