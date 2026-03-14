class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto& edge:prerequisites){
            int course=edge[0];
            int pre=edge[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int counter=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            counter++;
            for(auto adjnode:adj[node]){
                indegree[adjnode]--;
                if(indegree[adjnode]==0) q.push(adjnode);
            }
        }
    return counter==numCourses;
    }
};