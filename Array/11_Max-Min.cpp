/*
	Max Min (Return Sum of Max and Min element of Arrat and do that in min no of Comparisions )
	-----------
	Approach
	-----------
	In Optimised version use divide and conquer approach t.c. will be same as basic one but no
	of comparisions will be minimized.

	Just find min and max on left side and right side part of array and then take min and max of 
	(leftmin,rightmin) &  (leftmax,rightmax)
*/

//=============Basic Solution================
int Solution::solve(vector<int> &A) 
{
    int mx = INT_MIN;
    int mn = INT_MAX;
    
    if(A.size()==1)
    return A[0];
    
    if(A.size()==2)
    {
    	if(A[0]>A[1])
    	{ mx=A[0]; mn = A[1];}
    	else
    	{ mx=A[1]; mn = A[0];} 

    	return (mx+mn); 
    }
    
    for(int i=0;i<A.size();i++)
    {
        mx=max(mx,A[i]);
        mn=min(mn,A[i]);
    }
    return (mx+mn);
}
//========Optimised Solution====================
vector<int> find(vector<int>& A,int l,int r)
{
    vector<int> v(2,0);
    
    if(l==r)
    {
        v[0]=A[l];
        v[1]=A[l];
        return v;
    }
    
    if(l+1==r)
    {
        v[0] = min(A[l],A[r]);
        v[1] = max(A[l],A[r]);
    
        return v;
    }
    
    int mid=l+(r-l)/2;
    
    vector<int> left= find(A,l,mid-1);
    vector<int> right= find(A,mid,r);
    
    v[0]=min(left[0],right[0]);
    v[1]=max(left[1],right[1]);
    
    return v;
}


int Solution::solve(vector<int> &A) {
    
  vector<int> v;
  v=func( A,0,A.size()-1);
  return v[0]+v[1];
    
}