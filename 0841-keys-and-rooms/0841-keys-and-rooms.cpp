class Solution {
public:
    void dfs(vector<vector<int>> &rooms, int start, vector<bool> &vis) {
        vis[start] = true;
        
        for(int i=0; i<rooms[start].size(); i++) 
            if(!vis[rooms[start][i]]) 
                dfs(rooms, rooms[start][i], vis);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, n = rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);
        
        for(i=0; i<n; i++) 
            if(!vis[i]) 
                return false;
        
        return true;
    }
};