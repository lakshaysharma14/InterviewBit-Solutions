/*
	Partition
	----------
	Approach :
	----------
	Make  prefix array and suffix array to store the index till where sum is one third of the 
	total sum and then check in between those elements whether sum is 1/3 or not
*/

int Solution::solve(int A, vector<int> &B) 
{
    int sum = 0;
    for(int n:B)
    sum = sum + n;
    
    if(sum%3 != 0)
    return 0;
    
    sum = sum/3;
    
    vector<int> prefix; vector<int> suffix;
    int s = 0;
    for(int i=0;i<B.size();i++)
    {
        s = s + B[i];
        if(s == sum)
        prefix.push_back(i);
    }
    s=0;
    for(int i=B.size()-1;i>=0;i--)
    {
        s = s+B[i];
        if(s==sum)
        suffix.push_back(i);
    }
    
    int ans = 0;
    for(int i=0;i<prefix.size();i++)
    {
        for(int j=0;j<suffix.size();j++)
        {
            int x = 0,n = 0;
            for(int k = prefix[i]+1;k<suffix[j];k++)
            {
                x = x + B[k];
                n = 1;
            }
            if(x == sum && n==1)
            ans++;
        }
    }
    return ans;
}