class Solution {
public:
    int furthestBuilding(vector<int>& height, int bricks, int ladders) {
        int n = height.size();
        priority_queue<int>pq;
        for(int i = 1; i < n; i++){
            int diff = height[i] - height[i - 1];
            if(diff > 0){
                pq.push(diff);
                bricks -= diff;
                if(bricks < 0){
                    ladders -= 1;
                    bricks += pq.top();
                    pq.pop();
                    if(ladders < 0 || bricks < 0){
                        return i - 1;
                    }
                }
            }
        }
        return n - 1;
    }
};