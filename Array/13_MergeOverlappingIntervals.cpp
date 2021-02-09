/*
	Merging Overlapping Subintervals
	---------
	Approach
	----------

*/
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
vector<Interval> Solution::merge(vector<Interval> &A) 
{
    vector<Interval> result;
    if(A.size()==0)
    return result;
    
    sort(A.begin(),A.end(),compare);
    Interval crrntInt = A[0];
    result.push_back(crrntInt);
    for(int i=1;i<A.size();i++)
    {
        int crbeg = crrntInt.start;
        int crend = crrntInt.end;
        
        int newbeg = A[i].start;
        int newend = A[i].end;
        
        if(crend>=newbeg)
        {
            int maxend = max(crend,newend);
            crrntInt.end = maxend;
            
            result.pop_back();
            result.push_back(crrntInt);
        }
        else
        {
            crrntInt = A[i];
            result.push_back(crrntInt);
        }
    }
    return result;
}