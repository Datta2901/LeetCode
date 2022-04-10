class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int diff = nums[1] - nums[0];
        int n = nums.size();
        for(int i = 1; i < n - 1; i++){
            if(diff != nums[i + 1] - nums[i]){
                return false;
            }
        }
        return true;
    }
};