#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size(),min = 0;
        for(int i = n - 1; i > 0 ; i--){
            releaseTimes[i] = releaseTimes[i] - releaseTimes[i - 1];
        }
        // for(int i = 0; i < n; i++){
        //     cout << releaseTimes[i] << " ";
        // }
        // cout << endl;
        for(int i = 0; i < n; i++){
            if(releaseTimes[i] > releaseTimes[min]){
                    min = i;
            }else if(releaseTimes[i] == releaseTimes[min]){
                if(keysPressed[min] < keysPressed[i]){
                    min = i;
                }
            }
        }
        return keysPressed[min];
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
    string a;
    cin >> a;
    cout << obj.slowestKey(num,a) << endl;
    return 0;
}