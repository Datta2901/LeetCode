#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
private:
    TreeNode* BuildBinaryTree(vector<int>&inorder,vector<int> &postorder,int is,int ie,int ps,int pe,map<int,int>InorderIndex){
        if(ps > pe || is > ie){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = InorderIndex[postorder[pe]];
        int ns = inRoot - is; 
        root->left = BuildBinaryTree(inorder,postorder,is,inRoot - 1,ps,ps + ns - 1,InorderIndex);
        root->right = BuildBinaryTree(inorder,postorder,inRoot + 1,ie,ps + ns,pe - 1,InorderIndex);
        return root;
    }    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        map<int,int>InorderIndex;
        for(int i = 0; i < inorder.size(); i++){
            InorderIndex[inorder[i]] = i;
        }
        return BuildBinaryTree(inorder,postorder,0,inorder.size() - 1,0,postorder.size() - 1,InorderIndex);
    }
};

class Solution { 
private:
    int index;
    int search(vector<int>&inorder,int start,int end,int val){
        for(int i = start; i <= end; i++){
            if(inorder[i] == val){
                return i;
            }
        }
        return -1;
    }

    // Start and end refers to the pointers in inorder
    TreeNode* BuildBinaryTree(vector<int>&inorder,vector<int>&postorder,int start,int end){
        
        if(start > end){
            return NULL;
        }
        
        int val = postorder[index]; 
        index--;
        TreeNode* root = new TreeNode(val);
        if(start == end){
            return root;
        }
        int pos = search(inorder,start,end,val);
        root->right = BuildBinaryTree(inorder,postorder,pos + 1,end);
        root->left = BuildBinaryTree(inorder,postorder,start,pos - 1);
        return root;        
    } 

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()){
            return NULL;
        }
        index = postorder.size() - 1;
        return BuildBinaryTree(inorder,postorder,0,inorder.size() - 1);
    }

};

void inorderTrav(TreeNode* root){
    if(root){
        inorderTrav(root->left);
        cout << root->val  << " ";
        inorderTrav(root->right);
    }
}


int main(){
    Solution obj;
    vector<int>inorder,postorder;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        inorder.push_back(a);
    }
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        postorder.push_back(a);
    }
    TreeNode* root = obj.buildTree(inorder,postorder);
    inorderTrav(root);
    return 0;
}