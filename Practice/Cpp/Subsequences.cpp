#include<bits/stdc++.h>
using namespace std;

// The order of the array should be the same
vector<vector<int>>answer;

// Printing all the subsequences
void getAnswer(int arr[],int i,int n,vector<int>&ds){
    if(i == n){
        answer.push_back(ds);
        return;
    }

    //  include
    ds.push_back(arr[i]);
    getAnswer(arr,i + 1,n,ds);
    ds.pop_back();

    // Not include
    getAnswer(arr,i + 1,n,ds);
}

// Subsequences whose sum is k
// One number should present in the subsequence only one time
// Eg : {1,2,3} k = 4
// Answer is {1,3}
void subWithSumK(int arr[],int n,int i,int sum,vector<int>&ds,int k){
    if(i == n){
        if(sum == k){
            answer.push_back(ds);
        }
        return;
    }
    // pick
    ds.push_back(arr[i]);
    subWithSumK(arr,n,i + 1,sum + arr[i],ds,k);
    ds.pop_back();

    // not pick
    subWithSumK(arr,n, i + 1,sum,ds,k);
}

// Combination I Leetcode
// Subsequence with sum k 
// Where one number can present any number of times
// Eg : [2,3,6,7], k = 7
// Output: {2,2,3},{7}
class Solution{
public:
    vector<vector<int> > answer;
    
    void subWithSumK(vector<int> &arr,int n,int i,int sum,vector<int>&ds,int k){
        if(i == n){
            if(sum == k){
                answer.push_back(ds);
            }
            return;
        }
        // pick
        if(arr[i] + sum <= k){
            ds.push_back(arr[i]);
            subWithSumK(arr,n,i,sum + arr[i],ds,k);
            ds.pop_back();
        }

        // not pick
        subWithSumK(arr,n, i + 1,sum,ds,k);
    }
     
    vector<vector<int> > combinationSum(vector<int>& nums,int k){
        vector<int>ds;
        subWithSumK(nums,nums.size(),0,0,ds,k);
        return answer;
    }
};

// Combination 2
// Array contains the duplicate elements
// Answer should not contain any duplicate subsequences

// class Solution {
//     vector<vector<int> > answer;
//     set<vector<int> > order;
//     void subWithSumK(vector<int> &arr,int n,int i,int sum,vector<int>&ds,int k){
//         if(i == n){
//             if(sum == k){
//                 order.insert(ds);
//             }
//             return;
//         }
//         // pick
//         if(arr[i] + sum <= k){
//             ds.push_back(arr[i]);
//             subWithSumK(arr,n,i + 1,sum + arr[i],ds,k);
//             ds.pop_back();
//         }

//         // not pick
//         subWithSumK(arr,n, i + 1,sum,ds,k);
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<int>ds;
//         sort(candidates.begin(),candidates.end());
//         subWithSumK(candidates,candidates.size(),0,0,ds,target);
//         for(auto it : order){
//             answer.push_back(it);
//         }
//         return answer;
//     }
// };


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int>ds;
    // getAnswer(arr,0,n,ds);
    // for(auto it : answer){
    //     if(it.size() == 0){
    //         cout << "{}";
    //     }
    //     for(auto i : it){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    int k;
    cin >> k;

    subWithSumK(arr,n,0,0,ds,k);
    for(auto it : answer){
        if(it.size() == 0){
            cout << "{}";
        }
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}