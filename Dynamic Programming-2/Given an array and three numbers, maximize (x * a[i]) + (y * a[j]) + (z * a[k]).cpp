#include <bits/stdc++.h> 
using namespace std; 
//   TRAPPING RAINWATER KI TARAH HAI
// function to maximize the condition 
int maximizeExpr(int a[], int n, int x, int y, int z){ 
    int Left[n]; 
    Left[0] = x* a[0]; 
    for (int i = 1; i < n; i++)  
        Left[i] = max(Left[i - 1], x * a[i]); 

    // Compute right maximum for every index.  
    int Right[n]; 
    Right[n-1] = z * a[n-1];
    for (int i = n - 2; i >= 0; i--) 
        Right[i] = max(Right[i + 1], z * a[i]); 


    // Traverse through the whole array to  
    // maximize the required expression. 
    int ans = INT_MIN;  
    for (int i = 0; i < n; i++)  
          ans = max(ans, Left[i] + y * a[i] + Right[i]);  
  
    return ans; 
}  
int main()  
{  
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   int x,y,z;
   cin>>x>>y>>z;
   cout << maximizeExpr(a, n, x, y, z) << endl; 
   return 0; 
} 
