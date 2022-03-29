#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i = 0; i <= n - 2; i++){
            if(nums[i] < nums[i + 1] + nums[i + 2]){
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};

// Check lengths form a valid triangle 

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
    cout << obj.largestPerimeter(num) << endl;
    return 0;
}