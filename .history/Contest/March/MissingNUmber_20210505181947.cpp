#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {
    int sum = 0,Original = nums.size() * nums.size() + 1);
    for(int i = 0; i < nums.size; i++) {
        sum += nums[i];
    }

}

int main(){
    int n;
    cin >> n;
    vector<int>numbers;
    for(int i  = 0; i < n; i++){
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    return 0;
}