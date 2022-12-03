class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> m_heap;
        for(char c: s) m[c]++;
        for(auto it: m) m_heap.push({it.second, it.first});
        s = "";
        while(!m_heap.empty()) {
            s += string(m_heap.top().first, m_heap.top().second);
            m_heap.pop();
        }
        return s;
    }
};