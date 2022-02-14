/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Memoization
class Solution {
private:
    unordered_map<TreeNode*,int>dp; 
    int getAnswer(TreeNode* root){
        if(root == NULL){
            return dp[root] = 0;
        }
        if(dp.find(root) != dp.end()){
            return dp[root];
        }
        int pick = root->val;
        if(root->left){
            pick += getAnswer(root->left->left) + getAnswer(root->left->right);
        }
        if(root->right){
            pick += getAnswer(root->right->left) + getAnswer(root->right->right);
        }
        int notPick = getAnswer(root->left)+ getAnswer(root->right);
        return dp[root] = max(pick,notPick);
    }
    
public:
    int rob(TreeNode* root) {
       return getAnswer(root);
    }    
};