
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       int dp[n+1][W+1]; // In this method we totally avoid recursive calls and just implement it using the table , this method is called bottom up approach
       // Since we start from 0 and fill the table till last row last column we call it bottom up 
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<W+1;j++)
           {
               if(i==0 || j==0)dp[i][j]=0; // filling the 0th row and column with zeroes
           }
       }
       
       
       for(int i=1;i<n+1;i++)
       {
           for(int j=1;j<W+1;j++)
           {
               if(wt[i-1]<=j)
               {
                   dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]); // deriving from the choice diagram in recursion , either to include a particular thing in 
                    // knapsack or not including it .
               }
               else
                dp[i][j] = dp[i-1][j];  // if the element weight is greater than the weight of knapsack , we could not include that in knapsack , so no operations are performed
           }
       }
       
       return dp[n][W]; // after solving the sub problems , we finally reach to the problem asked in the question 
    }
};


int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
