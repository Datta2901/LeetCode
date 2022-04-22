// O(m*n)
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size();
        int n = arr2.size();
        int answer = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                    break;
                }
                if(j == n - 1){
                    answer++;
                }
            }
        }
        return answer;
    }
};

// O(mlogn)
class Solution {
private:
    bool isValid(vector<int>&arr,int target,int d){
        int size = arr.size();
        int low = 0,high = size - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(abs(arr[mid] - target) <= d){
                return false;
            }else if(arr[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return true;
    }
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size();
        int n = arr2.size();
        int answer = 0;
        sort(arr2.begin(),arr2.end());
        for(int i = 0; i < m; i++){
            if(isValid(arr2,arr1[i],d)){
                answer++;
            }
        }
        return answer;
    }
};