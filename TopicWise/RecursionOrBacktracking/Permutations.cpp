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
    int size;
    cin >> size;
    vector<int>nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }

    vector<vector<int> > answer = obj.permutate(nums);
    for(auto i : nums){
        for(auto j : i){
            cout << j << " ";
        }
    }
    return 0;
}