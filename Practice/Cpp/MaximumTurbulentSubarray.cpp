#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();
        int inc = 1,dec = 1;
        int answer = 1;
        for(int i = 1; i < size; i++){
            if(arr[i] > arr[i - 1]){
                inc = dec + 1;
                dec = 1;
            }else if(arr[i] < arr[i - 1]){
                dec = inc + 1;
                inc = 1;
            }else{
                inc = 1,dec = 1;
            }
            answer = max({answer,inc,dec});
        }
        return answer;
    }
};

int main(){
    Solution obj;

    return 0;
}