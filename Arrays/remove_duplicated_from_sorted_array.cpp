#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // Edge case: empty array
        int j = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main() {
    Solution solution;

    // Sample test case
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newLength = solution.removeDuplicates(nums);

    cout << "New length after removing duplicates: " << newLength << endl;
    cout << "Array after duplicates removed: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
