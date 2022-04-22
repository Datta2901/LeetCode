class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto maxi = max_element(arr.begin(),arr.end());
        return maxi-arr.begin();
    }
};


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int size = nums.size();
        int low = 0,high = size - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < nums[mid + 1]){
                low  = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};


