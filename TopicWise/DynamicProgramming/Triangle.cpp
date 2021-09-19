#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
         int n = tri.size();
         for(int i = 1; i < tri.size(); i++){
             for(int j = 0; j < tri[i].size(); j++){
                if(j == 0){ 
                    tri[i][j] = tri[i-1][j] + tri[i][j];
                }else if(j == tri[i].size() - 1){
                    tri[i][j] = tri[i-1][j-1] + tri[i][j];
                }else{
                    tri[i][j] = min( tri[i-1][j-1], tri[i-1][j]) + tri[i][j];
                 }
             }
              
         }
        return *min_element(tri[n-1].begin(),tri[n-1].end());    
    }
};

int main(){
    Solution obj;
    int size;
    cin >> size;
    vector<int> numbers;
    for(int i  = 0; i < size; i++){
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    cout << obj.minimumTotal(numbers) << endl;
    return 0;
}