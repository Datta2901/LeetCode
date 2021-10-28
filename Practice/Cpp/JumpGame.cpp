#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool canJump(vector<int>& nums) {
            int size = nums.size();
            int answer = 0;
            for(int i = 0; i < size; i++){
                answer = max(answer, i + nums[i]);
                if(answer == i){
                    return false;
                }else{
                    if(answer >= size){
                        return true;
                    }
                }
            }
            return true;
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
    cout << obj.canJump(num) << endl;
    return 0;
}