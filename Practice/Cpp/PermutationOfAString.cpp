#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        int s1len = s1.size();
        int s2len = s2.size();
        if(s1len>s2len)
            return false;
        
        int left=0,right=0;
        while(right<s1len)
        {
            s1hash[s1[right]-'a'] +=1;
            s2hash[s2[right]-'a'] +=1;
            right +=1;
        }
        right -=1;
        while(right<s2len)
        {
            if(s1hash==s2hash)
                return true;
            right+=1;
            if(right!=s2len)
                s2hash[s2[right]-'a'] +=1;
            s2hash[s2[left]-'a'] -=1;
            left +=1;
        }
        return false;
    }
};

#include<string>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        string rev = s1;
        reverse(s1.begin(),s1.end());
        size_t found = s2.find(s1);
        cout << s1 << " " << rev;
        if (found != string::npos){
            return true;
        }
        found = s2.find(rev);
        if (found != string::npos){
            return true;
        }
        return false;
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