#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums,int target){
        int low = 0,high = nums.size() - 1,answer= -1;
        while(low <= high){
            int mid = (low + high) /2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                answer= mid;
                high = mid - 1;
            }else{
                answer = mid + 1;
                low = mid + 1;
            }
        }
        return answer;
    }
    int searchInsert(vector<int>& nums, int target) {
        int answer = binarySearch(nums,target);
        return answer; 
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
    int t;
    cin >> t;
    cout << obj.searchInsert(num,t) << endl;
    return 0;
}