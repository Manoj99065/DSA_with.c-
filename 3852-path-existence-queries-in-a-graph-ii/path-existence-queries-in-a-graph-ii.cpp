// // class Solution {
// // public:
// //     vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
// //     }
// // };
// class Solution {
// public:
//     vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
//                               vector<vector<int>>& queries) {

//         vector<pair<int,int>> a;
//         for(int i=0;i<n;i++)
//             a.push_back({nums[i], i});

//         sort(a.begin(), a.end());

//         vector<int> pos(n);
//         vector<int> comp(n);

//         int cid = 0;
//         pos[a[0].second] = 0;
//         comp[a[0].second] = cid;

//         for(int i=1;i<n;i++){
//             if(a[i].first - a[i-1].first > maxDiff)
//                 cid++;
//             pos[a[i].second] = i;
//             comp[a[i].second] = cid;
//         }

//         vector<int> ans;
//         for(auto &q : queries){
//             int u = q[0], v = q[1];
//             if(comp[u] != comp[v])
//                 ans.push_back(-1);
//             else
//                 ans.push_back(abs(pos[u] - pos[v]));
//         }

//         return ans;
//     }
// };


class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[arr[i].second] = i;

        // next[i] = farthest sorted position reachable in one edge
        vector<int> nxt(n);
        int r = 0;
        for(int l = 0; l < n; l++) {
            while(r + 1 < n && arr[r + 1].first - arr[l].first <= maxDiff)
                r++;
            nxt[l] = r;
        }

        // Component IDs
        vector<int> comp(n);
        int cid = 0;
        comp[0] = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i].first - arr[i - 1].first > maxDiff)
                cid++;
            comp[i] = cid;
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for(auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u > v) swap(u, v);

            if(comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if(u == v) {
                ans.push_back(0);
                continue;
            }

            int cur = u;
            int steps = 0;

            for(int k = LOG - 1; k >= 0; k--) {
                if(up[k][cur] < v) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};
