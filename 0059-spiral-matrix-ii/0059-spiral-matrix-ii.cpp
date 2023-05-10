class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        vector<int> r_move = {0, 1, 0, -1};
        vector<int> c_move = {1, 0, -1, 0};
        int x = 0;
        int y = 0;
        int dir = 0;

        for(int i=1; i<=n*n; i++) {
            res[x][y] = i;
            vis[x][y] = true;
            
            int newX = x + r_move[dir];
            int newY = y + c_move[dir];
            
            if(newX >= 0 and newX < n and newY >= 0 and newY < n and !vis[newX][newY]) {
                x = newX;
                y = newY;
            } else {
                dir = (dir+1)%4;
                x += r_move[dir];
                y += c_move[dir];
            }
        }
        
        return res;
    }
};