class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node* left;
    Node* right;
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left; // left <--> right
    }
    
    // remove from the list
    void remove(Node* node) {
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt;
        nxt->prev = prv;
    }

    // insert at the right - most recent
    void insert(Node* node) {
        Node* prv = right->prev;
        right->prev = node;
        prv->next = node;
        node->next = right;
        node->prev = prv;
    }

    int get(int key) {
        if(mp.count(key)) {
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key))
            remove(mp[key]);
        mp[key] = new Node(key, value);
        insert(mp[key]);

        if(mp.size() > cap) {
            Node* lru = left->next;
            left->next = left->next->next;
            mp.erase(lru->key);
            remove(lru);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */