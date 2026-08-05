class Solution {
public:

   void dfs(int node, vector<vector<int>>& graph , set<int>& sus )
   {
        sus.insert(node);
        for(int nei: graph[node])
        {
            if(sus.find(nei)==sus.end())
            {
                dfs(nei,graph,sus);
            }
        }  
   }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>graph(n);
        for( auto & e:invocations)
        {
           graph[e[0]].push_back(e[1]);
        }
        set<int>sus;
        dfs(k,graph,sus);

        for(auto  &e : invocations)
        {
            int u=e[0];
            int v=e[1];

            if(sus.find(u)==sus.end() && sus.find(v)!=sus.end())
            {
                vector<int>ans;
                for(int  i=0;i<n;i++)
                {
                 ans.push_back(i);
                }
                return ans;
            }
        }

            vector<int>ans;
            for(int i=0;i<n;i++)
            {
                if(sus.find(i)==sus.end())
                {
                    ans.push_back(i);
                }
             
            }
        return ans;
        
    }
};