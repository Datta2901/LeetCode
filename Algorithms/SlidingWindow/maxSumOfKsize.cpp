#include<bits/stdc++.h>
using namespace std;

int getAnswer(vector<int>&nums,int k){
    int answer = INT_MIN;
    int i = 0,j = 0,sum = 0;
    int size = nums.size();
    while(j < size){
        sum += nums[j];
        if(j - i + 1 == k){
            answer = max(answer,sum);
            sum -= nums[i];
            i++; 
        }
        j++;
    }
    return answer;
}

int main(){
    int n;
    cin >> n;
    vector<int>nums;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int k;
    cin >> k;
    cout << getAnswer(nums,k) << endl;
    return 0;
}