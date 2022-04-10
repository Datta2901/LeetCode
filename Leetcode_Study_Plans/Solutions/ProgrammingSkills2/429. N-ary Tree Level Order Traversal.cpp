/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> answer;
        if(root == NULL){
            return answer;
        }
        queue<Node*>store;
        answer.push_back({root->val});
        store.push(root);
        while(!store.empty()){
            int size = store.size();
            vector<int>level;
            while(size--){
                Node* f = store.front();
                store.pop();
                for(auto it : f->children){
                    store.push(it);
                    level.push_back(it->val);
                }
            }
            if(level.size() > 0){
                answer.push_back(level);
            }
        }
        return answer;
    }
};