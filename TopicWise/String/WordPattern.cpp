#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if(pattern.size() != s.size()){
            return false;
        }
        map<char,string>fre;
        bool space = false;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                space = true;
                break;
            }
        }
        string a = "";
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(!space){
                a = s;
            }
            if(s[i] == ' ' || !space){
                if(fre[pattern[j]] == ""){
                    for(auto it : fre){
                        if(it.second == a){
                            return 0;
                        }
                    }
                    fre[pattern[j]] = a;
                }else if(fre[pattern[j]] != a){
                    return false;
                }
                j++;
                a="";
            }else{
                a += s[i];
            }
        }
        // cout << a << " "  << j << endl;
        if(a == ""){
            return true;
        }
        if(j < pattern.size()){
            if(fre[pattern[j]] != a){
                return false;
            }
        }
        return true;
    }
};

// class Solution{
//     public:
//     bool wordPattern(string pattern,string s){
//         if(pattern.size() != s.size()){
//             return false;
//         }
//         map<string,char>fre;
//         string a = "";
//         int j = 0;
//         for(int i = 0; i < s.size(); i++){
//             if(s[i] == ' '){
//                 // for(auto it : fre){
//                 //     if(it.second == pattern[j]){
//                 //         return false;
//                 //     }
//                 // }
//                 if(fre[a] == 0){
//                     fre[a] = pattern[j];
//                 }else if(fre[a] != pattern[j]){
//                     return false;
//                 }
//                 j++;
//                 a = "";
//             }else{
//                 a += s[i];
//             }
//         }
//         if(j < pattern.size()){
//             if(fre[a] != pattern[j]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };


int main(){
    Solution obj;
    string pattern,s;
    cin >> pattern;
    std::cin.ignore();
    getline(cin,s);
    // cout << pattern << endl;
    // cout << s << endl;
    cout << obj.wordPattern(pattern,s) << endl;
    return 0;
}