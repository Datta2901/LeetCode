#include<bits/stdc++.h>
using namespace std;


class Solution{
    private:
        unordered_map<int,int> fre;
        vector<int>answer;
        int maximum;
    public:
        vector<int> findFrequentTreeSum(TreeNode* root) {
            maximum = 0;
            dfs(root);
            for(auto it : fre){
                if(it.second == maximum){
                    answer.push_back(it.first);
                }
            }
            return answer;
        }

        int dfs(TreeNode* root){
            if(root == NULL){
                return 0;
            }
            int sum = dfs(root->left) + dfs(root->right) + root->val;
            fre[sum]++;
            maximum = max(maximum,fre[sum]);
            return sum;
        }
};




int main(){
    
    return 0;
}