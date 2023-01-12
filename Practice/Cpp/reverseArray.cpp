#include<bits/stdc++.h>
using namespace std;

void reverseArray(int n,int arr[],int l, int r){
    if(l >= r){
        return;
    }
    swap(arr[l],arr[r]);
    l++;
    r--;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    reverseArray(n,arr,0,n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}