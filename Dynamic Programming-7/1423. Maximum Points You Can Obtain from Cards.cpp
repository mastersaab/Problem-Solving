// <---------------RECURSION--------------->
// class Solution {
// public:
//     int fun(int i, int j, vector<int>& cardPoints, int k) {
//         if (k == 0) return 0; // Base case: No more cards to pick
//         if (i > j && k > 0) return -1e9; // Base case: Not possible to pick k cards

//         // Recursively calculate the maximum score by choosing the card from the start or end
//         return max(
//             cardPoints[i] + fun(i + 1, j, cardPoints, k - 1),
//             cardPoints[j] + fun(i, j - 1, cardPoints, k - 1)
//         );
//     }

//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         return fun(0, n - 1, cardPoints, k);
//     }
// };

// <------------MEMOIZATION------------------->
// class Solution {
// public:


//     int fun(int i,int j,vector<int>& cardPoints,int k, vector<vector<vector<int>>>&dp){
//         int n=cardPoints.size();
         
         
//          if(k==0) return 0;
//          if(i>j && k>0) return -1e9; // not possible with exact k cards
//          if(dp[i][j][k]!=-1)  return dp[i][j][k];

//         return dp[i][j][k]=max(cardPoints[i]+fun(i+1,j,cardPoints,k-1,dp),cardPoints[j]+fun(i,j-1,cardPoints,k-1,dp));
//     }
//     int maxScore(vector<int>& cardPoints, int k) {
        
//         int n=cardPoints.size();
//         vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
//         return fun(0,n-1,cardPoints,k,dp);
//     }
// };

// <-----------TABULATION-------------->
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0); 
        if (n == k)
            return sum;
        vector<int> dp(n + 1);

        dp[0] = cardPoints[0];
        for (int i = 1; i < n; i++)
            dp[i] = dp[i - 1] + cardPoints[i];
        int ans = dp[n - k - 1];
        for (int i = 1; i <= k; i++)
            ans = min(ans, dp[n - k + i - 1]-dp[i-1]);
        return sum - ans;
    }
};
