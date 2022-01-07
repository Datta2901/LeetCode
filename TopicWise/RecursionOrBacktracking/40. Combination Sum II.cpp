#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int> > answer;
    
    void BackTracking(vector<int>&per,vector<int>nums,int sum,int start){
        if(sum < 0){
            return ;
        }else if(sum == 0){
            answer.push_back(per);
        }else{
            for(int i = start; i < nums.size(); i++){
                if(i > start && nums[i - 1] == nums[i]){
                    continue;
                }
                per.push_back(nums[i]);
                BackTracking(per,nums,sum - nums[i], i + 1);
                per.pop_back();
            }
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>per;
        BackTracking(per,candidates,target,0);
        return answer;
    }
};

int main(){
    Solution obj;
    vector<int>num;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    return 0;
}