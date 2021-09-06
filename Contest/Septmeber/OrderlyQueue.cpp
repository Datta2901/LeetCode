#include<bits/stdc++.h>
using namespace std;

// Algo
// If k == 1 run over all the possibilities and find the mini string
// if k >= 2 simply sort the string that will be the smallest

class Solution {
public:
    string GetString(string s){
        string answer;
        answer = s[s.size() - 1];
        s.erase(s.end() - 1);
        answer += s;
        return answer;
    }
    string orderlyQueue(string s, int k) {
        string mini = s,a = s;
        if(k == 1){
           for(int i = 0; i < s.size(); i++){
               a = GetString(a);
               //cout << a << endl;
               mini = min(mini,a);
           } 
           return mini;
        }
        sort(s.begin(),s.end());
        return s;
    }
};


int main(){
    Solution obj;
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << obj.orderlyQueue(s,k) << endl;
    return 0;
}