#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};

int main() {
    Solution solution;

    // Sample test case
    vector<int> nums = {3, 0, 1};
    int missing = solution.missingNumber(nums);

    cout << "Missing number: " << missing << endl;

    return 0;
}
