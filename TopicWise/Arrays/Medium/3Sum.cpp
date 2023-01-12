#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& num) {
        vector<vector<int> > res; 
        sort(num.begin(), num.end()); 
        for (int i = 0; i < (int)(num.size())-2; i++) {  
            if (i == 0 || (i > 0 && num[i] != num[i-1])) {  
                int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {  
                        vector<int> temp; 
                        temp.push_back(num[i]); 
                        temp.push_back(num[lo]); 
                        temp.push_back(num[hi]); 
                        res.push_back(temp);
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;  
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            }
        }
        return res;
    }
};

// class Solution {
// private:
//     vector<vector<int>> answer;
//     void binarySearch(vector<int>&num,int index){
//         int n = num.size();
//         int low = index + 1,high = n - 1;
//         int sum = 0 - num[index];
//         //low,high are two more pointers         
//         while(low < high){
//             if(num[low] + num[high] == sum){
//                 answer.push_back({num[low],num[high],num[index]});
//                 while(low < high && num[low] == num[low + 1]){
//                     low++;
//                 }
//                 while(low < high && num[high] == num[high - 1]){
//                     high--;
//                 }
//                 low++,high--;
//             }else if(num[low] + num[high] < sum){
//                 low++;
//             }else{
//                 high--;
//             }
//         }
//     }
// public:
//     vector<vector<int>> threeSum(vector<int>& num) {
//         //Using three pointers
//         int n = num.size();
//         if(n == 0){
//             return answer;
//         }
//         sort(num.begin(),num.end());
//         for(int i = 0; i < n - 2; i++){
//             // i - one pointer             
//             if(i == 0 || (num[i] != num[i - 1])){
//                 // doing binary search on other side
//                 // We have to avoid duplicates 
//                 binarySearch(num,i);
//             }
//         }
//         return answer;
//     }
// };


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
    vector<vector<int> > answer =  obj.threeSum(answer);
    for(auto it : answer){
        for(auto j : it){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}