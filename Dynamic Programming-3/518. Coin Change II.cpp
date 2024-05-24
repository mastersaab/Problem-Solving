class Solution {
public:
// <------------TABULATION------------>
        // int change(int amount, vector<int>& coins)
        // {
        //     int n=coins.size();
        //     vector<vector<int>>dp(n,vector<int>(amount+1,0));
        //     for(int t=0;t<=amount;t++)
        //     {
        //         dp[0][t]=(t%coins[0]==0); 
        //     }
        //     for(int ind=1;ind<n;ind++)
        //     {
        //         for(int t=0;t<=amount;t++)
        //         {
        //             int nottake=dp[ind-1][t];
        //             int take=0;
        //             if(coins[ind]<=t) take= dp[ind][t-coins[ind]];
        //             dp[ind][t]=take+nottake;
        //         }
        //     }
        //     return dp[n-1][amount];
        // }
//  <-----------SPACE OPTIMISATION--------->
        int change(int amount, vector<int>& coins)
        {
            int n=coins.size();
            vector<int>prev(amount+1,0),curr(amount+1,0);
            for(int t=0;t<=amount;t++)
            {
                prev[t]=(t%coins[0]==0);
            }
            for(int ind=1;ind<n;ind++)
            {
                for(int t=0;t<=amount;t++)
                {
                    int nottake=prev[t];
                    int take=0;
                    if(coins[ind]<=t) take= curr[t-coins[ind]];
                    curr[t]=take+nottake;
                }
                prev=curr;
            }
            return prev[amount];
        }
};
