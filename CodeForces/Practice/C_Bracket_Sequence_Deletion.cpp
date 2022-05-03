/* 1
(
1
)
2
((
2
)(
2
()
2
))
3
(((
3
)((
3
()(
3
))(
3
(()
3
)()
3
())
3
)))
4
((((
4
)(((
4
()((
4
))((
4
(()(
4
)()(
4
())(
4
)))(
4
((()
4
)(()
4
()()
4
))()
4
(())
4
)())
4
()))
4
))))
5
(((((
5
)((((
5
()(((
5
))(((
5
(()((
5
)()((
5
())((
5
)))((
5
((()(
5
)(()(
5
()()(
5
))()(
5
(())(
5
)())(
5
()))(
5
))))(
5
(((()
5
)((()
5
()(()
5
))(()
5
(()()
5
)()()
5
())()
5
)))()
5
((())
*/

// Author: Harshit Vishwakarma (Shikhar03Stark)
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define nl '\n'
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << " " << x << endl
using namespace std;

bool ispalin(string &s, int start, int end){
    int i = 0;
    while(start+i < end-i){
        if(s[start+i] != s[end-i]) return false;
        i++;
    }
    return true;
}

void pre(){
    
    return;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int ops = 0;
    while(i<n){
        int j = i;
        int open = 0;
        

    }
    
    // // cerr << nl;
    // for(int j = i; j<n; j++){
    //     if(s[j] == '('){
    //         open++;
    //     }
    //     else{
    //         open--;
    //     }
    //     if(open<0) break;
    //     if(open == 0){
    //         lastidx = j+1;
    //     }
    //     // cerr << j << ":" << open << " ";
    // }
    // if(lastidx != i){
    //     ops++;
    // }
    // cout << ops << " " << max(0, n-lastidx) << nl;
    // cerr << nl << nl;;
    // cout << ops << " " << n-lastidx << nl;
    return;
}

int main(){
    FASTIO
    pre();
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}