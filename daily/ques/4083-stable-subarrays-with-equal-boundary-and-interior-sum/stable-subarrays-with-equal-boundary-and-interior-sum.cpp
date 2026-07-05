class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        // map-> {prefixsum,last ele}
       int n = capacity.size();
       if(n<=2) return 0;

        // {prefixSum before current index, value at current index} -> frequency
        map<pair<long long, int>, long long> mp;

        long long ans = 0;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += capacity[i];

            // Need prefixSum = currentPrefix - 2 * currentValue
            long long need = sum - 2LL * capacity[i];

            ans += mp[{need, capacity[i]}];

            // Store current index as a possible left boundary
            // prefix sum before current index = sum - capacity[i]
            mp[{sum , capacity[i]}]++;
            if (i > 0 &&capacity[i] == 0 && capacity[i - 1] == 0)
                ans--;
        }

        return ans;
        }
};