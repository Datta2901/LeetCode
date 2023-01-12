class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int answer = INT_MIN,maxRight = INT_MIN;
       int n = prices.size();
        for(int i = n - 1; i >= 0; i--){
            maxRight = max(maxRight,prices[i]);
            answer = max(answer,maxRight - prices[i]);
        }
        return answer;
    }
};