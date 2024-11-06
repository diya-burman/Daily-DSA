#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        // Check if the array can be rotated to be sorted
        for (int i = 0; i < n; i++) {
            // Count the number of "descending" pairs (where an element is greater than the next)
            if (nums[i] > nums[(i + 1) % n]) {
                cnt++;
            }
        }
        
        // If there's at most one "descending" point, the array can be a rotated sorted array
        return cnt <= 1;
    }
};

int main() {
    Solution solution;

    // Sample test case
    vector<int> nums = {2,1,3,4}; // Rotated sorted array
    bool result = solution.check(nums);

    cout << "Can the array be rotated to be sorted? " << (result ? "true" : "false") << endl;

    return 0;
}
