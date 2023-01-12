class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>answer;
        int carry = 1;
        int n = digits.size() - 1;
        for(int i = n; i >= 0; i--){
            if(carry + digits[i] >= 10){
                answer.push_back(digits[i] / 10);
                carry = carry % 10;
            }else{
                answer.push_back(carry + digits[i]);
                carry = 0;
            }
        }
        if(carry > 0){
            answer.push_back(carry);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};