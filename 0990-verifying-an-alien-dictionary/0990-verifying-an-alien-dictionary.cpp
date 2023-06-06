class Solution {
public:
    unordered_map<char, int> mp;
    bool isSorted(string& s1, string& s2) {
        int i = -1;
        while(++i < s1.size() and i < s2.size()) {
            if(mp[s1[i]] != mp[s2[i]])
                return mp[s1[i]] < mp[s2[i]];
        }
        return s1.size() <= s2.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<order.size(); i++) mp[order[i]] = i;
        for(int i=0; i<words.size()-1; i++) {
            if(!isSorted(words[i], words[i+1]))
                return false;
        }
        return true;
    } 
};