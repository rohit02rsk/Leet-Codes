class LockingTree {
public:
    unordered_map<int, vector<int> > children;
    unordered_map<int, int> locked_by;
    vector<int> parent;
    
    LockingTree(vector<int>& p) : parent(p) {
        for(int i=0; i<parent.size(); i++) {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(locked_by.count(num)) return false;
        locked_by[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(!locked_by.count(num) or locked_by[num] != user) return false;
        locked_by.erase(num);
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(locked_by.count(num)) return false;
        if (is_locked_child(num) && !is_locked_parent(parent[num])) {
            unlock_descendants(num);
            locked_by[num] = user;
            return true;
        }
        return false;
    }
    void unlock_descendants(int num) {
        for(auto c : children[num]) {
            locked_by.erase(c);
            unlock_descendants(c);
        }
    }
    bool is_locked_child(int num) {
        bool flag = false;
        if (locked_by.find(num) != locked_by.end()) flag = true;
        for (auto ch : children[num]) flag |= is_locked_child(ch);
        return flag;
    }
    
    bool is_locked_parent(int num) {
        if (num == -1) return false;
        if (locked_by.find(num) != locked_by.end()) return true;
        return is_locked_parent(parent[num]);
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */