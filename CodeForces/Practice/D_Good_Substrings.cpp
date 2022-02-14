// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

void pre(){
    
    return;
}

struct Node{
    char c;
    bool isleaf;
    vector<Node*> next;

    Node(char c){
        this->c = c;
        isleaf = false;
        next.assign(26, nullptr);
    }
};

void addString(Node* root, const string &s, int start = 0){
    int n = s.size();
    if(start<n){
        if(root->next[s[start]-'a'] == nullptr){
            Node* t;
            root->next[s[start]-'a'] = t = new Node(s[start]);
            t->isleaf = (start==n-1);
        }
        else{
            Node* t = root->next[s[start]-'a'];
            t->isleaf = (start==n-1);
        }
        addString(root->next[s[start]-'a'], s, (root->c=='.'?start:start+1));
    }
}

int maxk;

int dfs(Node* root, const string &good, int k){
    if(root){
        int sum = 0;
        if(k<=maxk){
            sum++;
        }
        for(auto& e: root->next){
            sum += dfs(e, good, (good[root->c-'a']=='1'?k:k+1));
        }

        return sum;

    }
    return 0;
}
void debugNode(Node* root){
    if(root){
        cerr << root << " " << root->c << nl;
        cerr << "isleaf " << root->isleaf << nl;
        for(int i = 0; i<26; i++){
            if(root->next[i])
                cerr << "NEXT " << root->next[i] << " " << (char)('a'+i) << nl;
        }
        cerr << nl;
        for(int i = 0; i<26; i++){
            //cerr << "NEXT " << root->next[i] << " " << 'a'+i << nl;
            debugNode(root->next[i]);
        }
    }
}

void solve(){
    string s;
    cin >> s;
    string good;
    cin >> good;
    cin >> maxk;
    Node* root = new Node('.');
    int n = s.size();
    for(int i = 0; i<n; i++){
        string t;
        for(int j = i; j<n; j++){
            t.push_back(s[j]);
            //cout << t << nl;
            addString(root, t);
        }
    }
    //debugNode(root);
    int ans = dfs(root, good, 0);
    cout << ans << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}