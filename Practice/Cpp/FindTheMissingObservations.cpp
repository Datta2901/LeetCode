#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
            int sum = 0;
            int m = rolls.size();
            for(int i = 0; i < m; i++){
                sum += rolls[i];
            }
        
            int Sum_n = (mean * (m + n) - sum);
            vector<int> answer(n,1);
            int s = n;
            if(Sum_n - s == 0){
                return answer;
            }if(Sum_n < s){
                return {};
            }
            for(int i = 0; i < n; i++){
                if(Sum_n - s >= 5){
                    s += 5;
                    answer[i] += 5;
                }else{    
                    answer[i] += Sum_n - s;
                    s  = Sum_n ;
                }
                if(s == Sum_n){
                    break;
                }
            }
            if(s == Sum_n){
                return answer;
            }
            return {};
        }
};
int main(){
    Solution obj;
    int m;
    cin >> m;
    vector<int> mobs;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        mobs.push_back(a);
    }

    int mean,n;
    cin >> mean >> n;
    vector<int> answer = obj.missingRolls(mobs,mean,n);
    if(answer.size() != n){
        return 0;
    }
    for(int i = 0; i < n; i++){
        cout << answer[i] << " ";
    } 
    return 0;
}