#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = 0,answer = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            maxi += nums[i];
            if(maxi > answer){
                answer = maxi;
            }
            if(maxi < 0){
                maxi = 0;
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
    return 0;
}