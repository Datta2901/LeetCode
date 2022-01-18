/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 bool comp(Interval &a,Interval &b){
        return a.start < b.start;
    }

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(),intervals.end(),comp);
        priority_queue<int,vector<int>,greater<int> >pq;
        for(int i = 0; i < n; i++){
            pq.push(intervals[i].end);
            if(intervals[i].start < pq.top()){
                count++;
            }else{
                pq.pop();
            }
        }
        return count;
    }
};