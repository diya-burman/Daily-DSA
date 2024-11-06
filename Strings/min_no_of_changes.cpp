#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int changes = 0;
        int i = 0;

        while (i < n) {
            char curr_ch = s[i];
            int cnt = 0;

            // Count the length of the current contiguous substring
            while (i < n && s[i] == curr_ch) {
                cnt++;
                i++;
            }

            // If the length of this contiguous substring is odd, one change is needed
            if (cnt % 2 != 0) {
                changes++;
            }
        }

        return changes;
    }
};

int main() {
    Solution solution;

    // Sample test case
    string s = "1001";
    int result = solution.minChanges(s);
    cout << "Minimum changes to make even-length substrings: " << result << endl;

    return 0;
}
