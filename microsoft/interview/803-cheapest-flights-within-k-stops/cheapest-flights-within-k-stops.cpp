#define P pair<int,int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<P>> adj(n);
        for(auto &flight : flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // minCost[node][stops] = min price to reach node with stops
        vector<vector<int>> minCost(n, vector<int>(k + 2, 1e9));
        priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P>>> pq;

        pq.push({0, {0, src}});
        minCost[src][0] = 0;

        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int price = it.first;
            int stop = it.second.first;
            int node = it.second.second;

            if (node == dst) return price;
            if (stop > k) continue;

            for (auto &neigh : adj[node]) {
                int next = neigh.first;
                int wt = neigh.second;
                int newCost = price + wt;
                if (newCost < minCost[next][stop + 1]) {
                    minCost[next][stop + 1] = newCost;
                    pq.push({newCost, {stop + 1, next}});
                }
            }
        }

        return -1;
    }
};
