class Solution {
    int getAnswer(int i,vector<int>&coins,int amount){
        if(i == coins.size()){
            return INT_MAX - 1;
        }
        if(amount == 0){
            return 0;
        }
        
        int pick = INT_MAX,notPick = INT_MAX;
        if(coins[i] <= amount){
            pick = 1 + getAnswer(i,coins,amount-coins[i]);
        }
        notPick = getAnswer(i + 1,coins,amount);
        return min(pick,notPick); 
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int answer = getAnswer(0,coins,amount);
        if(answer == INT_MAX || answer == INT_MAX -1){
            return -1;
        }
        return answer;
    }
};


// Memoization
class Solution {
    int getAnswer(int i,vector<int>&coins,int amount,vector<vector<int> > &dp){
        if(i == coins.size()){
            return INT_MAX - 1;
        }
        if(amount == 0){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        
        int pick = INT_MAX,notPick = INT_MAX;
        if(coins[i] <= amount){
            pick = 1 + getAnswer(i,coins,amount-coins[i],dp);
        }
        notPick = getAnswer(i + 1,coins,amount,dp);
        return dp[i][amount] = min(pick,notPick); 
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int> > dp(coins.size(),vector<int>(amount + 1,-1));
        int answer = getAnswer(0,coins,amount,dp);
        if(answer == INT_MAX || answer == INT_MAX -1){
            return -1;
        }
        return answer;
    }
};

