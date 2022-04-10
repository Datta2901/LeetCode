class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
     int n = mat.size();
     int m = mat[0].size();
        if(r * c != n * m){
            return mat;
        }
      vector<vector<int> > res(r, vector<int>(c));
        vector<int>temp;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            temp.push_back(mat[i][j]);
         }
      }
      int count = 0;
      for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
            res[i][j] = temp[count++];
         }
      }
      return res;
    }
};

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {  
        int m = mat.size();
        int n = mat[0].size();
        int total = m * n;
        if(total != r * c){
            return mat;
        }
        vector<vector<int> > result(r,vector<int>(c,0));
        for(int i = 0; i < total; i++){
            result[i / c][i % c] = mat[i / n][i % n];
        }
        return result;
    }
        
};