#include<bits/stdc++.h>
using namespace std;

// Using Binary Indexed Tree(Fenwick Tree)
class NumArray {
public:
    vector<int>Fen,arr;
    int size;

    void build(vector<int>nums){
        for(int i = 0; i < nums.size(); i++){
            Buildupdate(i,nums[i]);
        }
    }
    
    NumArray(vector<int>& nums){
        arr = nums;
        Fen.resize(nums.size() + 1);
        fill(Fen.begin(),Fen.end(),0);
        size = arr.size();
        build(nums);
    }
    
    void Buildupdate(int index, int val) {
        index += 1;
        while(index <= size){
            Fen[index] += val;
            index = index + (index & (-index));
        }
    }

    void update(int index, int val) {
        val = val - arr[index];
        arr[index] = val;
        index += 1;
        while(index <= size){
            Fen[index] += val;
            index = index + (index & (-index));
        }
    }
    
    int sumOneRange(int index){
        index += 1;
        int sum = 0;
        while(index > 0){
            sum += Fen[index];
            index -= (index & -index);
        }
        return sum;
    }

    int sumRange(int left, int right){
        int l = sumOneRange(left - 1);
        int r = sumOneRange(right);
        cout << l << " " << r << endl;
        return  r - l ;
    }
    
    void _printFen(){
        for(int i = 1; i < Fen.size(); i++){
            cout << Fen[i] << ' ';
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */


// Using Segment Tree
class NumArray {
public:
    vector<int>Seg,arr;
    int size;

    NumArray(vector<int>& nums){
        arr = nums;
        Seg.resize(4 * nums.size());
        fill(Seg.begin(),Seg.end(),0);
        size = arr.size();
        build(0,0,size - 1);
    }
    

    void build(int index,int low,int high){
        if(low == high){
            Seg[index] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * index + 1,low,mid);
        build(2 * index + 2,mid + 1,high);
        Seg[index] = Seg[2 * index + 1] + Seg[2 * index + 2];
    }
    
    void update(int low,int high,int pos,int index,int diff){
        if(pos < low  || pos > high){
            return;
        }
        Seg[index] = Seg[index] + diff;
        if(low < high){
            int mid = (low + high)/ 2;
            update(low,mid,pos,2 * index + 1,diff);
            update(mid + 1,high,pos,2 * index + 2,diff);
        }
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        update(0,size - 1,index,0,diff);
    }
    
    int sumRange(int left, int right){
        return query(0,size - 1,0,left,right);
    }
    int query(int low,int high,int index,int l,int r){
        if( high < l || low > r){
            return 0;
        }
        if(l <= low && r >= high){
            return Seg[index];
        }
        int mid = low + (high - low) / 2;
        return query(low,mid,2 * index + 1,l,r) + query(mid + 1,high,2 * index + 2,l,r);
    }

    void _printSeg(){
        for(int i = 0; i < Seg.size(); i++){
            cout << Seg[i] << ' ';
        }
    }
};



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(){
    int size;
    cin >> size;
    vector<int> nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    SegTree obj(nums);
    
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
           int l,r;
           cin >> l >> r;
           cout << obj.query(0,size - 1,0,l,r) << endl;
        }else if(type == 2){
            int pos,val;
            cin >> pos >> val;
            int diff = val - obj.arr[pos];
            obj.update(0,size - 1,0,pos,diff);
        }else{
            obj._printSeg();
        }
    }
}