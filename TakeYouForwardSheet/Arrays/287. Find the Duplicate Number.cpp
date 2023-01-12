class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[abs(arr[i])] > 0){
                arr[abs(arr[i])] = -1 * arr[abs(arr[i])]; 
            }else{
                return abs(arr[i]);
            }
        }
        return -1;
    }
};

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


