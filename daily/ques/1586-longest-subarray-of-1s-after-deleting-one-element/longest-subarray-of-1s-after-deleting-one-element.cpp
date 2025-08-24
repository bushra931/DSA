class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int n = nums.size();
        int l = 0, zeros = 0, best = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) zeros++;
            while (zeros > 1) {
                if (nums[l] == 0) zeros--;
                l++;
            }
            // window [l..r] has at most one zero
            best = max(best, r - l + 1);
        }
        int ans = best - 1;          // must delete exactly one element
        if (ans < 0) ans = 0;        // e.g., when n == 1
        return ans;
        }
};