class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        Node* res = new Node(node->val);
        mp[node] = res;

        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for(auto nbr : curr->neighbors) {
                if(!mp.count(nbr)) {
                    mp[nbr] = new Node(nbr->val);
                    q.push(nbr);
                }
                mp[curr]->neighbors.push_back(mp[nbr]);
            }
        }
        return res;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/