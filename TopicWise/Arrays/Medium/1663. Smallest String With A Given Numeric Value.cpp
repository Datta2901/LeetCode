#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string answer = "";
        int i  = 26;
        while(k > 0 && i >= 1){ 
            while(k - i >= 0){
                if((k - i) + answer.size() + 1 >= n){
                    answer += 'a' + i - 1;
                    k -= i;
                }else{
                    break;
                }
            }
            i--;
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};


// class Solution {
// public:
//     string getSmallestString(int n, int k) {
//         string answer = "";
//         for(int i = n; i > 0; i--){     
//             int remaining = k - (i - 1);       
//             if(remaining >= 26){
//                 answer += 'z';
//                 k -= 26;
//             }else{
//                 answer += 'a' + remaining - 1;
//                 k -= remaining;
//             }
//         }
//         reverse(answer.begin(),answer.end());
//         return answer;
//     }
// };




int main(){
    Solution obj;
    int n,k;
    cin >> n >> k;
    cout << obj.getSmallestString(n,k) << endl;
    
    return 0;
}