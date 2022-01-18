class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>answer;
        priority_queue<pair<int,int> > pq;
        map<int,int>fre;
        for(auto it : nums){
            fre[it]++;
        }
        for(auto it : fre){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            if(answer.size() < k){
                answer.push_back(pq.top().second);
            }
            pq.pop();
        }
        return answer;
    }
};