class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for (const auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &adjnode:adj[node]){
                  indegree[adjnode]--;
                  if(indegree[adjnode]==0) q.push(adjnode);
            }

        }
        if(ans.size()<numCourses) return {};
        return ans;
        
        
    }
};