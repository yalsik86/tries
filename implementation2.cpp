// using struct and without put and get functions
// functions to count prefixes and words 
// as well as erase word given that it exists
#include <bits/stdc++.h> 
class Node {
public:
    Node* links[26];
    int prefixCnt;
    int wordCnt;
    bool containsKey(char c) {
        if(links[c-'a']==NULL)
            return false;
        return true;
    }
};
class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string &s){
        Node* node = root;
        for(int i=0; i<s.size(); i++) {
            if(!node->containsKey(s[i])) {
                node->links[s[i]-'a'] = new Node();
            }
            node = node->links[s[i]-'a'];
            node->prefixCnt++;
        }
        node->wordCnt++;
    }

    int countWordsEqualTo(string &s){
        Node* node = root;
        for(int i=0; i<s.size(); i++) {
            if(!node->containsKey(s[i])) {
                return 0;
            } else {
                node = node->links[s[i]-'a'];
            }
        }
        return node->wordCnt;
    }

    int countWordsStartingWith(string &s){
        Node* node = root;
        for(int i=0; i<s.size(); i++) {
            if(!node->containsKey(s[i])) {
                return 0;
            } else {
                node = node->links[s[i]-'a'];
            }
        }
        return node->prefixCnt;
    }

    void erase(string &s){
        Node* node = root;
        for(int i=0; i<s.size(); i++) {
            node = node->links[s[i]-'a'];
            node->prefixCnt--;
        }
        node->wordCnt--;
    }
};
