class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        int answer = 1;
        int count;
        if(n == 0){
            return 0;
        }
        unordered_map<int,int> fre;
        for(int i = 0; i < n; i++){
            fre[nums[i]] = 1;
        }
        for(int i = 0; i < n; i++){
            if(fre[nums[i] - 1] == 0){
                count = 1;
                int current = nums[i];
                while(fre[current + 1] != 0){
                    current++;
                    count++;
                }
                answer = max(answer,count);
            }
        }
        return answer;
    }
};