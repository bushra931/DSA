#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(vector<double> nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < 1e-6;
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<double> nxt;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) nxt.push_back(nums[k]);
                }
                double a = nums[i], b = nums[j];
                vector<double> candidates = {a + b, a - b, b - a, a * b};
                if (fabs(b) > 1e-6) candidates.push_back(a / b);
                if (fabs(a) > 1e-6) candidates.push_back(b / a);
                
                for (double val : candidates) {
                    nxt.push_back(val);
                    if (solve(nxt)) return true;
                    nxt.pop_back();
                }
            }
        }
        return false;
    }
};
