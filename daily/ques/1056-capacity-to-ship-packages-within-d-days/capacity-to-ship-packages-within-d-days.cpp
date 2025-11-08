class Solution {
public:
    bool canbeship(vector<int>& weights,int mid, int days){
        int requiredDays = 1;   // need at least one day
        int currentLoad = 0;

        for (int w : weights) {
            if (w > mid) return false; // can't fit single package
            if (currentLoad + w > mid) {
                requiredDays++;       // start new day
                currentLoad = 0;
            }
            currentLoad += w;
        }
        return requiredDays <= days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1;
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canbeship(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};