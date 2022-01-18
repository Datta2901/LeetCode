// TC - O(klogn)
// SC - O(n)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        for(int i=1;i<k;++i) 
            pq.pop();
        return pq.top();
    }
};


// TC - O(nlogk)
// SC - O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }else if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
            cout << pq.top() << " ";
        }
        return pq.top();
    }
};