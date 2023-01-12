#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int maxi;
    map<int, vector<vector<int> > > fre;
    vector<int> sortedSums;
    int getSum(vector<int> &nums)
    {
        int sum = 0;
        for (auto it : nums)
        {
            sum += it;
        }
        return sum;
    }
    
    bool checkAnswer(vector<int> sub, int sum)
    {
        map<int, int> freS,dup;
        for (auto it : sub)
        {
            // cout << it << " ";
            freS[it]++;
        }
        dup = freS;
        // cout << endl;
        for (auto it : fre[sum])
        {
            map<int, int> freI;
            for (auto i : it)
            {
                // cout << i << " ";
                freI[i]++;
            }
            // cout << endl;
            // cout << " -----------" << endl;
            bool c = true;
            for (auto it1 : freI)
            {   
                
                if (freI[it1.first] + freS[it1.first] > count[it1.first])
                {
                   c = false;
                   break;
                }
            }
            if(c){
                return true;
            }
        }
        return false;
    }

    void getSubsets(int ind, vector<int> &sub, vector<int> &nums)
    {
        if (ind >= nums.size())
        {
            int sum = getSum(sub);
            sortedSums.push_back(sum);
            fre[sum].push_back(sub);
            if (fre[sum].size() > 1)
            {
                if (checkAnswer(sub, sum))
                {
                    maxi = max(maxi, sum);
                }
            }
            // fre[sum].push_back(sub);

            return;
        }
        sub.push_back(nums[ind]);
        getSubsets(ind + 1, sub, nums);
        sub.pop_back();
        getSubsets(ind + 1, sub, nums);
    }
    map<int, int> count;

public:
    void print(){
        for(auto it : fre){
        cout  << it.first << " " << it.second.size() << endl;
        }
    }
    int tallestBillboard(vector<int> &rods)
    {
        int n = rods.size();
        maxi = INT_MIN;
        int sum = 0;
        sort(rods.begin(), rods.end());
        for (auto it : rods)
        {
            count[it]++;
        }
        vector<int> sub;
        getSubsets(0, sub, rods);
        if(maxi == INT_MIN){
            return 0;
        }
        return maxi;
    }
};

int main()
{
    Solution obj;
    int size;
    cin >> size;
    vector<int> nums;
    for (int i = 0; i < size; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    
    cout << obj.tallestBillboard(nums) << endl;
    return 0;
}

class Solution {
    int path = 0;
    void bfs(vector<pair<int,int> >adj[],int start,int finish,int fuel){
        priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > pq;
        pq.push({fuel,start})
        while(!pq.empty()){
            int node = pq.top().second;
            int f = pq.top().first;
            for(auto it : adj[node]){
                if(!visited[it]){
                    pq.push(it);
                    visited[it] = true;
                }
            }
        }
    }

public:
    int countRoutes(vector<int>& locations,int start,int finish,int fuel) {
        int n = locations.size();
        vector<pair<int,int>adj[n];
        for(int i = 0;i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(locations[i] - location[j] > 0){
                    adj[i].push_back({j,locations[i] - location[j]});
                }
            }
        }
        vector<bool>visited(n,false);
        int count = 0;
        bfs(adj,start,finish,fuel + start);
        return ;
    }
};