/*
	Anti Diagonals
	------------
	Approach
	------------
	We have to just iterate through first row and last coln. While iterating for particular
	element just keep checking whether (i+1,j-1) are in bounds or not. If it is then push that
	element as antidiagonal for that element.
*/
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) 
{
    vector<vector<int>> res;
    if(A.size()==0)
    return res;
    
    int rowbeg = 0;
    int rowend = A.size()-1;
    int colbeg = 0;
    int colend = A.size()-1;
    
    vector<int> f;
    f.push_back(A[rowbeg][colbeg]);
    res.push_back(f);
    
    vector<int> curr;
    colbeg++;
    
    while(colbeg<=colend)
    {
        curr.push_back(A[rowbeg][colbeg]);
        int i = rowbeg,j=colbeg;
        
        i = i+ 1 ;
        j = colbeg - 1;
        
        while(i<=A.size()-1 && j>=0)
        {
            curr.push_back(A[i][j]);
            i=i+1;
            j=j-1;
        }
        res.push_back(curr);
        colbeg++;
        curr.clear();
    }
    
    rowbeg++;
    while(rowbeg<=rowend)
    {
        curr.push_back(A[rowbeg][colend]);
        int i = rowbeg,j=colend;
        i=i+1;j=j-1;
        
        while(i<=A.size()-1 && j>=0)        
        {
            curr.push_back(A[i][j]);
            i=i+1;
            j=j-1;
        }
        res.push_back(curr);
        rowbeg++;
        curr.clear();
    }
    return res;
}