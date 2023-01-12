int getAnswer(int k,vector<int>&nums){
    int n = nums.size();
    int i = 0; 
    unordered_map<int,int>fre;
    int answer = 0;
    for(int j = 0; j < n; j++){ 
        fre[nums[j]]++;
        while(fre.size() > k){
            fre[nums[i]] -= 1;
            if(fre[nums[i]] == 0){
                fre.erase(nums[i]);
            }
            i++;
        }
        answer = max((j - i + 1),answer);
    }
    return answer;
}

int solve(int k, vector<int>& nums) {
    return getAnswer(k,nums);
}