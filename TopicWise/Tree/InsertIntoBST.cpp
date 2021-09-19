#include<bits/stdc++.h>
using namespace std;



//  * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }
        while(root != NULL){
            if(root->val > val){
                root = root->left;
            }
            else if(root->val < val){
                root = root->right;
            }else{
                return root;
            }
        }
        return NULL;
    }
};

int main(){
    Solution obj;
    Treecreate();
    cout << endl;
    
    return 0;
}