class Solution {
public:

    long long limit = 20000;

    bool bfs(vector<int>& start, vector<int>& finish,
             unordered_set<string>& blockedSet) {

        queue<pair<int,int>> q;
        unordered_set<string> visited;

        q.push({start[0], start[1]});
        visited.insert(to_string(start[0]) + "#" + to_string(start[1]));

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            // reached destination
            if (x == finish[0] && y == finish[1])
                return true;

            // escaped blocked area
            if (visited.size() > limit)
                return true;


            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= 1000000 || ny >= 1000000)
                    continue;


                string key = to_string(nx) + "#" + to_string(ny);

                if (blockedSet.count(key))
                    continue;

                if (visited.count(key))
                    continue;


                visited.insert(key);
                q.push({nx, ny});
            }
        }

        return false;
    }


    bool isEscapePossible(vector<vector<int>>& blocked,
                          vector<int>& source,
                          vector<int>& target) {

        unordered_set<string> blockedSet;

        for (auto &b : blocked) {
            blockedSet.insert(to_string(b[0]) + "#" + to_string(b[1]));
        }


        return bfs(source, target, blockedSet) &&
               bfs(target, source, blockedSet);
    }
};