class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>sum;
        int carry = 0;
        int size = num.size();
        int i = size - 1;
        while(i >= 0 || k > 0 || carry > 0){
            if(i >= 0){
                carry += num[i];
                i--;
            }if(k > 0){
                carry += k % 10;
                k /= 10;
            }
            sum.push_back(carry % 10);
            carry /= 10;
        }
        reverse(sum.begin(),sum.end());
        return sum;
    }
};