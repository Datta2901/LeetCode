#include<bits/stdc++.h>
using namespace std;



class Solution1 {
public:
    // Using kadanes Algorithm 
    // SC - O(1)
    // TC - O(N)
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int answer = INT_MIN;
        for(int i = 0; i < n; i++){
            int count = i + 1;
            int j = i;
            int maxUpto = 0;
            while(count != i){
                maxUpto += nums[j];
                if(maxUpto > answer){
                    answer = maxUpto; 
                }
                if(maxUpto < 0){
                    maxUpto = 0;
                }
                j++;
                j = j % n;
                count = j;
            }
        }
        return answer;
    }
};



class Solution{
// Using inversion technique
private: 
    int kadanesAlgorithm(vector<int>nums){
        int n = nums.size(),sum = 0;
        int maxUpto = 0,answer = INT_MIN;
        for(int i = 0; i < n; i++){
            maxUpto += nums[i];
            if(answer < maxUpto){
                answer = maxUpto;
            }if(maxUpto < 0){
                maxUpto = 0;
            }
        } 
        return answer;
    }
public:
    // Using kadanes Algorithm 
    // SC - O(1)
    // TC - O(N)
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(),sum = 0;
        int answer = kadanesAlgorithm(nums);
        bool control =false;
        for(int i = 0; i < n; i++){
            nums[i] *= -1;
            sum += nums[i];
        }
        int answer2 = (-1 * sum) - (-1 * kadanesAlgorithm(nums));
        if(max(answer,answer2) == 0){
            return -1 * (*min_element(nums.begin(),nums.end()));
        }
        return max(answer,answer2); 
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
    cout << obj.maxSubarraySumCircular(num) << endl;
    return 0;
}