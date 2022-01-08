#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define dev(x) cerr << #x << x << endl
using namespace std;

int* test(){
    int a = 5;
    return &a;
}

int main(){
    //static int arr[3] = {[0] = 5, [2]=7};
    //printf("%d", arr[1]);
    int *hc = test();
    printf("%d", *hc);
    return 0;
}