#include<iostream>
using namespace std;

class TrieNode {
public:
    bool isWord = false;
    unordered_map<char, TrieNode*> children;
};

class Trie {
private:
    TrieNode *root = new TrieNode();

public:
    Trie() {
        
    }
    
    // O(l) time complexity, where l is the length of the word
    void insert(string word) {
        TrieNode *temp = root;
        for(char ch: word) {
            if(temp->children.find(ch) == temp->children.end()) {
                temp->children[ch] = new TrieNode();
            }
            temp = temp->children[ch];
        }
        temp->isWord = true;
    }
    
    // O(l) time complexity, where l is the length of the word
    bool search(string word) {
        TrieNode *temp = root;
        for(char ch: word) {
            if(temp->children.find(ch) == temp->children.end()) {
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->isWord;
    }
    
    // O(l) time complexity, where l is the length of the prefix
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for(char ch: prefix) {
            if(temp->children.find(ch) == temp->children.end()) {
                return false;
            }
            temp = temp->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    cout << trie.search("hello") << endl; // true
    cout << trie.search("world") << endl; // true
    cout << trie.search("hi") << endl; // false
    cout << trie.startsWith("he") << endl; // true
    cout << trie.startsWith("wo") << endl; // true
    cout << trie.startsWith("hi") << endl; // false
    return 0;
}