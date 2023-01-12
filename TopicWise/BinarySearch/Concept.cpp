#include<bits/stdc++.h>
using namespace std;

int findFirstOccurrence(vector<int>&nums,int target){
    int low = 0,high = nums.size() - 1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            ans = mid;
            high = mid - 1;
        }else if(nums[mid] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int LastOccurrence(vector<int>&nums,int target){
    int low = 0,high = nums.size() - 1;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid] == target){
            ans = mid;
            low = mid + 1;
        }else if(nums[mid] > target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    } 
    return ans;
}


int Sqrtn(int n){
    int low = 1,high = n;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mid * mid <= n){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int CubeRoot(int n){
    int low = 1,high = n;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mid * mid * mid <= n){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int size;
    cin >> size;
    // vector<int>nums;
    // for(int i = 0; i < size; i++){
    //     int a;
    //     cin >> a;
    //     nums.push_back(a);
    // }
    // int target;
    // cin >> target;
    // cout << findFirstOccurrence(nums,target) << endl;
    // cout << LastOccurrence(nums,target) << endl;
    // cout << Sqrtn(size) << endl;

    cout << CubeRoot(size);

    return 0;
}