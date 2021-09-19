#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result = result ^ nums[i];
        }
        return result;
    }
};

int main(){
    Solution obj;
    vector<int>answer;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        answer.push_back(a);
    }
    

    return 0;
}