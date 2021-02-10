/* Merge Intervals */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compare(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) 
{
    intervals.push_back(newInterval);
    vector<Interval> result;
    
    if(intervals.size()==0)
    return result;
    
    sort(intervals.begin(),intervals.end(),compare);
    Interval crrntInt = intervals[0];
    result.push_back(crrntInt);
    for(int i=1;i<intervals.size();i++)
    {
        int crbeg = crrntInt.start;
        int crend = crrntInt.end;
        
        int newbeg = intervals[i].start;
        int newend = intervals[i].end;
        
        if(crend>=newbeg)
        {
            int maxend = max(crend,newend);
            crrntInt.end = maxend;
            
            result.pop_back();
            result.push_back(crrntInt);
        }
        else
        {
            crrntInt = intervals[i];
            result.push_back(crrntInt);
        }
    }
    return result;
}
