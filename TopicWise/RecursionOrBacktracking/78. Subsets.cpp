#include<bits/stdc++.h>
using namespace std;
// BackTracking
class Solution {
public:
    vector<vector<int> > answer;
    void BackTrack(int start,vector<int> &sub,vector<int>& nums){
        answer.push_back(sub);
        for(int i = start; i < nums.size(); i++){
            sub.push_back(nums[i]);
            BackTrack(i + 1,sub,nums);
            sub.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>sub;
        BackTrack(0,sub,nums);
        return answer;
    }
};

// Complete Recursive solution
class Solution{
    vector<vector<int> >answer;
    void printSubsets(vector<int>&nums){
        for(auto &it : nums){
            cout << it << " ";
        }
        cout << endl;
    }
    public:
    void subsets(int ind,vector<int>&sub,vector<int>&nums){
        if(ind >= nums.size()){
            printSubsets(sub);
            answer.push_back(sub);
            return;
        }
        //pick this current element to our subset
        sub.push_back(nums[ind]); 
        subsets(ind + 1,sub,nums);
        sub.pop_back();
        // not pick the current element to our subet
        subsets(ind + 1,sub,nums);
    }
}

// Using Bit manupulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = 1 << nums.size();
        vector<vector<int>> answer(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < nums.size(); j++){
                // checking if jth bit is set or not
                if(i & (1 << j)){
                    answer[i].push_back(nums[j]);
                }
            }
        }
        return answer;
    }
};