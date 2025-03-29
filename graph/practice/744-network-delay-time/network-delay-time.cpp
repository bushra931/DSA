class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        // Ordered set {time, node}
        set<pair<int, int>> s;
        
        vector<int> t(n + 1, INT_MAX);
        t[k] = 0;
        s.insert({0, k});

        while (!s.empty()) {
            auto [time, node] = *s.begin();
            s.erase(s.begin());

            // Process all neighbors
            for (auto &[tnode, newt] : adj[node]) {
                if (time + newt < t[tnode]) {
                    s.erase({t[tnode], tnode});  // Remove old value if present
                    t[tnode] = time + newt;
                    s.insert({t[tnode], tnode});
                }
            }
        }

        // Find the maximum time to reach any node
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (t[i] == INT_MAX) return -1;  // Some nodes are unreachable
            maxTime = max(maxTime, t[i]);
        }

        return maxTime;


        
    }
};