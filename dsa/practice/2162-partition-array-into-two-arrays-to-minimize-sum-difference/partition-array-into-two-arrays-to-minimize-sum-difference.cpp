
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;
        int tsum = accumulate(nums.begin(), nums.end(), 0);  // Correct: total sum

        vector<int> leftpart(nums.begin(), nums.begin() + n);
        vector<int> rightpart(nums.begin() + n, nums.end());

        vector<vector<int>> left(n + 1), right(n + 1);

        // Generate subset sums for left half
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0, size = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    size++;
                    sum += leftpart[i];
                }
            }
            left[size].push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0, size = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    size++;
                    sum += rightpart[i];
                }
            }
            right[size].push_back(sum);
        }

        // Sort right side for binary search
        for (int i = 0; i <= n; ++i) {
            sort(right[i].begin(), right[i].end());
        }

        int ans = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            int j = n - i;

            for (int a : left[i]) {
                int target = tsum / 2 - a;
                auto& vec = right[j];

                if (vec.empty()) continue; // ✅ prevent any access if empty

                auto it = lower_bound(vec.begin(), vec.end(), target);

                // ✅ Case 1: found value ≥ target
                if (it != vec.end()) {
                    int s1 = a + *it;
                    int s2 = tsum - s1;
                    ans = min(ans, abs(s1 - s2));
                }

                // ✅ Case 2: check value just before it safely
                if (it != vec.begin()) {
                    --it;  // this is now safe
                    int s1 = a + *it;
                    int s2 = tsum - s1;
                    ans = min(ans, abs(s1 - s2));
                }
            }
        }

        return ans;
    }
};
