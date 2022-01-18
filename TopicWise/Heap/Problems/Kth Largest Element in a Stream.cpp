class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    int size;
    KthLargest(int k, vector<int>& nums) { 
        size=k;
        for(auto it :nums){
            q.push(it);
            if(q.size() > k) q.pop();
        }
    }

    int add(int val) {
        q.push(val);
        if(q.size() > size) q.pop();
        return q.top();
    }

};

   

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



class KthLargest {
public:
    vector<int>nums;
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int a, vector<int>& num) {
        nums = num;
        for(auto it : num){
            pq.push(it);
        }
        k = a;
    }
    
    int add(int val) {
        // nums.push_back(val);
        pq.push(val);
        priority_queue<int> dup = pq;
        int n = nums.size();
        for(int i = 0; i < k - 1; i++){
            dup.pop();
        }
        return dup.top();
    }
};



class KthLargest {
private:
    vector<int>nums;
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int a, vector<int>& num) {
        nums = num;
        for(auto it : num){
            pq.push(it);
        }
        k = a;
    }
    
    int add(int val) {
        // nums.push_back(val);
        pq.push(val);
        priority_queue<int> dup = pq;
        int n = nums.size();
        for(int i = 0; i < k - 1; i++){
            dup.pop();
        }
        return dup.top();
    }

};

   

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */