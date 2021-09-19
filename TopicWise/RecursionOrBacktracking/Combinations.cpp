#include<bits/stdc++.h>
using namespace std;

// TODO backtracking problem
class Solution {
public:
    vector<vector<int> > result;
    
    void GeneratePossibleCombinations(int index,int n,vector<int>&current,int k){
        if(current.size() == k){
            result.push_back(current);
            return ;
        }
        for(int i = index; i <= n; i++){
            current.push_back(i);
            GeneratePossibleCombinations(i + 1,n,current,k);
            current.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<int>current;
        GeneratePossibleCombinations(1,n,current,k);
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