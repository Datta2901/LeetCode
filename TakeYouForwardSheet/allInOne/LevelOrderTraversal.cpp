/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int>answer;
    queue<BinaryTreeNode<int>*> store;
    store.push(root);
    while(!store.empty()){
        BinaryTreeNode<int> *root = store.front();
        store.pop();
        if(root){
            answer.push_back(root->val);
            if(root->left){
                store.push(root->left);
            }if(root->right){
                store.push(root->right);
            }
        }
    }
    return answer;
}


vector<int> level(TreeNode* root){

    queue<TreeNode*> store;
    store.push(root);
    vector<int>answer;
    while(!store.empty()){
        TreeNode* node = store.front();
        store.pop();
        if(node){
            answer.push_back(node->val);
            if(node->left){
                store.push(node->left);
            }if(node->right){
                store.push(node->right);
            }
        }
    }
    return answer;
}