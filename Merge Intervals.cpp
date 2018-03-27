/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval>res;
        int len = intervals.size();
        if(len == 0){
            return res;
        }
        sort(intervals.begin(),intervals.end(),comp);//sort according first
        res.push_back(intervals[0]);
        for(int i=1;i<len;i++){
             if (res.back().end < intervals[i].start){ // not overlapping with previous
                 res.push_back(intervals[i]); // just push the new interval
             }
            else{ // update the end of overlaping interval with max value
                res.back().end = max(res.back().end, intervals[i].end);
            }
        }
        return res;
    }
private:
    static bool comp(Interval a, Interval b){
        return a.start < b.start;
    }
};