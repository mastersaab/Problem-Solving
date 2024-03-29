USING BS
int lcm(int a, int b) {
    int greater = max(a, b); 
    int smallest = min(a, b); 
    for (int i = greater; ; i += greater) { 
        if (i % smallest  == 0) 
            return i; 
    } 
} 

int termC(int a, int b, int c, int num) {
    return ((num / a) + (num / b) + (num / c) - (num / lcm(a, b)) - (num / lcm(b, c)) - (num / lcm(a, c)) + (num / lcm(a, lcm(b, c))));
}

int findNthTerm(int a, int b, int c, int n) {
    int low = 1, high = 1e9, mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (termC(a, b, c, mid) < n)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    cout << findNthTerm(a, b, c, n);
    return 0;
}
