class TrieNode{
    public:
        TrieNode *children[26];
        bool isEnd;
    
        TrieNode() {
        isEnd = false;   
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie{
    public:
        TrieNode * root;
        Trie(){
            root = new TrieNode();
        }
        
        void insert(string s) {
            TrieNode* curr = root;
            for(char c : s){
                if(!curr->children[c-'a']) 
                    curr->children[c-'a'] = new TrieNode();
                curr = curr->children[c-'a'];
            }
            curr->isEnd = true;
        }
        
        string search(string s){
            TrieNode* curr = root;
            string res = "";
            for(char c : s){
              
                if(curr->isEnd) //shortest word
                    return res; 
                if(!curr->children[c-'a'] )
                    return "";
                if(curr->children[c-'a']) {
                    res += c;                     
                }
               
                curr = curr->children[c-'a'];
            }
            return curr->isEnd ? res : "";
        }
};


class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        vector<string> words;
        istringstream ss(sentence);
        string w = "";
        while(ss>>w){
            words.push_back(w);
        }
        Trie* trie = new Trie();
        for(auto  s : dict) {
            trie->insert(s);
        }
        string ans = "";
        for(string s : words) {
            string res = trie->search(s);
            if(res=="") 
                res = s;
            ans = ans + " " + res;
        }
        return ans.substr(1,ans.length()-1);
    }
};648. Replace Words
