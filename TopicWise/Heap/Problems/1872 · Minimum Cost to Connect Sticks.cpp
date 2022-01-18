class Solution {
public:
    /**
     * @param sticks: the length of sticks
     * @return: Minimum Cost to Connect Sticks
     */
    int MinimumCost(vector<int> &sticks) {
        // write your code here
        priority_queue<int,vector<int>,greater<int> > pq;
        for(auto it : sticks){
            pq.push(it);
        }
        int answer = 0;
        while(!pq.empty()){
            if(pq.size() == 1){
                // cout << pq.top() << endl;
                // answer += pq.top();
                return answer;
            }
            int x = pq.top();
            // cout << x << " ";
            pq.pop();
            if(!pq.empty()){
                int y = pq.top();
                // cout << y << endl;
                answer += (x + y);
                pq.pop();
                pq.push(x + y);
            }
        }
        return -1;
    }
};