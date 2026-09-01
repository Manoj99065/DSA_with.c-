class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int sr = -1, sc = -1;
        vector<vector<int>> litter(n, vector<int>(m, -1));

        int k = 0;

        // Find S and number every L
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litter[i][j] = k++;
                }
            }
        }

        int allCollected = (1 << k) - 1;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            n,
            vector<vector<vector<bool>>>(
                m,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );

        // {row, col, energy, mask, moves}
        queue<array<int, 5>> q;

        q.push({sr, sc, energy, 0, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, e, mask, moves] = q.front();
            q.pop();

            // All litter collected
            if (mask == allCollected) {
                return moves;
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                // Wall
                if (classroom[nr][nc] == 'X')
                    continue;

                // Need energy to make a move
                if (e == 0)
                    continue;

                int ne = e - 1;

                // If we arrive at R, recharge
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                int nmask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {
                    int id = litter[nr][nc];
                    nmask |= (1 << id);
                }

                if (!visited[nr][nc][ne][nmask]) {
                    visited[nr][nc][ne][nmask] = true;

                    q.push({
                        nr,
                        nc,
                        ne,
                        nmask,
                        moves + 1
                    });
                }
            }
        }

        return -1;
    }
};