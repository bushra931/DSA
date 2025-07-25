class DisjointSet{
    vector<int> parent,size;
public: 
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++){
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
        if(ulp_u==ulp_v) return;
        else if(size[ulp_v]<size[ulp_u]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0,maxcol=0;
        for(auto stone:stones){
            maxrow=max(maxrow,stone[0]);
            maxcol=max(maxcol,stone[1]);
        }
        int offset=maxrow+1;
        DisjointSet ds(maxrow+maxcol+1);
        unordered_set<int> uniqueNodes;
        for(auto &stone:stones){
            int nrow=stone[0];
            int ncol=stone[1]+offset;
            ds.unionbysize(nrow,ncol);
            uniqueNodes.insert(nrow);
            uniqueNodes.insert(ncol);

        }
        int components = 0;
        for (int node : uniqueNodes) {
            if (ds.findupar(node) == node)
                components++;
        }

        return stones.size() - components;


        
    }
};