/* 
	Minimum No of Lights to Light the Corridoor
	----------
	Approach 
	----------
	Every light has the same power B. So, if we greedily start from the left and arrive at a position and pick the rightmost light to cover that position, we will end up getting the minimum no of lights required to cover the whole corridor.
*/

int Solution::solve(vector<int> &A, int B) 
{
    if(A.size()==1 && A[0]!=1) // Base Case 1
    return -1;
    
    if(B>=A.size())  // Base Case 2
    return 1;
    
    int i = B-1,ct=0,k=B;
    
    while(i<A.size())
    {
        if(A[i]==1)
        {
            ct++;
            k=B;
            
            i=i+B;    
            // Through this loop we are going towards extreme right POSSIBLE position of INDEX i                
            while(i<A.size()-1 && k>0)
            {
                i++;
                k--;
            }
            // Now from Right position we can 2*B steps backward (B for right + B for left)
            k=2*B;
        }
        else
        {
            // Searching if we get suitable position to light the bulb for index i in the range(i-B+1,i+B+1)
            i--;  
            k--;
            
            if(k==0)
            return -1;
        }
    }
    return ct;    
}
