#include<bits/stdc++.h>
using namespace std;

// Tortoise method
class solution{
public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0];
        int fast = arr[0];
        do{
            slow = arr[slow];
            fast = arr[arr[fast]];
        }while(fast != slow);

        fast = arr[0];
        
        while(slow != fast){
            slow = arr[slow];
            fast = arr[fast];
        }
        return fast;
    }
};  

int main(){
    solution obj;
    int size;
    cin >> size;
    vector<int> nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cout << obj.findDuplicate(nums) << endl;
    return 0;
}