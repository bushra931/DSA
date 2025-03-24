class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdegree(n, 0);
        vector<vector<int>> reverseGraph(n); 
        queue<int> q;
        vector<int> result;

        // Step 1: Build the reverse graph and calculate outdegre
        //imp look rev of graph i missed it so tle arha tha kyuki bahut loop lgne pade
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if (outdegree[i] == 0) {
                q.push(i); // Terminal nodes
            }
        }

        // Step 2: Process queue using BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int prev : reverseGraph[node]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        // Step 3: Sort result as required
        sort(result.begin(), result.end());
        return result;
    }
};