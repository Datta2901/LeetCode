#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num;
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            auto b = find(nums.begin() + i+  1,nums.end(),target - a);
            if(b-nums.begin() != nums.size()){
                num.push_back(i);
                num.push_back(b-nums.begin());
                break;
            }
        }
        return num;
    }
};



int main(){
    int  size;
    cin >> size;
    vector<int>nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int target;
    cin >> target;
    Solution obj;
    nums = obj.twoSum(nums,target);
    for(int i = 0; i < 2; i++){
        cout << nums[i] << " ";
    }
}


