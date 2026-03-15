class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;
        long long currentSum = 0;

        int bestLength = INT_MAX;

        for(int right = 0; right < nums.size(); right++) {

            currentSum += nums[right];

            while(currentSum >= target) {

                bestLength = min(bestLength, right - left + 1);

                currentSum -= nums[left];
                left++;
            }
        }

        if(bestLength == INT_MAX)
            return 0;

        return bestLength;
    }
};