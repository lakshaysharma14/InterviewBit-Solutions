/* 
	Spiral Matrix II 
	-------------
	Approach
	-------------
	We will make 4 boundaries and will keep bringint it inwards.
*/

vector<vector<int> > Solution::generateMatrix(int A) 
{
    vector<vector<int>> res(A,vector<int>(A));
    if(A == 0)
    return res;
    
    int rowbeg = 0;
    int rowend = A-1;
    int colbeg = 0;
    int colend = A-1;
    
    int ele = 1;
    
    while(rowbeg <=rowend && colbeg<=colend)
    {
        for(int i=colbeg;i<=colend;i++)
        res[rowbeg][i] = ele++;;
            
        rowbeg++;
        
        for(int i=rowbeg;i<=rowend;i++)
        res[i][colend] = ele++;
        
        colend--;
        
        if(rowbeg<=rowend)
        {
            for(int i=colend;i>=colbeg;i--)
            res[rowend][i]=ele++;
        }
        
        rowend--;
        
        if(colbeg<=colend)
        {
            for(int i=rowend;i>=rowbeg;i--)
            res[i][colbeg]=ele++;
        }
        colbeg++;   
    }
    return res;
}