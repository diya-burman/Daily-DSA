#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p = 1, s = 1;
        int res = INT_MIN;
        
        for(int i = 0; i < n; i++) {
            if(p == 0) p = 1;
            if(s == 0) s = 1;
            p = p * nums[i];
            s = s * nums[n - i - 1];
            res = max(res, max(p, s));
        }
        
        return res;
    }
};

int main() {
    vector<int> nums = {-2,0,-1};
    Solution solution;
    int result = solution.maxProduct(nums);
    cout << "Maximum product of subarray: " << result << endl;
    return 0;
}
