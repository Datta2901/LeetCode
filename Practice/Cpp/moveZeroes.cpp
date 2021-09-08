#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // void moveZeroes(vector<int>& nums) {
    //     int n = nums.size(),zero = n - 1,i = n - 1;
    //     for(int i = 0; i < n; i++){
    //         if(nums[i] == 0 && i < zero){
    //             if(zero != i){
    //                 swap(nums[i],nums[zero]);
    //             }
    //             zero--;
    //         }
    //     }
    // }
    class Solution {
    public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0,i = 0,n = nums.size() - 1;
        while(i <= n){
            if(nums[i] != 0){
                nums[pos++] = nums[i];
            }
            i++;
        }

        int zeroes = n - pos;
        while(zeroes >= 0){
            nums[n--] = 0;
            zeroes--;
        }
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
    obj.moveZeroes(num);
    for(int i = 0; i < size; i++){
        cout << num[i] << " ";
    }

    return 0;
}