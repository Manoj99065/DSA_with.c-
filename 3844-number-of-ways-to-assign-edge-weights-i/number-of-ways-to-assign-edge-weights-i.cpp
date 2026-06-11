class Solution {
public:
    int M=1e9+7;
    typedef long long ll;
    ll power(ll base, ll exponent)
    {
        if(exponent==0)
        {
            return 1;
        }
        ll half=power(base,exponent/2);
        ll result=(half*half)%M;

        if(exponent%2==1)
        {
            result=(result*(base)%M);
        }
        return result;
    }
    int getmaxdepth(unordered_map<int,vector<int>>&adj,int node, int parant)
    {
        int depth=0;
        for(int &ngbr: adj[node])
        {
            if(ngbr==parant)continue;
            depth=max(depth,getmaxdepth(adj,ngbr,node)+1);
        }
        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int d=getmaxdepth(adj,1,-1);
        if(d==0)return 1;
        return power(2,d-1);      
    }
};