class Node {
public:
    char val;
    bool isEnd;
    Node* children[26];
    Node(char v) {
        val = v;
        isEnd = false;
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('0');
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++) {
            int ind = word[i] - 'a';
            if(!curr->children[ind])
                curr->children[ind] = new Node(word[i]);
            curr = curr->children[ind];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++) {
            int ind = word[i] - 'a';
            if(!curr->children[ind]) return false;
            curr = curr->children[ind];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++) {
            int ind = word[i] - 'a';
            if(!curr->children[ind]) return false;
            curr = curr->children[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */