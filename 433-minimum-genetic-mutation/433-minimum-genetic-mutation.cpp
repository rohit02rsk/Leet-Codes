class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s;
        unordered_set<string> vis;
        int n = start.length();
        for(auto str: bank) s.insert(str);
        if(s.find(end) == s.end()) return -1;
        
        queue<string> q;
        q.push(start);
        
        int steps = 0;
        while(!q.empty()) {
            int len = q.size();
            while(len--) {
                string curr = q.front();
                q.pop();
                if(curr == end) return steps;
                s.erase(curr);
                for(int i=0; i<n; i++) {
                    string t = curr;
                    t[i]='A';
                    if(s.count(t)) q.push(t);
                    t[i]='C';
                    if(s.count(t)) q.push(t);
                    t[i]='G';
                    if(s.count(t)) q.push(t);
                    t[i]='T';
                    if(s.count(t)) q.push(t);
                }
            }
            steps++;
        }
        
        return -1;
    }
};