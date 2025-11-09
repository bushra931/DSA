#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool splitarrayposs(vector<int>& nums, long long mid, int k) {
        long long sum = 0;
        int cnt = 1;  // start with one subarray

        for (int it : nums) {
            if (it > mid) return false; // single element too large
            if (sum + it > mid) {       // need new subarray
                cnt++;
                sum = 0;
            }
            sum += it;
            if (cnt > k) return false;  // early exit
        }
        return cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        // range of possible answers
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (splitarrayposs(nums, mid, k)) {
                ans = mid;
                high = mid - 1;  // try smaller largest sum
            } else {
                low = mid + 1;   // need larger capacity
            }
        }
        return (int)ans;
    }
};
