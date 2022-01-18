class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>store;
        for(int i = 0; i < n; i++){
            store.push(stones[i]);
        }
        while(!store.empty()){
            int f = store.top();
            int s;
            store.pop();
            if(!store.empty()){
                s = store.top();
                store.pop();
            }else{
                return f;
            }
            
            if(f - s == 0){
                continue;
            }
            store.push(f - s);
        }
        return 0;
    }
};