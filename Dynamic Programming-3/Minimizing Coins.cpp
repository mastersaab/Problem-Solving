#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, INT_MAX);
    // dp[i] represents the minimum number of coins required to achieve the sum i using the given coin denominations.
    dp[0] = 0; // Base case: 0 coins needed to make sum 0

    for (int i = 1; i <= x; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if (dp[x] == INT_MAX) {
        cout << -1 << endl; // If it is not possible to form the sum
    } else {
        cout << dp[x] << endl; // Minimum number of coins to form the sum
    }

    return 0;
}
