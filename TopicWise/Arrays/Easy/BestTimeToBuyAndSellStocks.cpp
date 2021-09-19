#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxRight = INT_MIN,profit = 0;
        for(int i = prices.size() - 1; i >= 0; i--){
            maxRight = max(maxRight,prices[i]);
            profit = max(profit,maxRight - prices[i]);
        }
        return profit;
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