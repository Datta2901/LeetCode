#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bal;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{'|| s[i] == '['){
                bal.push(s[i]);
            }else{
                // cout << s[i] << " " << bal.top() << endl;
                if(bal.empty()){
                    return false;
                }
                if(s[i] == ')' && bal.top() == '('){
                    bal.pop();
                }else if(s[i] == '}' && bal.top() == '{'){
                    bal.pop();
                }else if(s[i] == ']' && bal.top() == '['){
                    bal.pop();
                }else{
                    return false;
                }
           }
        }
        if(!bal.empty()){
            return false;
        }
        return true;
    }
};

int main(){
    Solution obj;
    string s;
    cin >> s;
    cout << obj.isValid(s) << endl;
    return 0;
}