class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis,
             int &vertices, int &edges) {
        vis[node] = 1;
        vertices++;
        edges += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, vertices, edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int vertices = 0;
                int edgeCount = 0;

                dfs(i, adj, vis, vertices, edgeCount);

                edgeCount /= 2;   // Every edge counted twice

                if (edgeCount == (vertices * (vertices - 1)) / 2)
                    ans++;
            }
        }

        return ans;
    }
};
