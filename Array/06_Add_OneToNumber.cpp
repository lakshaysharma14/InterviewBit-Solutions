/* Add one to a Number */

vector<int> Solution::plusOne(vector<int> &A) 
{
    int n=A.size(),c=0;
    vector<int>res;
    res.push_back((1+A[n-1])%10);
    c = ( 1 + A[n-1] ) / 10;
    
    for(int i=n-2;i>=0;i--)
    {
        res.push_back((c+A[i])%10);
        c = (c + A[i] )/10;
    }
    if(c)
    res.push_back(c);
    
    int x=res.size();
    
    for(int i=0;i<x/2;i++) // Reverse a array 
    swap(res[i],res[x-i-1]);
    
    while(res[0]==0)
    {
       res.erase(res.begin());
    }
    return res;
}

