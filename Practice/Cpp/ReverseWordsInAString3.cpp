#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string answer,word = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(word.begin(),word.end());
                answer += word;
                answer += ' ';
                word = "";
            }else{
                word += s[i];
            }
        }
        reverse(word.begin(),word.end());
        answer += word;
        return answer;
    }
};

int main(){
    Solution obj;
    string s;
    getline(cin,s);
    cout << obj.reverseWords(s) << endl;
    return 0;
}