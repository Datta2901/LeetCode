#include<bits/stdc++.h>
using namespace std;

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> answer;
        answer.push_back(root->val);
        TreeNode *temp = root;
        while(tem)
    }
};

int main(){

}