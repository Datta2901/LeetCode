class Solution {
private:
    vector<vector<int>> answer;
    // map<vector<int>,int>fre;
    int first;
    void binarySearch(vector<int>&num,int index,int target){
        int n = num.size();
        int low = index + 1,high = n - 1;
        int sum = target;
        while(low < high){
            if(num[low] + num[high] == sum){
                // if(fre[{num[first],num[index],num[low],num[high]}] != 1){
                    answer.push_back({num[first],num[index],num[low],num[high]});
                    // fre[{num[first],num[index],num[low],num[high]}] = 1;
                // }
                // cout << target << " " << num[low] << " " << num[high] << endl;
                while(low < high && num[low] == num[low + 1]){
                    low++;
                }
                while(low < high && num[high] == num[high - 1]){
                    high--;
                }
                low++,high--;
            }else if(num[low] + num[high] < sum){
                low++;
            }else{
                high--;
            }
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
        int n = num.size();
        if(n == 0){
            return answer;
        }
        sort(num.begin(),num.end());
        for(int i = 0; i < n - 2; i++){
            int currentSum = target - num[i];
            for(int j = i + 1; j < n - 2; j++){
                int s = currentSum - num[j];
                first = i;
                binarySearch(num,j,s);
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        }
        return answer; 
    }
};