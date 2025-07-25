class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++) parent[i]=i;
    }
    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        int mincable=0;
        int mstcable=n-1;
        DisjointSet ds(n);
        for(auto &it: connections){
            int node1=it[0];
            int node2=it[1];
            if(ds.findUpar(node1)!=ds.findUpar(node2)){
                mincable++;
                ds.unionbysize(node1,node2);
            }
        }
        return mstcable-mincable;
        
    }
};