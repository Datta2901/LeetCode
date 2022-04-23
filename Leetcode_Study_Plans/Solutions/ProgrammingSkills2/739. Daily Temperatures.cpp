class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>track;
        vector<int>answer(temperatures.size(),0);
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!track.empty() && temperatures[track.top()] <= temperatures[i]){
                track.pop();
            }
            if(track.empty()){
                answer[i] = 0;
            }else{
                answer[i] = track.top() - i;
            }
            track.push(i);
        }
        return answer;
    }
};