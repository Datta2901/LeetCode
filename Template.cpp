#include<bits/stdc++.h>
using namespace std;

// bool isPalindrome(int x) {
//     string a = to_string(x);
//     string b = a;
//     reverse(a.begin(),a.end());
//     if(a == b){
//         return true;
//     }
//     return false;
// }

// This overflows when we are reversing the number
// int Reverse(int x){
//     int rev = 0;
//     while(x){
//         rev = rev * 10 + x % 10;
//         x /= 10;
//     }
//     // cout << rev << endl;
//     return rev;  
// }

class Solution {
public:
     bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x > sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};

bool isPalindrome(int x){
    int rev = Reverse(x);
    if(x == rev){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    cout << isPalindrome(n) << endl;
    return 0;
}