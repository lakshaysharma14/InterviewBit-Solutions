/* Maximum Subarray Sum => Kadanes Algorithm */
int Solution::maxSubArray(const vector<int> &A) 
{
    if(A.size()==1)
    return A[0];
    
    int msf = INT_MIN,mse=0;
    for(int i=0;i<A.size();i++)
    {
        mse = mse + A[i];
        if(msf<mse)
        msf = mse;
        
        if(mse<0)
        mse = 0;
    }
    return msf;
    
}