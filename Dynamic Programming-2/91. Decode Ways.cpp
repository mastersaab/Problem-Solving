// -------RECURSION------
/*
    int solve(string &s, int start) {
    if (start >= s.size()) {
        return 1;
    }
    // 1 char k liye count
    int pickOne = 0;
    if (s[start] != '0') {
        pickOne = solve(s, start + 1);
    }
    // 2 char k liye count
    int pickTwo = 0;
    if (start + 1 < s.length() && s.substr(start, 2) <= "26" && s[start] != '0') {
        pickTwo = solve(s, start + 2);
    }
    return pickOne + pickTwo;
}
int numDecodings(string s) {
    if (s.empty() || s[0] == '0') {
        return 0; //agr 0 se start hota to valid nhi hota.
    }
    return solve(s, 0);
}
*/
// ---------MEMOIZATION---------
 /* int solve(int index,string &s,vector<int>& dp)
    {
        if(index==s.size())
        {
            return 1;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        //ya to ek banda lunga
        int pickone=0;
        int picktwo=0;
        if(s[index]!='0')
        {
            pickone=solve(index+1,s,dp);
            if(index+1<s.length() && s.substr(index,2)<="26")
            {
                picktwo=solve(index+2,s,dp);
            }
        }
        return dp[index]=(pickone+picktwo);
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
            return solve(0,s,dp);
    }
*/
//---------TABULATION----------
/*   int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    
    // Base case: Empty string
    dp[n] = 1;
    
    // Iterate from end of string to beginning.
    for (int i = n - 1; i >= 0; i--) {
        // If the current character is '0', akela nhi hoga decode
        if (s[i] == '0') {
            dp[i] = 0;
            continue;
        }
        int pickOne = dp[i + 1];
        int pickTwo = 0;
        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            pickTwo = dp[i + 2];
        }
        
        // Total count for current position.
        dp[i] = pickOne + pickTwo;
    }
    
    return dp[0];
}
*/
// ---------SPACE OPTIMISATION-----------
    int numDecodings(string s) {
        int n = s.size();
        
        // two most recent states.
        int prevPrev = 0;
        int prev = 1;
    
        for (int i = n - 1; i >= 0; i--) {
            // Current state calculation.
            int current = 0;
            
            // If the current character is '0', akela nhi hoga decode
            if (s[i] != '0') {
                current += prev; // single k liye count
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    current += prevPrev; // agr 2 ho ske uske liye count
                }
            }
            
            // Update the two most recent states for the next iteration.
            prevPrev = prev;
            prev = current;
        }
        
        return prev;
    }
