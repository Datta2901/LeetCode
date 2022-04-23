class Solution {
public:
    string addBinary(string a, string b) {
        string answer = "";
        int carry = 0;
        int m = a.size();
        int n = b.size();
        if(m < n){
            swap(m,n);
            swap(a,b);
        }
        int j = m - 1;
        for(int i = n - 1; i >= 0; i--){
            int n1 = a[j] - '0';
            int n2 = b[i] - '0';
            j--;
            if(n1 + n2 + carry == 3){
                answer.append("1");
                carry = 1;
            }else if(n1 + n2 == 2){
                answer.append("0");
                carry = 1;
            }else if(n1 + n2 == 1){
                if(carry == 1){
                    answer.append("0");
                    carry = 1;
                }else{
                    // cout << "." << endl;
                    // answer.append(".");
                    // continue;
                    answer.append("1");
                }
            }else{
                string aa = to_string(n1 + n2 + carry);
                if(carry == 1){
                    carry = 0;
                }
                answer.append(aa);
            }
        }
        // cout << answer << endl;
        // cout << answer << endl;
        for(int i = j; i >= 0; i--){
            int n1 = a[i] - '0';
            if(n1 + carry == 2){
                answer.append("0");
                carry = 1;
            }else{
                answer.append(to_string(n1 + carry));
                if(carry == 1){
                    carry = 0;
                }
            }
        }
        if(carry == 1){
            answer += '1';
        }
        reverse(answer.begin(),answer.end());

        return answer;
    }
};


// Short Solution
class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int m = a.size();
        int n = b.size();
        int i = m - 1,j = n - 1,carry = 0;
        while(i >= 0|| j >= 0|| carry > 0){
            if(i >= 0){
                carry += (a[i] - '0');
                i--;
            }if(j >= 0){
                carry += (b[j] - '0');
                j--;
            }
            sum += (carry % 2) + '0';
            carry /= 2;
        }
        reverse(sum.begin(),sum.end());
        return sum;
    }
};

