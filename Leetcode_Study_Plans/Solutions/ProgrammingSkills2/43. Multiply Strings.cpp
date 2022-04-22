class Solution {
public:
    string multiply(string num1, string num2){
        string answer;
        int m = num1.size(),n = num2.size();
        vector<int> sum(m + n,0);
        int carry = 0,a = 0;
        for(int i = n - 1; i >= 0; i--){
            a = num2[i] - '0';
            for(int j = m - 1; j >= 0; j--){
                b = nums[j] - '0';
                carry +=  a * b + sum[i + j + 1];
                sum[i + j + 1] = carry % 10;
                carry /= 10;
            }
            if(carry > 0){
                sum[i + j + 1] = carry;
            }
            carry = 0;
        }
        while(sum[0] == 0 && sum.size() > 1){
            sum.erase(sum.begin());
        }
        string answer = 0;
        int size = sum.size();
        for(int i = 0; i < size; i++){
            answer += (sum[i] + '0');
        }
        return answer;
    }
};
