class Solution {
public:
    bool isPerfectSquare(int num) {
        float a = float(sqrt(num));
        int b = sqrt(num);
        return a == b; 
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1,high = num;
        while(low <= high){
            long long mid = low + ((high - low) / 2);
            long long squared = mid * mid;
            if(squared == num){
                return true;
            }else if(squared < num){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
    //All the squared numbers are written as sum of odd numbers
        int odd = 1;
        while(num > 0){
            num -= odd;
            odd += 2;
            if(num == 0){
                return true;
            }
        }
        return false;
    }
};