class Solution {
public:
    vector<vector<int>>adj;
    vector<int>disFromBob;
    int bobNode;
    int dfs(int u,int par,int depth,vector<int>&amount){
        int ret = 0;
        if(u==bobNode) disFromBob[u] = 0;
        else disFromBob[u] = amount.size();
        int maxChild = -INT_MAX;
        for(int v:adj[u]){
            if(v==par)continue;
            maxChild = max(maxChild,dfs(v,u,depth+1,amount));
            disFromBob[u] = min(disFromBob[u],disFromBob[v]+1);
        }
        if(disFromBob[u]>depth)ret+=amount[u];
        else if(disFromBob[u]==depth)ret+=amount[u]/2;
        if(maxChild==-INT_MAX) return ret;
        else return ret+maxChild;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        bobNode = bob;
        adj.resize(n,vector<int>());
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        disFromBob.resize(n);
        return dfs(0,0,0,amount);
    }
    
};