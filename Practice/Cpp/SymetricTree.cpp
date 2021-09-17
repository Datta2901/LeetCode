#include<bits/stdc++.h>
using namespace std;
//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    bool isMirror(TreeNode *root1,TreeNode *root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }else if(root1 == NULL || root2 == NULL){
            return false;
        }
        return root1->val == root2->val && isMirror(root1->left,root2->right) && isMirror(root1->right,root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};

int main(){
    Solution obj;

    return 0;
}