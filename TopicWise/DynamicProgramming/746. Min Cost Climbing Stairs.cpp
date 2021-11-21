#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1){
            return cost[0];
        }
        if(n == 2){
            return min(cost[0],cost[1]);
        }
        vector<int>dp(n,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i - 1],dp[i - 2]);
        }
        return min(dp[n - 1],dp[n - 2]);
    }
};

int main(){
    Solution obj;
    int n;
    cin >> n;
    cout << obj.climbStairs(n) << endl;
    return 0;
}