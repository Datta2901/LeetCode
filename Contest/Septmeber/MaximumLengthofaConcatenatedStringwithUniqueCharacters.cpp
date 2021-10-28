#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isUnique(string s){
        vector<bool>fre(26,false);
        for(int i = 0; i < s.size(); i++){
            if(fre[s[i]]){
                return false;
            }else{
                fre[s[i]] = true;
            }
        }
        return true;
    }
    
    int maxLength(vector<string>& arr) {
        string answer = "";
        vector<string>ans;
        ans.push_back("");
        int size = 0;
        for(int i = 0; i < arr.size(); i++){
            if(!isUnique(arr[i])){
                continue;
            }
            for(int j = 0; j < answer.size(); j++){
                string a = answer[j] + arr[i];
                if(isUnique(a)){
                    size = max(size, int(a.size()));
                    ans.push_back(a);
                }
            }
        }
        return size;
    }
};

int main(){
    Solution obj;

    return 0;
}