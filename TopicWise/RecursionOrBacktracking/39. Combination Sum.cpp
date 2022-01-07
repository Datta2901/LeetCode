#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int> > answer;
    void GetAnswer(vector<int>&ds,vector<int>&nums,int ind,int sum,int target){
        if(sum > target){
            return;
        }
        if(ind >= nums.size()){
            return;
        }
        if(sum == target){
            answer.push_back(ds);
            return;
        }

        // pick
        if(target >= nums[ind]){
            ds.push_back(nums[ind]);
            sum += nums[ind];
            GetAnswer(ds,nums,ind,sum,target);
            sum -= nums[ind];
            ds.pop_back();
        }

        // not pick
        GetAnswer(ds,nums,ind + 1,sum,target);
    }
    
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        GetAnswer(ds,candidates,0,0,target);
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