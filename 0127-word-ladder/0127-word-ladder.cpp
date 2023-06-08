class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        int res = 1;
        queue<string> q;

        for(auto x: wordList)
            dict.insert(x);
        
        q.push(beginWord);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                string curr = q.front();
                q.pop();
                
                if(curr == endWord)
                    return res;
                
                dict.erase(curr);
                for(int j=0; j<curr.size(); j++) {
                    char c = curr[j];
                    for(int k=0; k<26; k++) {
                        curr[j] = 'a' + k;
                        if(dict.count(curr)) {
                            q.push(curr);
                            dict.erase(curr);
                        }
                        curr[j] = c;
                    }
                }
            }
            res++;
        }
        
        return 0;
    }
};