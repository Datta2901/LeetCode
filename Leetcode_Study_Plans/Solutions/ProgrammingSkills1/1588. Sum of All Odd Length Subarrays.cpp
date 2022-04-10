class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int answer = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if((j - i + 1) % 2 == 1){
                    answer += accumulate(arr.begin() + i, arr.begin() + j + 1,0);
                }
            }
        }
        return answer;
    }
};