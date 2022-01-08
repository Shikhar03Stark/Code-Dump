#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        string cells;
        cin >> n >> k;
        cin >> cells;

        unordered_map<int, int> sheets;
        unordered_map<int, bool> mags, irons;
        int tot = 0;
        for(int i = 0; i<n; i++){
            char c = cells[i];
            if(c == 'M'){
                mags[i] = false;
            }
            if(c == 'I'){
                irons[i] = false;
            }
            if(c == ':'){
                ++tot;
            }
            sheets[i] = tot;
        }
        int ans = 0;
        int m = 0, i = 0;
        while (i < n && m<n){
            if (cells[m] == 'M'){
                while(i < n && cells[i] != 'X'){
                    if(cells[i] == 'I'){
                        break;
                    }
                    ++i;
                }
                if(cells[i] == 'I'){
                    if(mags[m] == false && irons[i] == false){
                        int p = k + 1 - abs(m - i) - abs(sheets[m] - sheets[i]);
                        if(p>0){
                            mags[m] = true;
                            irons[i] = true;
                            ++ans;
                            ++m;
                            ++i;
                            continue;
                        }
                        else{
                            ++i;
                            continue;
                        }
                    }
                }
                else if(cells[i] == 'X'){
                    m = i+1;
                    i = i+1;
                    continue;
                }
            }
            else if(cells[m] == 'X'){
                i = m+1;
                m = m+1;
                continue;
            }
            m++;
        }

        cout << ans << endl;


        /*{

            map<int,bool> irons, mags;
            unordered_map<int, int> sheets;
            unordered_map<int, int> blocks;
            int tot = 0, totb = 0;
            for(int i = 0; i<n;i++){
                char c = cells[i];
                if(c == 'I'){
                    irons[i] = false;
                }
                if(c == 'M'){
                    mags[i] = false;
                }
                if(c == 'X'){
                    totb++;
                }
                if(c == ':'){
                    ++tot;
                }
                sheets[i] = tot;
                blocks[i] = totb;
            }
            int count = 0;
            for(auto &mp : mags){
                for(auto &ip: irons){
                    if(ip.second == true){
                        continue;
                    }
                    bool isBlocked = abs(blocks[mp.first] - blocks[ip.first]) != 0 ? true : false;
                    if(isBlocked){
                        continue;
                    }
                    int s = abs(sheets[mp.first] - sheets[ip.first]);
                    int p = k + 1 - abs(mp.first - ip.first) - s;
                    if(p > 0){
                        ip.second = true;
                        if(mp.second == false){
                            ++count;
                            mp.second = true;
                            break;
                        }
                    }
                }
            }
            cout << count << endl;
        }*/


    }
    return 0;
}