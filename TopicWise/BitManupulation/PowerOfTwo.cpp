#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0){
            return false;
        }
        if(n == 0){
            return false;
        }
        if((n & n - 1) == 0){
            return true;
        }
        return false;
    }
};

int main(){
    Solution obj;
    int n;
    cin >> n;
    cout << obj.isPowerOfTwo(n) << endl;
    return 0;
}