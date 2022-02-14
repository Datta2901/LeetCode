#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b) {
    int m = a.size();
    int n = b.size();
    if(a == b){
        return n;
    }      
    vector<vector<int> > dp(m + 1,vector<int>(n + 1,0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    int lcs = dp[m][n];
    
    return m + n - lcs;
}

int main(){

    return 0;
}