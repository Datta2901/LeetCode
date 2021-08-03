#include<bits/stdc++.h>
using namespace std;


int reverse(int x){
    int answer = 0,a = x;
    if(a < 0){
        x = -1 * x;
    }
    while(x > 0){
        answer = 10 * answer + (x % 10);
        x /= 10;
    }
    if(a < 0){
        answer = -1 * answer;
    }
    return answer;
}


int main(){
    int num;
    cin >> num;
    cout << reverse(num) << endl;

    return 0;
}