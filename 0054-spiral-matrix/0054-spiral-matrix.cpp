class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> res;
        vector<int> rows_move = {0, 1, 0, -1};
        vector<int> cols_move = {1, 0, -1, 0}; 
        vector<vector<int>> vis(rows, vector<int> (cols, false));
        int x = 0; 
        int y = 0; 
        int direction = 0;
        
        for(int i=0; i<rows*cols; i++) {
            res.push_back(matrix[x][y]);
            vis[x][y] = true;
            
            int newX = x + rows_move[direction];
            int newY = y + cols_move[direction];
            
            if(newX >= 0 and newX < rows and newY >= 0 and newY < cols and !vis[newX][newY]) {
                x = newX;
                y = newY;
            } else {
                direction = (direction+1)%4;
                x += rows_move[direction];
                y += cols_move[direction];
            }
        }
        
        return res;
    }
};