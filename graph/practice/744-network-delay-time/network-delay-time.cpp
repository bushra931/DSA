class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &time : times){
            adj[time[0]].push_back({time[1],time[2]});
        }
        vector<int> t(n+1,1e9);
        t[k]=0;
        q.push({0,k});
        while(!q.empty()){
            auto it=q.top();
            int time=it.first;
            int node =it.second;
            q.pop();
            for(auto neigh: adj[node]){
                int newt=neigh.second;
                int tnode=neigh.first;
                if(time+newt<t[tnode]){
                    t[tnode]=time+newt;
                    q.push({time+newt,tnode});
                }

            }
        }
        int mini=0;
        for(int i=1;i<=n;i++){
            if(t[i]==1e9) return -1;
            mini=max(mini,t[i]);

        }
        return mini;


        
    }
};