// // class Solution {
// // public:
// //     bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
// //     }
// // };

// class Solution {
// public:
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//         int m = grid.size(), n = grid[0].size();

//         vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

//         deque<pair<int,int>> dq;

//         dist[0][0] = grid[0][0];
//         dq.push_front({0,0});

//         vector<pair<int,int>> dirs = {
//             {1,0}, {-1,0}, {0,1}, {0,-1}
//         };

//         while (!dq.empty()) {
//             auto [r, c] = dq.front();
//             dq.pop_front();

//             for (auto &[dr, dc] : dirs) {
//                 int nr = r + dr;
//                 int nc = c + dc;

//                 if (nr < 0 || nr >= m || nc < 0 || nc >= n)
//                     continue;

//                 int cost = grid[nr][nc];

//                 if (dist[r][c] + cost < dist[nr][nc]) {
//                     dist[nr][nc] = dist[r][c] + cost;

//                     if (cost == 0)
//                         dq.push_front({nr, nc});
//                     else
//                         dq.push_back({nr, nc});
//                 }
//             }
//         }

//         return dist[m-1][n-1] < health;
//     }
// };

class Solution {
public: 
    vector<vector<int>>direction{{0,1},{0,-1},{1,0},{-1,0}} ;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        deque<pair<int,int>>deq;
        result[0][0]=grid[0][0];

        deq.push_front({0,0});
        while(!deq.empty())
        {
            auto[r,c]=deq.front();
            deq.pop_front();

            for(auto & dir:direction)
            {
                       int nr=r+dir[0];
                       int nc=c+dir[1];

                       if(nr<0 || nr >=m || nc<0 || nc>=n)continue;

                       if(result[r][c]+grid[nr][nc]<result[nr][nc])
                       {
                        result[nr][nc]=result[r][c]+grid[nr][nc];


                        if(grid[nr][nc]==0)
                        {
                            deq.push_front({nr,nc});
                        }
                        else
                        {
                            deq.push_back({nr,nc});
                        }
                       }
            }
        }
        int x=result[m-1][n-1];
        return health-x>=1;

    }
};