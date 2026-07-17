class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> dq;
        int n=nums.size();
        vector<int> prefixsum(n,0);
        int res=INT_MAX;
        int j=0;
        while(j<n){
            if(j==0) prefixsum[j]= nums[j];
            else prefixsum[j]=prefixsum[j-1]+nums[j];
            if(prefixsum[j]>=k) res=min(res,j+1);
           
            // dip agya case --> so to store inc only 
            while(!dq.empty() && prefixsum[j]<=prefixsum[dq.back()]){
                dq.pop_back();
            }
             //shrink window or not 
            while(!dq.empty() && prefixsum[j]-prefixsum[dq.front()]>=k){
                res=min(res,j-dq.front());
                dq.pop_front();
            }
            dq.push_back(j);
            j++;
        }
       return res == INT_MAX ? -1 : res;

        
    }
};