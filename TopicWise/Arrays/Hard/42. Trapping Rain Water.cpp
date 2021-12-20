#include<bits/stdc++.h>
using namespace std;


// Approach : min(MaxHeightOnLeft,MaxHeightOnRight)

// Brute Force
// TC : O(N2)
// SC : O(1)
class Solution1{
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int answer = 0;
        for(int i = 1; i < n - 1; i++){
            int water = min(*max_element(height.begin(),height.begin() + i),*max_element(height.begin() + i + 1,height.end()));
            int diff = (water - height[i]  > 0);
            answer += (diff > 0)  ? diff : 0;
            // cout << i << " -> " << water << " "  << height[i] << endl;
        }
        return answer;
    }
};


// Better one
// computing max on right and left side for every index 
// TC - O(N)
// SC - O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int answer = 0;
        vector<int>prefixMax(n,0),SuffixMax(n,0);
        prefixMax[0] = height[0];
        SuffixMax[n - 1] = height[n - 1]; 
        for(int i = 1; i < n; i++){
            prefixMax[i] =  max(prefixMax[i - 1],height[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            SuffixMax[i] = max(SuffixMax[i + 1],height[i]);
        }

        for(int i = 1; i < n - 1; i++){
            int water = min(prefixMax[i],SuffixMax[i]);
            int diff = water - height[i];
            answer += (diff > 0) ? diff : 0;
        }

        return answer;
    }
};



int main(){
    Solution obj;
    vector<int>num;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    cout << obj.trap(num) << endl;
    return 0;
}