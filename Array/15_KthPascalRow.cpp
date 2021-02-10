/* Kth Row of Pascal Triangle */

//=============== Optimised Solution ==============
vector<int> Solution::getRow(int A) {
    
    vector<int>temp;// to store the resultant row
    
        int n  = 1;
        for( int col = 0; col <= A ; col++){// nth row will have n + 1 elements in pascal triangle
            temp.push_back(n);
            n = n * (A - col)/(col + 1);// mathematics
        }
    return temp; // resultant vector returned.
    // space complexity O(A).
    // time complexity O(A).
}
//============== Basic  Solution ==================
vector<int> Solution::getRow(int A) 
{
    vector<vector<int>> res;
    vector<int> firstRow;
    firstRow.push_back(1);
    
    res.push_back(firstRow);
    
    for(int i=1;i<=A;i++)
    {
        vector<int> prow = res[i-1];
        vector<int> crow;
        crow.push_back(1);
        
        for(int j=1;j<i;j++)
        crow.push_back(prow[j-1]+prow[j]);
        
        crow.push_back(1);
        res.push_back(crow);
    }
    
    vector<int > ans = res[A];
    return ans;
}
