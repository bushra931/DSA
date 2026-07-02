#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> calculatePrefixMaxSum(vector<int>& nums, int len) {

        int n = nums.size() - 1;

        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        vector<int> maxPrefix(n + 1, 0);

        int best = 0;

        for (int i = len; i <= n; i++) {

            int windowSum = prefix[i] - prefix[i - len];

            best = max(best, windowSum);

            maxPrefix[i] = best;
        }

        return maxPrefix;
    }

    vector<int> calculateSuffixMaxSum(vector<int>& nums, int len) {

        int n = nums.size() - 1;

        vector<int> suffix(n + 2, 0);

        for (int i = n; i >= 1; i--)
            suffix[i] = suffix[i + 1] + nums[i];

        vector<int> maxSuffix(n + 2, 0);

        int best = 0;

        for (int i = n - len + 1; i >= 1; i--) {

            int windowSum = suffix[i] - suffix[i + len];

            best = max(best, windowSum);

            maxSuffix[i] = best;
        }

        return maxSuffix;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {

        // Convert to 1-based indexing
        vector<int> arr(nums.size() + 1);

        for (int i = 0; i < nums.size(); i++)
            arr[i + 1] = nums[i];

        int n = arr.size() - 1;

        vector<int> leftFirst = calculatePrefixMaxSum(arr, firstLen);
        vector<int> rightSecond = calculateSuffixMaxSum(arr, secondLen);

        vector<int> leftSecond = calculatePrefixMaxSum(arr, secondLen);
        vector<int> rightFirst = calculateSuffixMaxSum(arr, firstLen);

        int ans = 0;

        // firstLen before secondLen
        for (int i = firstLen; i <= n - secondLen; i++) {
            ans = max(ans, leftFirst[i] + rightSecond[i + 1]);
        }

        // secondLen before firstLen
        for (int i = secondLen; i <= n - firstLen; i++) {
            ans = max(ans, leftSecond[i] + rightFirst[i + 1]);
        }

        return ans;
    }
};