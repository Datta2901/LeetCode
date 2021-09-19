#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int firstUniqChar(string s) {
            map<char,int>fre;
            for(auto i : s){
                fre[i]++;
            }
            int count = 0;
            for(auto i : s){
                // cout << i.first  << " " << i.second << endl;
                if(fre[i] == 1){
                    return count;
                }
                count++;
            }
            return -1;
        }
};



int main(){
    Solution obj;
    string s;
    cin >> s;
    cout << obj.firstUniqChar(s) << endl;
    return 0;
}