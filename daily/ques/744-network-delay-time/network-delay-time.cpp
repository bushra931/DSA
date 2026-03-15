class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto& edge:times){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n+1,1e9);
        //{wt,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto [wt,node]=pq.top();
            pq.pop();
            for(auto& nbr:adj[node]){
                int adjnode=nbr.first;
                int distn=nbr.second;
                if(wt+distn<dist[adjnode]){
                    dist[adjnode]=wt+distn;
                    pq.push({wt+distn,adjnode});
                }

            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};