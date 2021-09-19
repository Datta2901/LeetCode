#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        if(n == 1){
            return dp[0];
        }
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};

int main(){
    Solution obj;
    int size;
    cin >> size;
    vector<int> numbers;
    for(int i  = 0; i < size; i++){
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    cout << obj.rob(numbers) << endl;
    return 0;
}