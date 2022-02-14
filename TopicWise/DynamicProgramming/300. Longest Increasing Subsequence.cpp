// Recursion
class Solution {
    int getAnswer(int i,vector<int>&nums){
        int pick = 1;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                pick = max(pick,1 + getAnswer(j,nums));
            }
        }
        return pick;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans,getAnswer(i,nums));
        }
        return ans;
    }
};

// Memoization
class Solution {
    int getAnswer(int i,vector<int>&nums,vector<int>&dp){
        int pick = 1;
        if(dp[i] != -1){
            return dp[i];
        }
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                pick = max(pick,1 + getAnswer(j,nums,dp));
            }
        }
        return dp[i] = pick;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        vector<int>dp(n,-1);
        for(int i = 0; i < n; i++){
            ans = max(ans,getAnswer(i,nums,dp));
        }
        return ans;
    }
};