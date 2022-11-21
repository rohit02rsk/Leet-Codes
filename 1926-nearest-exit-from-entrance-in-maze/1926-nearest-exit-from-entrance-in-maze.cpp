class Solution {
public:
    int dirx[4] = { -1, 0, 0, 1 };
    int diry[4] = { 0, 1, -1, 0 };
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<array<int, 3>> q;
        q.push({entrance[0], entrance[1], 0});
        while(!q.empty()) {
            auto [i, j, steps] = q.front(); 
            q.pop();
            bool isAtTheEntrance = (i == entrance[0] && j == entrance[1]);
            bool isAtTheBorder = (i == 0 || j == 0 || i == m - 1 || j == n - 1);
            if (!isAtTheEntrance && isAtTheBorder) return steps;
             for (int d = 0; d < 4; d++) {
                int next_i = i + dirx[d];
                int next_j = j + diry[d];

                if (next_i >= 0 && next_j >= 0 && 
                    next_i < m && next_j < n && 
                    maze[next_i][next_j] == '.') {
                    maze[next_i][next_j] = '+';
                    q.push({next_i, next_j, steps + 1});
                }
            }
        }
        return -1;
    }
};