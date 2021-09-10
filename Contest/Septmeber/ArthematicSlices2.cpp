#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // dp[i][diff] = dp[j][diff] + 1       
        unordered_map<long long int,long long int> fre;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                long long int diff = nums[i]*1l - nums[j]*1l;
                long long int uniqueNum1 = 2000 * diff + i;
                long long int uniqueNum2 = 2000 * diff + j;
                fre[uniqueNum1] += fre[uniqueNum2] + 1;
            }
        }
        // answer contains all the possible subsets
        long long answer = 0;
        // for(auto it : fre){
        //     answer += it.second;
        // }
        for(auto it = fre.begin(); it != fre.end(); it++){
            answer += it->second;
        }
        //so we have to remove the subsets having the size 2
        return int(answer - n * (n - 1) / 2);

    }
};

int main(){

    
    return 0;
}