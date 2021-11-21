#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // SC - O(N)
    // TC - O(N2)
    int jump(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int n = nums.size();
        vector<int>dp(n, 0);
        dp[n - 1] = 0;
        for(int i  = n - 2; i >= 0; i--){
            int mini = *min_element(dp.begin() + i + 1,dp.begin() + min(i + nums[i],n - 1) + 1);
            dp[i] = 1 + mini;
        }
        return dp[0];
    }
};

// Greedy
class Solution {
public:
    // SC - O(1)
    // TC - O(N)
    int jump(vector<int>& nums) {
        int n = nums.size();
        int MaximumPossible = 0,end = 0;
        int answer = 0;
        for(int i = 0; i < n - 1; i++){
            MaximumPossible = max(MaximumPossible,i + nums[i]);
            if(i == end){
                answer++;
                end = MaximumPossible;
            }
        }
        return answer;
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
    cout << obj.jump(num) << endl;
    return 0;
}