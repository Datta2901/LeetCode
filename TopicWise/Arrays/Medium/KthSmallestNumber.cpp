// nlogn
int solve(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    return nums[k];
}

// O(n + k logn)
int solve(vector<int>& nums, int k) {
    make_heap(nums.begin(),nums.end());
    int n = nums.size();
    for(int i = 0; i < n - k - 1; i++){
        pop_heap(nums.begin(),nums.end());
        nums.pop_back();
    }
    return nums.front();
}