class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > answer;
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int n = intervals.size();
        for(int i = 1; i < n; i++){
            if(start <= intervals[i][0] && intervals[i][0] <= end){
                if(end <= intervals[i][1]){
                    end = intervals[i][1];
                }
            }else{
                answer.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        answer.push_back({start,end});
        return answer;
    }
};