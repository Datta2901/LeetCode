#include<bits/stdc++.h>
using namespace std;
// TODO backtracking problem
class Solution {
public:
    
    vector<string> result;
    
    void permutate(int index,string current, string s){
        if(s.size() == current.size()){
            result.push_back(current);
            return ;
        }
        
        if ('0' <= s[index] && s[index] <= '9'){
            permutate(index + 1,current + s[index],s);
        }else{
            permutate(index + 1,current + (char)(toupper(s[index])),s);
            permutate(index + 1,current + (char)(tolower(s[index])),s);
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        string current = "";
        permutate(0,current,s);
        return result;
    }
};
int main(){
    Solution obj;
    int n,k;
    cin >> n >> k;
    vector<vector<int> > result = obj.combine(n,k);
    for(int i = 0; result.size(); i++){
        for(int j = 0; j < result[0].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}