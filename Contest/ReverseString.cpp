#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        string a = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                a += s[i];
            }else if(s[i] == ' '){
                if(a != ""){
                    a += s[i];
                    temp.push_back(a);
                    a = "";
                }
            }
        }
        if(a != ""){
            temp.push_back(a);
            a = "";
        }
        for(int i = temp.size() - 1; i >= 0; i--){
            for(int j = 0; j < temp[i].size(); j++){
                if(temp[i][j] != ' '){
                    a += temp[i][j];
                }
            }
             if(i != 0){
                a += ' ';
             }
        }
        return a;
    }
};

int main(){
    Solution obj;
    string s;
    getline(cin,s);
    cout << obj.reverseWords(s) << endl;

}