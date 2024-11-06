#include <iostream>
#include <cmath>  // For math functions (not strictly needed for your solution)
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long long N = n;  // Use long long to handle negative INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double res = 1;
        while (N > 0) {
            if (N % 2 == 1) {
                res *= x;
            }
            x *= x;
            N /= 2;
        }
        return res;
    }
};

int main() {
    Solution solution;

    double x = 2.0;
    int n = 10;

    double result = solution.myPow(x, n);
    cout << "Result: " << result << endl;

    return 0;
}
