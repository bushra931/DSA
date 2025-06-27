class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt=0,cnt2=0;
        int ele,ele2;
        for(int i=0;i<nums.size();i++){
            if(cnt==0 && nums[i]!=ele2){
                cnt=1;
                ele=nums[i];
            }
            else  if(cnt2==0 && nums[i]!=ele){
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else if(nums[i]==ele2){
                cnt2++;
            }
            else cnt--,cnt2--;
        }
        vector<int> ls;
        int c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                c1++;
            }
            else if(nums[i]==ele2){
                c2++;
            }
        }
        int mini=(int)(nums.size()/3)+1;
        if(c1>=mini) ls.push_back(ele);
         if(c2>=mini) ls.push_back(ele2);
        sort(ls.begin(),ls.end());
        return ls;
        
    }
};