/* 
	Maximum Absoulute Difference
	-------------
	Approach
	------------
	1.) Brute Force => Using 2 loops => O(n^2)
	2.) Optimal => Analyse the modulus expression |ai+aj| + |i+j|

	Case 1: A[i] > A[j] and i > j
	hence, f(i, j) = (A[i] + i) - (A[j] + j)
	------------------------------------------------------------------------------
	Case 2: A[i] < A[j] and i < j
	hence, f(i, j) = -(A[i] + i) + (A[j] + j) = -[(A[i] + i) - (A[j] + j)] 
	
	Negative(Ignore as we have to max value)
	--------------------------------------------------------------------------------

	Case 3: A[i] > A[j] and i < j
	hence, f(i, j) = (A[i] - i) - (A[j] - j)
	-----------------------------------------------------------------------------------
	Case 4: A[i] < A[j] and i > j
	hence, f(i, j) = -(A[i] - i) + (A[j] - j) = - [(A[i] - i) - (A[j] - j)]

	Negative(Ignore as we have to max value)
	---------------------------------------------------------------------------------------
	Case 1 & 2 are redundant
	Case 3 & 4 are redundant


	So max((max1-min1),(max2-min2)) = Answer
*/

int Solution::maxArr(vector<int> &A) 
{
    int max1 = INT_MIN , max2 = INT_MIN;
    int min1 = INT_MAX , min2 = INT_MAX;
    
    for(int i=0;i<A.size();i++)
    {
        max1 = max(max1,A[i]+i);
        max2 = max(max2,A[i]-i);
        min1 = min(min1,A[i]+i);
        min2 = min(min2,A[i]-i);
    }
    return max((max1-min1),(max2-min2));
}
