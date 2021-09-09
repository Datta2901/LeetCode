#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int> >& mines) {
        vector<vector<int> > answer(n,vector<int>(n,1));
        int m = mines.size();
        for(int i = 0; i < m; i++){
            answer[mines[i][0]][mines[i][1]] = 0;
        }
        
        vector<vector<int> > up = answer,down = answer,right = answer,left = answer;
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                left[i][j] = (left[i][j] == 1) ? left[i][j - 1] + 1 : 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = n - 2; j >= 0 ; j--){
                right[i][j] = (right[i][j] == 1) ? right[i][j + 1] + 1 : 0;
            }
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                up[i][j] = (up[i][j] == 1) ? up[i - 1][j] + 1 : 0;
            }
        }
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                down[i][j] = (down[i][j] == 1) ? down[i + 1][j] + 1 : 0;
            }
        }
        int a = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a = max(a,min({up[i][j],down[i][j],left[i][j],right[i][j]}));
            }
        }        
        return a;
    }
};


int main(){
    Solution obj;
    vector<int>num;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    return 0;
}