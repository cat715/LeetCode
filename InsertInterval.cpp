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
private:
    static bool comp(Interval a, Interval b)
    {
        return a.start < b.start;
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        //在原始数组上操作
        vector<Interval>::iterator ite = lower_bound(intervals.begin(),intervals.end(), newInterval, comp);//按照start值二分查找
        if(ite != intervals.begin() && newInterval.start <= (ite-1)->end)//ite的上一个区间也可能参与合并
        {
            ite--;
            //合并后新区间的起点只和第一个合并的区间有关，因为数组时按区间起点有序的
            newInterval.start = min(newInterval.start, ite->start);
        }
        vector<Interval>::iterator eraseBegin = ite;
        for(; ite != intervals.end() && newInterval.end >= ite->start; ite++)
            if(newInterval.end < ite->end)newInterval.end = ite->end;//合并后的新区间存放于newInterval
         
        ite = intervals.erase(eraseBegin, ite);//[eraseBegin, ite)是合并时应该删掉的区间
        intervals.insert(ite, newInterval);//插入合并后的区间
        return intervals;
    }
};