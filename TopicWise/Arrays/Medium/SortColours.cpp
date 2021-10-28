#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int count0 = 0,count1 = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == 0){
                count0++;
            }else if(nums[i] == 1){
                count1++;
            }
        }
        for(int i = 0; i < size; i++){
            if(i < count0){
                nums[i] = 0;
            }else if(i < count0 + count1){
                nums[i] = 1;
            }else{
                nums[i] = 2;
            }
        } 
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
    obj.sortColors(answer);
    for(auto i : answer){
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}