#include<bits/stdc++.h>
using namespace std;

// Using Linear Search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return 0;
        }
        if(size >= 2){
            if(nums[0] > nums[1]){
                return 0;
            }
        }
        for(int i = 1; i < size - 1; i++){
            if(nums[i - 1] < nums[i] && nums[i] > nums[i + 1]){
                return i;
            }
        }
        if(nums[size-2] < nums[size -1 ]){
            return size - 1;
        }
        return 0;
    }
};


int main(){
    Solution obj;

    return 0;
}