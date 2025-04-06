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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        //for dimensions
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int> stonenodes;
        for(auto it: stones){
            int noderow=it[0];
            int nodecol=it[1]+maxrow+1;
            ds.unionbysize(noderow,nodecol);
            stonenodes[noderow]=1;
            stonenodes[nodecol]=1;

        }
        int cnt=0;
        for(auto it:stonenodes){
            if (ds.findupar(it.first) == it.first) {
                cnt++;
            }
        }
         return n - cnt;
    }
};