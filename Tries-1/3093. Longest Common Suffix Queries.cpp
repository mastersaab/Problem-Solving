struct TrieNode {
    int min_size;
    int min_index;
    TrieNode* children[26];

    TrieNode() {
        min_size = INT_MAX; 
        min_index = INT_MAX;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, const string& key, int index) {
    TrieNode* current = root;
    for (char c : key) {
        int idx = c - 'a';
        if (current->children[idx] == nullptr) {
            current->children[idx] = new TrieNode();
        }
        if (key.size() < current->min_size) {
            current->min_size = key.size();
            current->min_index = index;
        }
        current = current->children[idx];
    }
    if (key.size() < current->min_size) {
        current->min_size = key.size();
        current->min_index = index;
    }
}

int findLongestCommonPrefixIndex(TrieNode* root, const string& str) {
    TrieNode* current = root;
    int longest_common_prefix_index = -1;

    for (char c : str) {
        int idx = c - 'a';
        if (current->children[idx] == nullptr) {
            break;
        }
        current = current->children[idx];
        if (current->min_index != INT_MAX) {
            longest_common_prefix_index = current->min_index;
        }
    }
    if (current->min_index != INT_MAX) {
        longest_common_prefix_index = current->min_index;
    }

    return longest_common_prefix_index;
}

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        
        for (int i = 0; i < wordsContainer.size(); ++i) {
            string temp = wordsContainer[i];
            reverse(temp.begin(), temp.end());
            insert(root, temp, i);
        }
        
        vector<int> ans((int)wordsQuery.size());
        
        for(int i = 0; i < wordsQuery.size(); i++){
            string temp = wordsQuery[i];
            reverse(temp.begin(), temp.end());
            int tp = findLongestCommonPrefixIndex(root, temp);
            ans[i] = tp;
        }
        
        return ans;
        
    }
};
