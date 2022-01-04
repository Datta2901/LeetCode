#include<bits/stdc++.h>
using namespace std;

// Logic:
// Traverse from the back of the array
// keep track of the maximum element on the right side
// now take the maximum for prices[i],prices[i - 1]
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int answer = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] > prices[i - 1]){
                answer += prices[i] - prices[i - 1];
            }
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
    cout << obj.maxProfit(num) << endl;

    return 0;
}