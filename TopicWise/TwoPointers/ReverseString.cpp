#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(),s.end());
        vector<char>t(s.size(),'a');
        int j = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            t[j++] = s[i];
        }
        s = t; 
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
    }
};

int main(){
    Solution obj;
    vector<int>num;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    return 0;
}