#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int

using namespace std;

struct RMQ{

};
long long greatestValueDays(vector<int> ratings) {
    int n = ratings.size();
    int mi = -1;
    int start = 0;
    
    vector<long long> ans(n,0);
    for(int i = 0; i<n; i++){
        if(mi == -1){
            ans[i] = ratings[i]*ratings[i];
            mi = i;
            continue;
        }
        {
            int newmi = ratings[i] <= ratings[mi] ? i : mi;
            if(newmi == mi){
                if(ratings[mi] == 0){
                    ans[i] = ratings[i]*ratings[mi];
                }
                else{
                    ans[i] = (ans[i-1]/ratings[mi] + ratings[i])*ratings[mi];
                }
            }
            else{
                long long aux = 0;
                if(ratings[mi] == 0){
                    aux = ratings[i]*ratings[newmi];
                }
                else{
                    aux = (ans[i-1]/ratings[mi] + ratings[i])*ratings[newmi];
                }
                if(aux >= ans[i-1]){
                    mi = newmi;
                    ans[i] = aux;
                }
                else{
                    ans[i] = ans[i-1];
                    start = i+1;
                    mi = -1;
                }
            }
        }
        if(ans[i] == 0){
            mi = i;
            start = i+1;
        }
    }
    
    return *(max_element(ans.begin(), ans.end()));
}
int main(){
    greatestValueDays({0,0,1,2,0,0});
    return 0;
}