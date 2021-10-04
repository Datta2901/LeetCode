class Solution {
public:
    string multiply(string num1, string num2){
        string answer;
        int len_num1 = num1.length(), len_num2 = num2.length(), i, j;
        vector<int8_t> result(len_num1 + len_num2, 0);
        int L1, carry1 = 0, L1toInt = 0;

        for (i = num2.length() - 1; i >= 0; i--){
            L1 = num2[i] - '0';
            for (j = num1.length() - 1; j >= 0; j--){
                L1toInt = num1[j] - '0';
                carry1 = L1toInt * L1 + carry1 + result[j + i + 1]; 
                result[j + i + 1] = carry1 % 10;
                carry1 = carry1 / 10;
            }
            if (carry1 > 0)
                result[i + j + 1] = carry1;
            carry1 = 0;
        }
        
        while (result[0] == 0 && result.size() > 1)
            result.erase(result.begin());

        for (i = 0; i < result.size(); i++){
            answer += '0' + result[i];
        }
        
        return answer;
    }
};
