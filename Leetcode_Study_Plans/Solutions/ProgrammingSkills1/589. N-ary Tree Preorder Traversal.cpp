class Solution {
    vector<int>answer;
    void traverse(Node* root){
        if(!root){
            return;
        }
        answer.push_back(root->val);
        for(auto it : root->children){
            traverse(it);
        }
    }
public:
    vector<int> preorder(Node* root) {
        traverse(root);
        return answer;
    }
};