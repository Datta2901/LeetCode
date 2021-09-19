#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        for(auto i : matrix){
            for(auto j : i){
                if(j == target){
                    return true;
                }
            }
        }
        return false;
    }
};


int main(){
    Solution obj;
    int size;
    cin >> size;
    vector<vector<int> >num(size);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int a;
            cin >> a;
            num[i].push_back(a);
        }
    }
    int t;
    cin >> t;
    // for(auto it : num){
    //     for(auto i : it){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    cout << obj.searchMatrix(num,t) << endl;
    return 0;
}