#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>mag(26,0);
        for(int i = 0; i < magazine.size(); i++){
            mag[magazine[i] - 'a'] += 1;
        }
        for(int i = 0; i < ransomNote.size(); i++){
            if(mag[ransomNote[i] - 'a'] > 0){
                mag[ransomNote[i] - 'a'] -= 1;
            }else{
                return false;
            }
        }
        return true;
    }
};



int main(){
    Solution obj;
    string s1,s2;
    cin >> s1 >> s2;
    cout << obj.canConstruct(s1,s2) << endl;
    return 0;
}