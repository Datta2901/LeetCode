vector<vector<int>> solve(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
        
    for(int i = 0; i < m; i++){
        for(int j = 0; j < i; j++){ // diff
            swap(matrix[i][j],matrix[j][i]);
        }
    }   

    // diff
    for(int i = 0; i < m; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}