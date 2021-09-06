#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.*/
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
    string z;
    void printPostorder(struct TreeNode* node){
        if (node == NULL)
            return;
    
        printPostorder(node->left);
    
    
        printPostorder(node->right);
        z= z + to_string(node->val);
    
    }
    TreeNode* insert(TreeNode* root,int a){
        TreeNode* newNode = new TreeNode(a);
        if(root == NULL){
            newNode->val = a;
            return newNode;
        }
        if(root->val > a){
            root->left = insert(root->left,a);
        }else{
            root->right = insert(root->right,a);
        }
        return root;
    }   
    
    vector<TreeNode*> generateTrees(int n) {
        vector<int>num(n,0);
        vector<TreeNode*> answer;
        for(int i = 0; i < n; i++){
            num[i] = i + 1;      
        }
        
        map<string,int>map;
        TreeNode* root = NULL; 
            for(int i = 0; i < n; i++){
                root = insert(root,num[i]);
            }
            answer.push_back(root);
        while (next_permutation(num.begin(), num.end())){
            TreeNode* root = NULL; 
            for(int i = 0; i < n; i++){
                root = insert(root,num[i]);
            }
            z="";
            printPostorder(root);
            if(map[z]==0)
            {   
                answer.push_back(root);
                map[z]=1;
        }
        }
        return answer;
    }
};