/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
// O(logn)
class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int answer = guess(mid);
            if(answer == -1){
                high = mid - 1;
            } else if(answer == 0){
                return mid;
            }else{
                low = mid + 1;
            }
        }
        return 0;
    }
};