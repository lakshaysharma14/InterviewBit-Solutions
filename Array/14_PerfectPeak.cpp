/* 
	Perfect Peak of Array 
	------------------------------------------------------------------------------------
	Approach: 
	Just keep track of max element on left and min element on right for each element.
	Then if any element > max element on its left and element < min element on its right
	then that's the answer.
	--------------------------------------------------------------------------------------
*/

int Solution::perfectPeak(vector<int> &A) 
{
    int n = A.size();
    if(A.size()==0)
    return 0;
    
    int leftmax[n],rightmax[n];
    leftmax[0] = A[0];
    rightmax[n-1] = A[n-1];
    
    for(int i=1;i<n;i++)
    leftmax[i] = max(A[i],leftmax[i-1]);
    
    for(int i=n-2;i>=0;i--)
    rightmax[i] = min(A[i],rightmax[i+1]);
    
    int ans = 0;
    for(int i=1;i<n-1;i++)
    {
        if(A[i] > leftmax[i-1] && A[i]<rightmax[i+1])
        {
            ans=1;
            break;
        }
    }
    return ans;
}