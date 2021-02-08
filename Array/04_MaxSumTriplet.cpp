/* Maximum Sum Triplet
	---------
	Approach
	-----------
	1.) Brute Force => O(n^3) using 3 loops
	2.) Fixing Jth Index => O(n)
	    -> Finding Right Side greater element  in O(1) using suffix array => O(1)
	    -> Going from J-1 to 0 to find max element i.e. smaller than A[j] => O(n) 
	    Total Time Complexity = O(n^2);
	3.) Fixing Jth Index => O(n)
	    -> Finding Right Side greater element  in O(1) using suffix array => O(1)
	    -> Using set to store element on left side and using lower_bound method to find max 
	       element greater than A[j] => set insert(logn) and search using lower bound(logn) =>O(logn) 
	    Total Time Complexity = O(nlogn);Space Complexity => O(logn)
*/


int lowValue(set<int> &s,int n)
{
    auto it = s.lower_bound(n);
    /*Since 'lower_bound' returns the first iterator greater than 'n', thus wevhave to decrement the 
    pointer for getting the minimum value*/
    --it;
    return (*it);
}

int Solution::solve(vector<int> &A) 
{
    int n = A.size();
    int suffix[n];
    
    suffix[n-1] = A[n-1];
    
    for(int i=n-2;i>=0;i--)
    suffix[i] = max( A[i] , suffix[i+1] );
    
    set<int> s;
    s.insert(A[0]);
    int sum = INT_MIN;
    
    for(int j=1;j<n-1;j++)  // We need atleast 1 element on both sides of j
    {
        
        int a = lowValue(s,A[j]);
        int b = A[j];
        int c = suffix[j+1];
        
        if(c>b && c>a && b>a) // To avoid any wrong pair
        sum = max(sum,(a+b+c));
        
        s.insert(A[j]);
    }
    return sum;
}