#include<bits/stdc++.h>
using namespace std;
int n;
int wt;
vector<int>nums;
vector<int>profit;

int knapsackRecursive(int i,int weight,vector<vector<int> > &dp){
    if(weight > wt){
        return INT_MIN;
    }
    if(i == n){
        return 0;
    }
    if(dp[i][weight] != -1){
        return dp[i][weight];
    }
    int pick = profit[i] + knapsackRecursive(i + 1,weight + nums[i],dp);
    int notpick = knapsackRecursive(i + 1,weight,dp);
    return dp[i][weight] = max(pick,notpick);
}

int main(){
    cin >> wt >> n;
    vector<vector<int> >dp(n,vector<int>(wt + 1,-1));
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        nums.push_back(a);
        profit.push_back(b);
    }
    cout << knapsackRecursive(0,0,dp) << endl;
    return 0;
}
