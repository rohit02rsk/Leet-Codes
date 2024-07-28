class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adjList(n + 1);
        vector<int> visTime(n + 1, INT_MAX);
        vector<int> visCount(n + 1, 0);
        int minTime = INT_MAX;
        queue<array<int, 2>> q;

        for (auto &e : edges)
            adjList[e[0]].push_back(e[1]),
            adjList[e[1]].push_back(e[0]);
        
        q.push({1, 0});
        while (!q.empty()) {
            auto [node, t] = q.front(); 
            q.pop();
            
            for (auto next : adjList[node]) {
                int t2 = t;
                bool isRed = (t2 / change) % 2;
        
                if (isRed) 
                    t2 += change - t2 % change;
                
                t2 += time;
                
                if (next == n && minTime == INT_MAX) 
                    minTime = t2;

                if (next == n && t2 > minTime) 
                    return t2;

                if (visTime[next] != t2 && visCount[next] <= 1) { 
                    visTime[next] = t2;
                    visCount[next]++;
                    q.push({next, t2});
                }
            }
        }
        return -1;
    }
};