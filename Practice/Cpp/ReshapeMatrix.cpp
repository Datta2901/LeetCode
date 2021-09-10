#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& mat, int r, int c) {
        
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

int main(){
    Solution obj;
    vector<vector<int> > num;
    int m,n;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
             int a;
            cin >> a;
            num[i].push_back(a);
        }
    }
    int r,c;
    cin >> r >> c;
    vector<vector<int> > answer = obj.matrixReshape(num,r,c);
    for(auto i : answer){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}