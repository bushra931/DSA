class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        // //edge if prequ empty
        // if(prerequisites.empty()) {
        //     for(int i=0;i<numCourses;i++){
        //         ans.push_back(i);
        //     }
        //     return ans;
        // }
        // adjacanecy list u->v
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            adj[u].push_back(v);
        }
        //topo sort kahns
        vector<int> indegree(numCourses,0);
        for(int i=0;i<adj.size();i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int j=0;j<numCourses;j++){
            if(indegree[j]==0) q.push(j);
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }

        }
        //if impossible edge case(i missed)
        if(ans.size()!=numCourses) return {};
        return ans;

    }
};