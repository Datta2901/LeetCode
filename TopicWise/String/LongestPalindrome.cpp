#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> fre;
        for(int i = 0; i < s.size(); i++){
            fre[s[i]]++;
        }
        int count = 0;  
        bool middle = true;
        for(auto it : fre){
            if(it.second % 2 == 0){
                count += (it.second);
            }else{
                if(it.second >= 1 && middle){
                    middle = false;
                    count += 1;
                }
                count += ((it.second - 1));
            }
        }
        return count;
    }
};

int main(){
    string s;
    cin >> s;
    Solution obj;
    cout << obj.longestPalindrome(s) << endl;

}