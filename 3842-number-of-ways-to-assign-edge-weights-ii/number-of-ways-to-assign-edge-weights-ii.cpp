// class Solution {
// public:
//     vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
//     }
// };
class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;

    vector<int> parentDepth;
    vector<vector<int>> up;
    vector<long long> pow2;
    int LOG;

    void dfs(int u, int p, int d, vector<vector<int>>& g) {
        up[0][u] = p;
        parentDepth[u] = d;

        for (int v : g[u]) {
            if (v == p) continue;
            dfs(v, u, d + 1, g);
        }
    }

    int lca(int a, int b) {
        if (parentDepth[a] < parentDepth[b]) swap(a, b);

        int diff = parentDepth[a] - parentDepth[b];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                a = up[j][a];
        }

        if (a == b) return a;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][a] != up[j][b]) {
                a = up[j][a];
                b = up[j][b];
            }
        }

        return up[0][a];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        vector<vector<int>> g(n + 1);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        parentDepth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1, 1));

        dfs(1, 1, 0, g);

        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                up[j][i] = up[j - 1][ up[j - 1][i] ];
            }
        }

        pow2.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0], v = q[1];

            int w = lca(u, v);
            int len = parentDepth[u] + parentDepth[v]
                    - 2 * parentDepth[w];

            if (len == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)pow2[len - 1]);
            }
        }

        return ans;
    }
};