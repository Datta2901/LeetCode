class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        int m = matrix.size();
        int n = matrix[0].size();
        // priority_queue<int>pq;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                pq.push(matrix[i][j]);
                // cout << pq.top() << endl;
            }
        }
        
        int count = 0;
        while(!pq.empty()){
            if(count == m *n - k){
                return pq.top();
            }
            pq.pop();
            count++;
        }
        return 0; 
    }
};