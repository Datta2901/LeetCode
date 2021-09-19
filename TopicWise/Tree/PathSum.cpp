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


void Treecreate(){
    struct TreeNode *p, *t;
    int x;
    queue<TreeNode*> q;
    printf("Enter root value ");
    cin >> x;
    root = (struct TreeNode*)malloc(sizeof(TreeNode));
    root->val = x;
    root->left = root->rchild = NULL;
    q.push(root);
    while (!q.empty()){
        p = q.front();
        q.pop();
        printf("Enter left child of %d ", p->val);
        scanf("%d", &x);
        if (x != -1){
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            t->val = x;
            t->left = t->rchild = NULL;
            p->left = t;
            q.push(t);
        }
        printf("Enter right child of %d ", p->val);
        scanf("%d", &x);
        if (x != -1){
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            t->val = x;
            t->left = t->rchild = NULL;
            p->rchild = t;
            q.push(t);
        }
    }
}

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }else if(root->left == NULL && root->right == NULL && targetSum - root->val  == 0){
            return true;
        }else {
            return hasPathSum(root->left,targetSum - root->val) || hasPathSum(root->right,targetSum - root->val);
        }
    }
};


int main(){
    Solution obj;

    return 0;
}