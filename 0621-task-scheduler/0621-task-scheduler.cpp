class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<vector<int>> q;
        vector<int> ctr(26);

        for (int i = 0; i < tasks.size(); ++i)
            ctr[tasks[i] - 'A']++;
        for (int i = 0; i < 26; ++i){
            if (ctr[i])
                pq.push(ctr[i]);
        }

        int time = 0;
        while (!q.empty() || !pq.empty()){
            time++;
            if (!pq.empty()){
                if (pq.top() - 1)
                    q.push({pq.top() - 1, time + n});
                pq.pop();
            }
            if (!q.empty() && q.front()[1] == time){
                pq.push(q.front()[0]);
                q.pop();
            }
        }
        return time;
    }
};