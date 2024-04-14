class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string s) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < s.length(); i++) {
            char lastCh = s[i];
            prefix.push_back(lastCh);

            TrieNode* curr = prev->children[lastCh - 'a'];
            if (curr == NULL) {
                break;
            }

            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            output.push_back(temp);
            prev = curr;
        }

        int remaining = s.size() - output.size();
        for (int i = 0; i < remaining; i++) {
            output.push_back({"0"});
        }

        return output;
    }
};

class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie* t = new Trie();

        for (int i = 0; i < n; i++) {
            t->insertWord(contact[i]);
        }

        return t->getSuggestions(s);
    }
};
