#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        int maximum = *max_element(nums.begin(),nums.end());
        vector<int>answer(maximum + 1,0);
        for(int i = 0; i < nums.size(); i++){
            answer[nums[i]] = nums[i];
        }
        for(int i = 0; i < size; i++){
            if(answer[abs(nums[i])] >= 0){
                answer[i] *= -1;
            }else{
                return true;
            }
        }
        return false;
    }
};
// by using sorting
// we can use set,unordered map
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for(int i = 0; i < n-1; i++)
//             if(nums[i] == nums[i+1])
//                 return true;
//         return false;
//     }
// };

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
    cout << obj.containsDuplicate(num) << endl;
    return 0;
}