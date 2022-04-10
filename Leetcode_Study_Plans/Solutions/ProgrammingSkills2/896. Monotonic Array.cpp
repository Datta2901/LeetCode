class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = true;
        int i = 1;
        while(i < n && nums[i - 1] <= nums[i]){
            i++;
        }
        if(i == n){
            return true;
        }
        i = 1;
        while(i < n && nums[i - 1] >= nums[i]){
            i++;
        }
        if(i == n){
            return true;
        }
        return false;
    }
};