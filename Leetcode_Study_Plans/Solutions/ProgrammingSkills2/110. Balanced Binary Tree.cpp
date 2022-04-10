class Solution {
    bool answer;
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        if(abs(l - r) > 1){
            answer = false;
            return false;
        }
        return 1 + max(l,r);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        answer = true;
        height(root);
        return answer;
    }
};