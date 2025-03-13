class Solution {
public:
    int binarysearch(int target_index,vector<int>& nums,int k,vector<long>& prefixsum){
        int l=0,r=target_index;
        int best_index=target_index;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            long len=target_index-mid+1;
            long windowsum=prefixsum[target_index]-prefixsum[mid]+nums[mid];
            long currsum=nums[target_index]*len;
            if(currsum-windowsum<=k){
                //possible operations
                best_index=mid;
                //window size badao btw mid and target
                r=mid-1;
            }
            else{
                //operation not possible dec window size 
                l=mid+1;
            }


        }
        return target_index-best_index+1;

    }


    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<long> prefixsum(n);
        prefixsum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        int ans=0;
        for(int targetindx=0;targetindx<n;targetindx++){
            ans=max(ans,binarysearch(targetindx,nums,k,prefixsum));
        }
        return ans;
    }
};