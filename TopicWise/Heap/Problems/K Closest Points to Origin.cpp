class Solution {
private:
    double getDistance(vector<int>&dis){
        return sqrt(pow(dis[0],2) + pow(dis[1],2));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int> > answer;
        priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int>> > pq; 
        int m = points.size();
        int n = points[0].size();
        for(int i = 0; i < m; i++){
            double dis = getDistance(points[i]);
            pq.push({dis,i});
            // cout << dis << " " << i << endl;
        }
        int count = 0;
        while(!pq.empty()){
            int s = pq.top().second;
            if(count < K){
                answer.push_back({points[s][0],points[s][1]});
            }
            pq.pop();
            count++;
        }
        return answer;
    }
};
