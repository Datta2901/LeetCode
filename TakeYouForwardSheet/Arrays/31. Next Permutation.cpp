class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int IncreasingIndex = -1;
        int NextGreaterIndex = 0;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                IncreasingIndex = i;
                break;
            }
        }
        if(IncreasingIndex >= 0){
            for(int i = n - 1; i > IncreasingIndex; i--){
                if(nums[IncreasingIndex] < nums[i]){
                    NextGreaterIndex = i;
                    break;
                }
            }
            swap(nums[NextGreaterIndex],nums[IncreasingIndex]);
        }
        reverse(nums.begin() + IncreasingIndex + 1,nums.end());
    }
};