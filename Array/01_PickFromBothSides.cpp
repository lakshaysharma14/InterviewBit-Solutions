/* Pick From both Side 

Instead of going for 2 pointer approach we will go for another observation based approach bcoz 2 pointer approach wont work if there is a array element with very large value after the element which has minumum value.
----------
Approach :
-----------
Try to minimize the sum of N-B consecutive elements. Doing so will ensure that sum of other B elements is maximum. Dont follow greedy i.e. 2 pointer approach

*/

int Solution::solve(vector<int> &A, int B) 
{
    if(A.size()==0)
    return 0;
    
    int s=0,s1=0,mn;
    for(int n:A)
    s= s + n;
    
    int i=0,j=A.size()-B-1,s2=0;
    
    for(int k=i;k<=j;k++)
    s1 = s1 + A[k];
    
    mn = s1;
    i++;j++;
    while(j<A.size())
    {
        s1 = s1+A[j]-A[i-1];
        mn = min(s1,mn);
        i++;
        j++;
    }
    return (s - mn);
}