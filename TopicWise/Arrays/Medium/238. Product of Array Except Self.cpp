class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1,count = 0;
        bool isZero = false;
        vector<int>answer;
        for(auto it : nums){
            if(it != 0){
                product *= it;
            }else{
                isZero = true;
                count++;
            } 
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                if(isZero){
                     answer.push_back(0);
                    continue;
                }
                answer.push_back(product / nums[i]);
            }else{
                if(nums.size() == count || count > 1){
                    answer.push_back(0);
                    continue;
                }
                answer.push_back(product);
            }
        }
        return answer;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lhs(nums.size(), 1);
        int rhs = 1;
        for(int i = 1; i<nums.size() ; i++){
            lhs[i] = lhs[i-1] * nums[i-1];
        }
        for(int i = lhs.size()-1; i >= 1 ; i--){
            rhs *= nums[i];
            lhs[i-1] *= rhs;
        }
        return lhs;
    }
};