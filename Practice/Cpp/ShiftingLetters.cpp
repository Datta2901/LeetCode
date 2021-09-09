#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char shiftChar(char a,long long int  k){
        char ans = 'a';
        k = k % 26;
        if(a + k > 'z'){
            int diff = 'z' - a;
            k -= diff;
            ans = ans + k - 1;
        }else{
            ans = a + k;
        }
        return ans;
    }
    
    // as constraints are high 
    // int overflows
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<long long int>suffixSum(n,0);
        long long int sum = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += shifts[i];
            suffixSum[i] = sum;
        }
        string answer = "";
        for(int i = 0; i < n; i++){
            answer +=( shiftChar(s[i],suffixSum[i]));
        }
        return answer;
    }
};

// 1 line solution
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long sum=0;
        for(int i = s.size()- 1; i >= 0; i--){
            s[i] = ((s[i]-'a') + (sum+shifts[i]) % 26) % 26 + 'a';
            sum += shifts[i];
        }
        return s;
    }
};


int main(){
    Solution obj;
    vector<int>num;
    string s;
    cin >> s;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    // char a = 'a';
    // if(a + 26 > 'z'){
    //     int b = 'z' - a;
    //     cout << b << endl;
    // }
    cout << obj.shiftingLetters(s,num);   
    return 0;
}