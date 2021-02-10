/* Pascal Triangle */

vector<vector<int> > Solution::solve(int A) 
{
    vector<vector<int>> res;
    if(A==0)
    return res;
    
    vector<int> firstRow;
    firstRow.push_back(1);
    
    res.push_back(firstRow);
    
    for(int i=1;i<A;i++)
    {
        vector<int> prow = res[i-1];
        vector<int> crow;
        crow.push_back(1);
        
        for(int j=1;j<i;j++)
        crow.push_back(prow[j-1]+prow[j]);
        
        crow.push_back(1);
        res.push_back(crow);
    }
    return res;
}