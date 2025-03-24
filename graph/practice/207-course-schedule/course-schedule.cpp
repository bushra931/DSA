class Solution {
public:
   bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];  // Adjacency list
    vector<int> indegree(numCourses, 0); // Indegree array
    
    // Build graph
    for (auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);  // Edge from pre[1] -> pre[0]
        indegree[pre[0]]++;  // Increase indegree of course `pre[0]`
    }
    
    // Push nodes with 0 indegree into queue
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    int count = 0;  // Counter for processed courses
    
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        count++;  // Mark course as taken
        
        for (int next : adj[course]) {
            indegree[next]--;  // Reduce indegree of next course
            if (indegree[next] == 0) q.push(next);
        }
    }
    
    return count == numCourses;  // If all courses are processed, return true
}

    
};