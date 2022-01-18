// Diving the the given numbers into two halfs 
// (smaller than x )   (x)    (larger Than X)
//     1st half                  second half
// Here x is the median
// We want the value of greatest element on 1st half so we use maxheap
// We want the value of least element on the 2nd half so we use minheap

// If we neg the max heap we will get minheap

class MedianFinder {
    priority_queue<int>smaller,larger;
public:    
    void addNum(int num) {
        smaller.push(num);
        larger.push(-smaller.top());
        smaller.pop();
        if(larger.size() > smaller.size()){
            smaller.push(-larger.top());
            larger.pop();
        }
        
    }
    
    double findMedian() {
        if(smaller.size() > larger.size()){
            return smaller.top();
        }
        return (smaller.top() - larger.top()) / 2.0;
    }
};


class MedianFinder {
    priority_queue<int>smaller;
    priority_queue<int,vector<int>,greater<int> >larger;
public:    
    void addNum(int num) {
        smaller.push(num);
        larger.push(smaller.top());
        smaller.pop();
        if(larger.size() > smaller.size()){
            smaller.push(larger.top());
            larger.pop();
        }
        
    }
    
    double findMedian() {
        if(smaller.size() > larger.size()){
            return smaller.top();
        }
        return (smaller.top() + larger.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */