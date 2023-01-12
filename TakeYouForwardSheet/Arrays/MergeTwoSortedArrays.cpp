class Solution1 {
public:
    // Time complexity is O((n + m )logn)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++){
            nums1[m  + i] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};

class Solution2 {
public:
    // Time Complexity - O(m * n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while(i < m){
            if(nums1[i] > nums2[j]){
                swap(nums1[i],nums2[j]);
                int k = 0;
                while(k < n - 1){
                    if(nums2[k] > nums2[k + 1]){
                        swap(nums2[k],nums2[k + 1]);
                    }
                    k++;
                }
            }
            i++;
        }
        // our final answer is nums1 + nums2;
        for(int i = 0; i < m; i++){
                cout << nums1[i] << " ";
        }
        for(int i = 0; i < n; i++){
                cout << nums2[i] << " ";
        }
    }
};

// Gap Method
class Solution {
private:
    int m,n;
    bool isValid(int j){
        if(j >= m + n){
            return false;
        }
        return true;
    }
public:
    // Time Complexity - O(nlogn)
    void merge(vector<int>& nums1, int a, vector<int>& nums2, int b) {
        m = a;
        n = b;
        int gap = (m + n ) / 2;
        while(gap != 0){
            int i = 0,j = gap ;
            while(isValid(j)){
                if(i < m && j < m){
                    if(nums1[i] > nums1[j]){
                        swap(nums1[i],nums1[j]);
                    }
                }
                else if(i < m && j < m + n){ 
                    if(nums1[i] > nums2[j - m]){
                        swap(nums1[i],nums2[j - m]);
                    }
                }else if(i < m + n && j < m + n){
                    if(nums2[i - m] > nums2[j - m]){
                        swap(nums2[i - m],nums2[j - m]);
                    }
                }
                i++;
                j++;
            }
            if(gap <= 1){
                gap = 0;
            }
            gap = gap / 2 +( gap % 2);
        }
    }
};