class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> res;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > available;
        for(int i=0; i<servers.size(); i++) 
            available.emplace(make_pair(servers[i], i));
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > unavailable;
        int time = 0;
        
        for(int i=0; i<tasks.size(); i++) {
            time = max(time, i);
            if(available.empty()) {
                time = unavailable.top()[0];
            }
            while(!unavailable.empty() and time >= unavailable.top()[0]) {
                auto temp = unavailable.top(); //[timeFree, weight, index]
                unavailable.pop();
                available.emplace(make_pair(temp[1], temp[2]));
            }
            auto [weight, index] = available.top();
            available.pop();
            res.emplace_back(index);
            vector<int> temp;
            temp.emplace_back(time+tasks[i]);
            temp.emplace_back(weight);
            temp.emplace_back(index);
            unavailable.emplace(temp);            
        }
        
        return res;
    }
};