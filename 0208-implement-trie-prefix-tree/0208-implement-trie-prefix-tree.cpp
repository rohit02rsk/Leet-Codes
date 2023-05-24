class Node {
public:
    Node* children[26];
    bool isEnd;
    Node() {
        isEnd = false;
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++) {
            if(!node->children[word[i] - 'a']) {
                node->children[word[i] - 'a'] = new Node();
            }
            node = node->children[word[i] - 'a'];
        }
        
        node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        
        for(int i=0; i<word.size(); i++) {
            if(!node->children[word[i] - 'a']) {
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        
        for(int i=0; i<prefix.size(); i++) {
            if(!node->children[prefix[i] - 'a']) {
                return false;
            }
            node = node->children[prefix[i] - 'a'];
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