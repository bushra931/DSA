class KthLargest {
private:
    int K; // Integer K
    priority_queue <int, vector<int>, greater<int>> pq; // Min-heap 
public:
    KthLargest(int k, vector<int>& nums) {
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
        
    }
    
    int add(int val) {
        if(pq.size() < K) {
            pq.push(val);

            return pq.top();
        }

        // If the smallest element is less than the element to be added
        if(val > pq.top()) {
            pq.pop(); // Remove the top element
            pq.push(val); // Add the current element
        }
        
        return pq.top(); // Return the Kth largest element
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */