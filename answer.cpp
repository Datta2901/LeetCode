// #include<bits/stdc++.h>
// using namespace std;

// const int n = 5;

// int ans(int arr[],int m){
//     int sum = 0;
    
//     map<int,int>s;
//     for (int i=0; i<m; i++)
//     {
//         if (s[arr[i]] == 0)
//         {
//             sum += arr[i];
//            s[arr[i]] = 1;
//         }
//     }
//     return sum;
// }

// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     int n= sizeof(arr)/sizeof(arr[0]);
//     cout << ans(arr,m)  << endl;
//     return 0;
// }


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
        int required = INT_MIN;
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
                int an  = *min_element(level.begin(),level.end());
                required = max(an,required);
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

bool findPair(Node* root, Node* temp, int x)
{
    if (!root)
        return false;
 
    if (root != temp && ((root->data + temp->data) == x))
        return true;
 
    if (findPair(root->left, temp, x) || findPair(root->right, temp, x))
        return true;
 
    return false;
}
 

void countPairs(Node* root, Node* curr, int x, int& count)
{
    if (!curr)
        return;
 
    if (findPair(root, curr, x))
        count++;
 
    countPairs(root, curr->left, x, count);
 
    countPairs(root, curr->right, x, count);
}