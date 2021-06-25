class Solution {
public:
    vector<vector<int>> adj;
    vector<int> child;
    vector<int> ans;
    vector<int> subtree;
    int v;
    void BFS(int root)
    {
        vector<int> dis(v,100000000);
        dis[root]=0;
        queue<int> q;
        q.push(root);
        int sum=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto x:adj[u])
            {
                if(dis[x]==100000000)
                {
                    dis[x]=dis[u]+1;
                    sum+=dis[x];
                    q.push(x);
                    
                    
                }
                    
            }
        }
        ans[0]=sum;
    }
    int dfs(int curr,int par)
    {
        for(auto x:adj[curr])
        {
            if(x==par)
                continue;
            child[curr]+=dfs(x,curr);
        }
        return child[curr];
        
    }
    void dfs1(int curr,int par)
    {
        for(auto x:adj[curr])
        {
            if(x==par)
                  continue;
            ans[x]=ans[curr]-child[x]+v-child[x];
            dfs1(x,curr);
        }
    }
    int dfsnew(int curr,int par)
    {
        for(auto x:adj[curr])
        {
            if(x==par)
                continue;
            subtree[curr]+=(dfsnew(x,curr))+child[x];
        }
        return subtree[curr];
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        v=n;
        adj.resize(v);
        child.resize(v,1);
        ans.resize(v);
        subtree.resize(v,0);
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // BFS(0);
        dfs(0,-1);
        dfsnew(0,-1);
        ans[0]=subtree[0];
        dfs1(0,-1);
        return ans;
        
            
    }
};
