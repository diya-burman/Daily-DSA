#include <iostream>
#include <vector>
#include <algorithm> // for max

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt); // To account for cases where the longest sequence ends at the last element
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Sample test case
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int result = solution.findMaxConsecutiveOnes(nums);
    
    cout << "Max consecutive 1s: " << result << endl;
    
    return 0;
}
