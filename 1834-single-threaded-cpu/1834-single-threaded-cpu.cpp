class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        //store indices
        for(int i=0; i<n; i++) 
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());
        
        vector<int> res;
        int task_ind = 0;
        long long int t = tasks[0][0]; //first enqueue time
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        
        while(!pq.empty() or task_ind < n) {
            while(task_ind < n and t >= tasks[task_ind][0]) {
                pq.push({tasks[task_ind][1], tasks[task_ind][2]});
                task_ind++;
            }
            if(pq.empty()) {
                t = tasks[task_ind][0];
            }
            else {
               auto p = pq.top();
               pq.pop();
               res.push_back(p.second);
               t += p.first; 
            }
        }
        
        return res;
    }
};