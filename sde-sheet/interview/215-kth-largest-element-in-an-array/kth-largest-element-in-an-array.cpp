class Solution {
    int K; // Integer K
    priority_queue <int, vector<int>, greater<int>> pq; // Min-heap 
public:
    int findKthLargest(vector<int>& nums, int k) {
        K = k; // Initialize the integer
        
        // Traverse all the elements in the array
        for(int i = 0; i < nums.size(); i++) {
            // If the size of min-heap is less than k
            if(pq.size() < K) pq.push(nums[i]); // Add the current element
            
            // Else if the top element is smaller than the current element
            else if(nums[i] > pq.top()) {
                pq.pop(); // Pop the top element
                pq.push(nums[i]); // Add the current element
            }
        }
        return pq.top();     
    }
};