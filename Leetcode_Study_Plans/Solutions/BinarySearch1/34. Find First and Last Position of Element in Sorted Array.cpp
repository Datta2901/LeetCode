class Solution {
    int findFirstOccurence(vector<int>&nums,int target){
        int size = nums.size();
        int low = 0,high = size - 1;
        int answer = -1;
        while(low <= high){
            int mid = low +(high - low) / 2;
            if(nums[mid] >= target){
                if(nums[mid] == target){
                    answer = mid;
                }
                high = mid - 1; 
            }else{
                low = mid + 1;
            }
        }
        return answer;
    }
    
    int findLastOccurence(vector<int>&nums,int target){
        int size = nums.size();
        int low = 0,high = size - 1;
        int answer = -1;
        while(low <= high){
            int mid = low +(high - low) / 2;
            if(nums[mid] <= target){
                if(nums[mid] == target){
                    answer = mid;
                }
                low = mid + 1; 
            }else{
                high = mid - 1;
            }
        }
        return answer;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>answer(2,0);
        answer[0] = findFirstOccurence(nums,target);
        answer[1] = findLastOccurence(nums,target);
        return answer;
    }
};


// modular
class Solution {
    int findFirstOccurence(vector<int>&nums,int target){
        int size = nums.size();
        int low = 0,high = size - 1;
        int answer = -1;
        while(low <= high){
            int mid = low +(high - low) / 2;
            if(nums[mid] == target){
                answer = mid;
                high = mid - 1;
            }else if(nums[mid] > target){
                high = mid - 1; 
            }else{
                low = mid + 1;
            }
        }
        return answer;
    }
    
    int findLastOccurence(vector<int>&nums,int target){
        int size = nums.size();
        int low = 0,high = size - 1;
        int answer = -1;
        while(low <= high){
            int mid = low +(high - low) / 2;
            if(nums[mid] == target){
                answer = mid;
                low = mid + 1;
            }else if(nums[mid] < target){
                low = mid + 1; 
            }else{
                high = mid - 1;
            }
        }
        return answer;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>answer(2,0);
        answer[0] = findFirstOccurence(nums,target);
        answer[1] = findLastOccurence(nums,target);
        return answer;
    }
};