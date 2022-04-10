class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool zero = false;
        int neg = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zero = true;
                break;
            }else if(nums[i] < 0){
                neg++;
            }
        }
        if(zero){
            return 0;
        }else if(neg & 1){
            return -1;
        }
        return 1;
    }
};