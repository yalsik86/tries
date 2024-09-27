// Prefix score of a string is defined as:
// sum of the number of times each prefixe of a string appears in all words in the given dictionary
class Node {
public:
    Node* links[26];
    int counter;
    bool containsKey(char c) {
        if(links[c-'a']!=NULL)
            return true;
        return false;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string s) {
        Node* node = root;
        for(int i=0; i<s.size(); i++) {
            if(!node->containsKey(s[i])) {
                node->links[s[i]-'a'] = new Node();
            }
            node = node->links[s[i]-'a'];
            node->counter++;
        }
    }
    int count(string s) {
        Node* node = root;
        int res = 0;
        for(int i=0; i<s.size(); i++) {
            node = node->links[s[i]-'a'];
            res += node->counter;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie obj;
        int n = words.size();
        for(auto i: words) {
            obj.insert(i);
        }
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            res[i] = obj.count(words[i]);
        }
        return res;
    }
};
