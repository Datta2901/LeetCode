class NumArray {
public:
    vector<int>prefix;
    
    void build(vector<int>nums){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            prefix[i] = sum;
        }
    }
    
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());
        build(nums);
    }
    
    int sumRange(int left, int right) {
        if(left != 0){
            return prefix[right] - prefix[left - 1];   
        }
        return prefix[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */