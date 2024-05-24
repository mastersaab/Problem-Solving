#include <bits/stdc++.h>
using namespace std;

// <-----------RECURSION------------->
// int steps(int x){
//     if (x == 1)
//         return 0;
//     int a = INT_MAX, b = INT_MAX, c = INT_MAX;
//     if (x % 2 == 0)
//         a = steps(x / 2);
//     if (x % 3 == 0)
//         b = steps(x / 3);
//     c = steps(x - 1);
//     return 1 + min(a, min(b, c));
// }

// <---------------MEMOIZATION------------->
// int memoization(int n, vector<int>& dp) {
//     if (dp[n] != -1) {
//         return dp[n];
//     }
//     int a = INT_MAX;
//     int b = INT_MAX;
//     int c = 1 + memoization(n - 1, dp);
//     if (n % 2 == 0) {
//         a = 1 + memoization(n / 2, dp);
//     }
//     if (n % 3 == 0) {
//         b = 1 + memoization(n / 3, dp);
//     }
//     dp[n] = std::min(a, std::min(b, c));
//     return dp[n];
// }
// int countStepsToOne(int n) {
//     vector<int> dp(n + 1, -1);
//     dp[0] = 0;
//     dp[1] = 0;
//     return memoization(n, dp);
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<countStepsToOne(n);
//     return 0;
// }

// <------------------TABULATION---------------->
int stepsTab(int x)
{
    if (x < 2)
        return 0;
    int dp[x + 1];
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= x; i++)
    {
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if (i % 2 == 0)
            a = dp[i / 2];
        if (i % 3 == 0)
            b = dp[i / 3];
        c = dp[i - 1];
        dp[i] = 1 + min(a, min(b, c));
    }
    return dp[x];
}
int main(){
    int n;
    cin>>n;
    cout<<stepsTab(n);
    return 0;
}
