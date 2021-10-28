#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums){
        int count = 0,ele = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                ele = nums[i];
            }if(ele == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        if(count >= 0){
            return ele;
        }
        return -1;
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
    cout << obj.majorityElement(answer) << endl;
    return 0;
}