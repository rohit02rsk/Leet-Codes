class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (size(word1) != size(word2)) return false;
        return signature(word1) == signature(word2);
    }
    
    vector<int> signature(string word) {
        vector<int> freq(26);
        for (char ch : word) ++freq[ch - 'a'];
        vector<int> ans = freq;
        sort(freq.begin(), freq.end(), greater<int>());
        for (int i = 0, j = 0; i < ans.size(); ++i)
            if (ans[i]) ans[i] = freq[j++];
        return ans;
    }
};