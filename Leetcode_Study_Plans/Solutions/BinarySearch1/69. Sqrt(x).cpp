class Solution {
public:
    int mySqrt(int num) {
        int low = 1,high = num;
        while(low <= high){
            long long mid = low + ((high - low) / 2);
            long long squared = mid * mid;
            if(squared == num){
                return mid;
            }else if(squared < num){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low - 1;
    }
};