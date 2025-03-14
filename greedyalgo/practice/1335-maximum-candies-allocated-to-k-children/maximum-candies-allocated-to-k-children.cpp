class Solution {
public:
   bool candies_allocated(vector<int>& candies, long long k,int mid){
        int n=candies.size();
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=(candies[i]/mid);
        }
        if(sum>=k) return true;
        return false;
         
   }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxi=INT_MIN;
        int n=candies.size();
        for(int i=0;i<n;i++){
            maxi=max(candies[i],maxi);
        }
        int l=0,r=maxi;
        while(l<r){
            int mid=(l + r +1)/2; //missed +1 here 
            if(candies_allocated(candies,k,mid)){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        return l;

        
    }
};