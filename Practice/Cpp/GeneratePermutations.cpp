#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int> > answer;
    void Backtracking(vector<int>&nums,int i,int size){
        if(i == size){
            answer.push_back(nums);
            return ;
        }
        for(int j = i;  j <= size; j++){
            swap(nums[i],nums[j]);
            Backtracking(nums,i + 1,size);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int> > permute(vector<int>& nums) {
        Backtracking(nums,0,nums.size() - 1);
        return answer;
    }
};

int main(){
    Solution obj;

    return 0;
}