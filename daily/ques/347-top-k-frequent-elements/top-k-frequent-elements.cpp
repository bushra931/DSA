class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int> frequency;

        for(int value : nums) {
            frequency[value]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;

        for(auto &entry : frequency) {

            minHeap.push({entry.second, entry.first});

            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;

        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;

    }
};