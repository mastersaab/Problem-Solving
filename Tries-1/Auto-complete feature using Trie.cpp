// CLASS FIRST QUESTION
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    vector<string> commonPrefixNames;

    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
        isEnd = false;
    }
};

void insertIntoTrie(TrieNode* root, string name) {
    TrieNode* node = root;
    for(int i = 0; i < name.length(); i++) {
        char currCharacter = name[i];
        if(node->children[currCharacter - 'a'] == nullptr) {
            node->children[currCharacter - 'a'] = new TrieNode();
        }
        node = node->children[currCharacter - 'a'];
        node->commonPrefixNames.push_back(name);
    }
    node->isEnd = true;
}

void query(TrieNode* root) {
    TrieNode* node = root;
    char input;
    while(true) {
        cout << "Enter a character" << endl;
        cin >> input;
        if(input == '*') {
            break;
        }
        if(node->children[input - 'a'] == nullptr) {
            cout << "No names available with this prefix" << endl;
            cout << "Thank You. Tata" << endl;
            break;
        }
        node = node->children[input - 'a'];
        for(string name: node->commonPrefixNames) {
            cout << name << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<string> names = {"ishaan", "ishika", "ayush", "ayushman", "alok", "ayan", "ishika"};
    TrieNode* root = new TrieNode();
    for(string name: names) {
        insertIntoTrie(root, name);
    }
    query(root);
    return 0;
}
