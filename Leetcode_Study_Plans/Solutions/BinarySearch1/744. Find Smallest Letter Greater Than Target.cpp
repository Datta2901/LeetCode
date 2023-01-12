// O(n)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        for(int i = 0; i < size; i++){
            if(letters[i] > target){
                return letters[i];
            }
        }
        return letters[0];
    }
};

// O(logn)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int size = letters.size();
        int low = 0,high = size - 1;
        int answer = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(letters[mid] > target){
                answer = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return letters[answer];
    }
};