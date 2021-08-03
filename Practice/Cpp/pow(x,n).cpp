#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    double answer = pow(x,n);
    return answer;
}

int main(){
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x,n);
    return 0;
}