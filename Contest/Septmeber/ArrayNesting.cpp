#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);
        int answer = 0,count;
        for(int i = 0; i < n; i++){
            count = 1;
            if(!visited[i]){
                visited[i] = true;
                int index = i,startIndex = i;
                while(nums[startIndex] != index){
                    startIndex = nums[startIndex];
                    count++;
                    visited[startIndex] = true;
                }
            }
            answer = max(count,answer);
        }
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
    cout << obj.arrayNesting(num) << endl;
    return 0;
}