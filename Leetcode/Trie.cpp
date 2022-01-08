#include <bits/stdc++.h>
using namespace std;

class TNode {
    public:
    char letter;
    bool end;
    int value;
    vector<TNode*> next;
    TNode(char c, bool end = false, int value = 0){
        this->letter = c;
        this->end = end;
        this->value = value;
        next.resize(26, nullptr);
    }
};

class Trie {
    TNode* root;
    public:
    Trie(){
        root = new TNode(0);
    }
    
    void dfsInsert(string &key, int val, int idx, TNode* root){
        int n = key.size();
        int nidx = key[idx] - 'a';
        
        if(root->next[nidx]){
            if(idx == n-1)
                root->next[nidx]->end = true, root->next[nidx]->value = val;
            else
                dfsInsert(key, val, idx+1, root->next[nidx]);
        }
        else{
            if(idx == n-1){
                root->next[nidx] = new TNode(key[idx], true, val);
            }
            else{
                root->next[nidx] = new TNode(key[idx]);
                dfsInsert(key, val, idx+1, root->next[nidx]);
            }
        }
    }
    
    TNode* prefixNode(string &prefix, int idx, TNode* root){
        int n = prefix.size();
        if(root){
            int nidx = prefix[idx] - 'a';
            if(root->next[nidx]){
                if(idx == n-1)
                    return root->next[nidx];
                return prefixNode(prefix, idx+1, root->next[nidx]);
            }
        }
        return nullptr;
    }
    
    void sumVal(TNode* root, int &total){
        if(root){
            if(root->end){
                total += root->value;
            }
            for(int i = 0; i<26; i++){
                if(root->next[i])
                    sumVal(root->next[i], total);
            }
        }
    }
    
    void insertWord(string key, int val){
        dfsInsert(key, val, 0, root);
        
    }
    
    int sum(string pref){
        TNode* prefNode = prefixNode(pref, 0, root);
        int ans = 0;
        sumVal(prefNode, ans);
        
        return ans;
    }
};

int main(){
    Trie t;
    t.insertWord("apple", 3);
    cout << t.sum("ap") << endl;
    t.insertWord("app", 2);
    cout << t.sum("ap") << endl;
    return 0;
}