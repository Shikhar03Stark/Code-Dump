#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

bool isVowel(char c){
    return ( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' );
}

int main(){
    int t;
    cin>>t;
    for(int z = 1; z<=t; z++){
        cout << "Case #" << z << ": ";
        set<char> uniq;
        unordered_map<char, int> freq;
        string str;
        cin >> str;
        bool hasVowel = false, hasCons = false;
        int n = str.size();
        for(int i = 0; i<n; i++){
            char c = str[i];
            uniq.insert(c);
            freq[c]++;
            if(isVowel(c))
                hasVowel = true;
            else
                hasCons = true;
        }
        int ans = INT_MAX;
        for(auto& t: uniq){
            int cnt = 0;
            if(isVowel(t)){
                for(int i = 0; i<n; i++){
                    if(str[i] != t){
                        if(isVowel(str[i])){
                            cnt += 2;
                        }
                        else{
                            cnt += 1;
                        }
                    }
                }
            }
            else{
                for(int i = 0; i<n; i++){
                    if(str[i] != t){
                        if(isVowel(str[i])){
                            cnt += 1;
                        }
                        else{
                            cnt += 2;
                        }
                    }
                }
            }
            ans = min(ans, cnt);
        }
        if(!hasVowel || !hasCons){
            ans = min(ans, (int)str.size());
        }

        cout << ans << endl;
    }
    return 0;
}