// nlogn
vector<int> solve(vector<int>& nums) {
    vector<int>answer;
    for(auto it : nums){
        answer.push_back(it * it);
    }
    sort(answer.begin(),answer.end());
    return answer;
}

// optimize solution
// O(n)
vector<int> solve(vector<int>& nums) {
    vector<int>answer;
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    while(i <= j){
        int start = nums[i];
        int end = nums[j];
        if(start * start >= end * end){
            answer.push_back(start*start);
            i++;
        }else{
            answer.push_back(end*end);
            j--;
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}