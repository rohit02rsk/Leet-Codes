class Node {
public:
    Node* children[26];
    bool isEnd;
    Node () {
        isEnd = false;
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(!temp->children[word[i] - 'a'])
                temp->children[word[i] - 'a'] = new Node();
            temp = temp->children[word[i] - 'a'];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        return help(temp, 0, word);
    }
    bool help(Node *root, int i, string s) {
        if(!root) return false;
        if(i == s.size()) return root->isEnd;
        if(s[i] != '.') return help(root->children[s[i] - 'a'], i+1, s);
        for(int it=0; it<26; it++) {
            if(help(root->children[it], i+1, s))
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */