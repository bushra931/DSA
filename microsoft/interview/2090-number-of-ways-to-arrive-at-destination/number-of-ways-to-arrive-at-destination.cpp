const int MOD=1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
          vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // use long long not int as dist could be  huge in it 
       priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
       pq.push({0,0});
       vector<long long> dist(n,LLONG_MAX);
       vector<int> ways(n,0);
       dist[0]=0;
       ways[0]=1;
       while(!pq.empty()){
              auto it=pq.top();
              pq.pop();
              long long dis=it.first;
              int node=it.second;
              for(auto &[newn,newd]:adj[node]){
                if(dis+newd<dist[newn]){
                    pq.push({dis+newd,newn});
                    dist[newn]=dis+newd;
                    ways[newn]=ways[node];
                }
                else if(dis+newd==dist[newn]){
                    ways[newn]=(ways[node]+ways[newn])%MOD;
                }
              }
       }
       return ways[n-1]%MOD;

        
    }
};