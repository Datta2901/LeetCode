class Solution {
private:
    int m,n;
    vector<int>answer;
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> >  >pq;
        m =  mat.size();
        n = mat[0].size();
        for(int i = 0; i < m; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            pq.push({count,i});
        }
        
        while(!pq.empty()){
            int f = pq.top().first;
            int s = pq.top().second;
            pq.pop();
            if(answer.size() < k){
                answer.push_back(s);
            }
        }
        return answer;
    }
};