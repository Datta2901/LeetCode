#include<bits/stdc++.h>
using namespace std;



int main(){
    Solution obj;
    vector<int>nums;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int k;
    cin >> k;
    cout << obj.subarraySum(nums,k) << endl;
    return 0;
}