class Solution {
public:
    struct TrieNode {
    TrieNode *children[2]; 
    int count; 
    TrieNode() {
        children[0] = children[1] = NULL; 
        count= 0; 
    } 
}; 

void insertTrie(TrieNode *root, int N) {
    for (int i = 31; i >= 0; i--) {
        bool x = (N) & (1 << i); 
        if(!root->children[x]) {
            root->children[x] = new TrieNode(); 
        } 
        root->children[x]->count+= 1; 
        root= root->children[x]; 
    } 
} 

int cntSmaller(TrieNode * root, int N, int K) {
    int cntPairs = 0; 
    for (int i = 31; i >= 0 && root; i--) {
        bool x = N & (1 << i); 
        bool y = K & (1 << i); 
        if (y) {
            if(root->children[x]) {
                cntPairs  += root->children[x]->count; 
            }
            root = root->children[1 - x]; 
        } else {  
            root = root->children[x]; 
        } 
    } 
    return cntPairs; 
} 

int pairs(vector<int>arr, int n, int k) {
    TrieNode *root = new TrieNode(); 
    int cntPairs = 0; 
    for(int i = 0;i < n; i++) {
        cntPairs += cntSmaller(root, arr[i], k); 
        insertTrie(root, arr[i]); 
    } 
    return cntPairs; 
}

int countPairs(vector<int>& nums, int low, int high) {
    int n = nums.size(); 
    return pairs(nums, n, high + 1) - pairs(nums, n, low);
}

};
