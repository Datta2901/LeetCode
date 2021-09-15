#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        string answer= "";
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')){
                answer += s[i];
            }
        }
        int m = answer.size() - 1;
        for(int i = 0; i < n; i++){
            if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')){
                s[i] = answer[m];
                m -= 1;
                if(m < 0){
                    break;
                }
            }
        }
      return s;
    }
};

int main(){
    Solution obj;
    string s;
    cin >> s;
    cout << obj.reverseOnlyLetters(s) << endl;
    return 0;
}