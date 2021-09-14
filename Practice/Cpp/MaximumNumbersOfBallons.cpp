#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> fre;
        
        for(auto it : text){
            fre[it]++;
        }
        //balloon   
        // a : 1 ,b : 1 ,o : 2,l : 2. n : 1        
        int answer = min({fre['a'],fre['b'] ,fre['l']/ 2,fre['o'] / 2,fre['n']});
        return answer;
    }
};

int main(){
    string s;
    cin >> s;
    Solution obj;
    cout << obj.maxNumberOfBalloons(s) << endl;   
    return 0;
}