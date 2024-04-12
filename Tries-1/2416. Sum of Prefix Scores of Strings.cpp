struct TrieNode{
    TrieNode* children[26];
    int score;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        score=0;
    }
};
class Solution {
    
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root=new TrieNode();
        for(int i=0;i<words.size();i++){
            TrieNode* node=root;
            string word=words[i];
            for(int j=0;j<word.length();j++){
                char ch=word[j];
                if(!node->children[ch-'a']) node->children[ch-'a']=new TrieNode();
                node=node->children[ch-'a'];
                node->score++;
            }
        }
        vector<int>res;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            TrieNode* node=root;
            int val=0;
            for(int j=0;j<word.length();j++){
                char c=word[j];
                node=node->children[c-'a'];
                val=val+node->score;
            }
        res.push_back(val);
        }
        return res;
    }
};
