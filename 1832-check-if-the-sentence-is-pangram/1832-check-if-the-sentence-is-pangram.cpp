class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<int> s;
        int n = sentence.length();
        int count = 0;
        for(int i=0 ; i<n ; i++) {
            if(s.find(sentence[i]) == s.end()) {
                count++;
                s.insert(sentence[i]);
            } 
        }
        if(count == 26) return true;
        return false;
    }
};