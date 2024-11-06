#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        
        // Count frequency of each number in the array
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        
        // Find the number that appears only once
        for (const auto& entry : freq) {
            if (entry.second == 1) {
                return entry.first;
            }
        }
        
        return -1; // In case there's no such number, return -1
    }
};

int main() {
    Solution solution;

    // Sample test case
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = solution.singleNumber(nums);

    // Output the result
    cout << "The number that appears only once is: " << result << endl;

    return 0;
}
