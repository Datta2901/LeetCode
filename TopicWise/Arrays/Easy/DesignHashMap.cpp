#include<bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    int data[1000001];
    MyHashMap() {
        fill(data, data + 1000000, -1);
    }
    
    /** value will always be non-negative. */
     
    void put(int key, int val) {
        data[key] = val;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return data[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        data[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main(){
    Solution obj;
    vector<int>answer;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        answer.push_back(a);
    }
    
    return 0;
}