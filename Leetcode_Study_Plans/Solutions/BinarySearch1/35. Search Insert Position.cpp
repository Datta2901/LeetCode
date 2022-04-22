class Solution {
public:
    int binarySearch(vector<int>& nums,int target){
        int size = nums.size();
        int low = 0,high = size - 1;
        int answer = 0;
        while(low <= high){
            int mid = low + (high - low) / 2; 
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                answer = mid;
                high = mid - 1;
            }else{
                answer = mid + 1;
                low = mid + 1;
            }
        }
        return answer;
    }
    int searchInsert(vector<int>& nums, int target) {
        int answer = binarySearch(nums,target);
        return answer; 
    }
};