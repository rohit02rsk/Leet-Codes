class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int ind) {
        if(ind == word.size())
            return true;
        
        if(i < 0 or j < 0
        or i >= board.size()
        or j >= board[0].size()
        or word[ind] != board[i][j])
            return false;

        char c = board[i][j];
        board[i][j] = '*';
        bool res = dfs(board, word, i+1, j, ind+1)
                or dfs(board, word, i-1, j, ind+1)
                or dfs(board, word, i, j+1, ind+1)
                or dfs(board, word, i, j-1, ind+1);
        board[i][j] = c;
        
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};