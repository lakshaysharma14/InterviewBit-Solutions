/* 
	Flip the Bits
	-----------
	* Approach
	-----------
	We have to see the substring where zeroes are maximum and ones are minimum i.e.
	by doing so we will be ensuring you that ones are maximum in the string.
	Code follows similar approach as kadane's algorithm.

*/
vector<int> Solution::flip(string A)
{
    int ctz = 0,cto = 0;
    vector<int> ans;
    for(char c:A)
    {
        if(c=='0')
        ctz++;
        else
        cto++;
    }
    
    
    if(ctz==0)
    return ans;
    
    if(A.size()==0)
    {
        if(A[0]=='0')
        {
            ans.push_back(1);
            ans.push_back(1);
            return ans;
        }
    }
    
    int mxcnt = INT_MIN;
    int cnt=0,l,r,ltemp=0;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == '0')
        cnt++;
        else
        cnt--;
        
        if(cnt<0)
        {
            cnt=0;
            ltemp = i+1;
        }
        
        if(cnt>mxcnt)
        {
            mxcnt = cnt;
            l=ltemp;
            r=i;
        }
    
    }
    
    ans.push_back(l+1);
    ans.push_back(r+1);
    
    return ans;
}