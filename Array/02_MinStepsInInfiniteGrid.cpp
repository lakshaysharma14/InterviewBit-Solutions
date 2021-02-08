/* Minimum Steps in infinite Grid
You are in an infinite 2D grid where you can move in any of the 8 directions
(x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points.. Give the minimum number of steps in which you can achieve it. You start from the first point.

Approach : Since we can move in all the 8 directions we just need to ensure that what is the max distance travelled eith from initial x cordinate to next x cordinate or intial y cordinate to next y cordinate and then add the maximum of two to the answer.
*/

int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    int x = A[0];
    int y = B[0];
    
    int ans = 0;
    for(int i=1;i<A.size();i++)
    {
        ans = ans + max(abs(x - A[i]) , abs(y - B[i]) );
        x = A[i];y=B[i];
    }
    return ans;
}