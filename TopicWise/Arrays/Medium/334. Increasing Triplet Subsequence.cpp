#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX,second = INT_MAX;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(first >= nums[i]){
                first = nums[i];
            }else if(second >= nums[i]){
                second = nums[i];
            }else if(second < nums[i]){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution obj;
    int size;
    cin >> size;
    vector<vector<int> >num(size);
    for(int i = 0; i < size; i++){
        int a,b;
        cin >> a >> b;
        num.push_back({a,b});
    }
    cout << obj.increasingTriplet(num) << endl;
    return 0;
}