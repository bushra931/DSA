class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
       for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

//         You’re using a priority queue (min-heap), which always picks the lowest-cost path first.

// This is a problem because a more expensive path with fewer stops might later lead to a better solution, but your current logic discards these paths too early.

// Example of failure: If a direct but costly flight is taken first, it might prevent finding a cheaper multi-stop path. my mistake in using pq
        queue<pair<int, pair<int, int>>> pq;  
        vector<int> cost(n,1e9);
        cost[src]=0;
        // {cost,src,step k}
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int price=it.first;
            int node=it.second.first;
            int step=it.second.second;
            // yeh condition glt likhi thi dono directly k==dteps krwa rhi thi at most k thabhen
            // If we exceed k stops, stop processing further
            if (step > k) continue;
            for(auto neigh: adj[node]){
                int costn=neigh.second;
                int v=neigh.first;
                if(costn+price<cost[v]){
                    cost[v]=costn+price;
                    pq.push({costn+price,{v,step+1}});
                }

            }


        }
        //yha bhi glti kre last me retrn krwao
        if (cost[dst] == 1e9)
            return -1;
        return cost[dst];
       

        
    }
};