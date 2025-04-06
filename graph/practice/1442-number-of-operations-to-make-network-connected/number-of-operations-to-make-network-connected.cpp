    
 class DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findupar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findupar(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulp_u=findupar(u);
        int ulp_v=findupar(v);
        if(ulp_u==ulp_v) return; // of same parent so together
        if(size[ulp_u]<size[ulp_v]){
            //attach smaller to larger
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
        int msteg=n-1;
        if(connections.size()<msteg) return -1;
        DisjointSet ds(n);
        int cableused=0;
        for(auto edge: connections){
            int u=edge[0];
            int v=edge[1];
            //mst made
            if(ds.findupar(u)!=ds.findupar(v)){
                 cableused++;
                 ds.unionbysize(u,v);
            }

        }
        return msteg-cableused;

        
    }
};