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
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > answer;
        if(root == NULL){
            return answer;
        }
        queue<TreeNode*> q;
        vector<int>level;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node != NULL){
                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }if(node->right){
                    q.push(node->right);
                }
            }else if(node == NULL && !q.empty()){
                answer.push_back(level);
                level.clear();
                q.push(node);
            }
        }
        answer.push_back(level);
        return answer;
    }
};

int main(){
    Solution obj;

    return 0;
}