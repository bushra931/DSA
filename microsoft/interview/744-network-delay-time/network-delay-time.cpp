class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : times) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int wt = edge[2];
            adj[u].emplace_back(v, wt);
        }

        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;

        set<pair<int, int>> s;
        s.insert({0, k - 1});

        while (!s.empty()) {
            auto [time, node] = *s.begin();
            s.erase(s.begin());

            for (auto& [nei, wt] : adj[node]) {
                if (time + wt < dist[nei]) {
                    s.erase({dist[nei], nei});
                    dist[nei] = time + wt;
                    s.insert({dist[nei], nei});
                }
            }
        }

        int maxTime = *max_element(dist.begin(), dist.end());
        return (maxTime == INT_MAX ? -1 : maxTime);
    }
};
