class RandomizedSet {
    unordered_map<int,int> pos;
    vector<int> nums;
public:
    RandomizedSet() {
        pos.clear();
        nums.clear(); 
    }
    
    bool insert(int val) {
        if(pos.count(val)) return false;
        nums.push_back(val);
        pos[val]=nums.size()-1;
        return true;    
    }
    
    bool remove(int val) {
        if(!pos.count(val)) return false;
        //remo
        int idx=pos[val];
        int last=nums.size()-1;
        //excehnahge
        swap(nums[idx],nums[last]);
        pos[nums[idx]]=idx;
        nums.pop_back();
        pos.erase(val);  
        return true; 
    }
    
    int getRandom() {
        int rindx=rand()%nums.size();
        return nums[rindx];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */