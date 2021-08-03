#include<bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums) {
    int sum = 0,Original = ((nums.size()) * (nums.size() + 1))/2;
    for(int i = 0; i < nums.size; i++) {
        sum += nums[i];
    }
    cout << Original - sum << endl;
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
    cout << m
    return 0;
}