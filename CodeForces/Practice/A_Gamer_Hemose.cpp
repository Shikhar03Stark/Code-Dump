#include<stdio.h>
#include<algorithm>
#define MAXN 1005
typedef long long ll;
using namespace std;
template <typename qwq> void read(qwq &a)
{
	a=0;int x=1;char c=getchar();
	for  (;c<'0'||c>'9';c=getchar()) if  (c=='-')	x=-x;
	for  (;c>='0'&&c<='9';a=(a<<1)+(a<<3)+(c^48),c=getchar()); a*=x;
}
int a[MAXN];
void work()
{
	int N,H;read(N),read(H);
	for	(int i=1;i<=N;i++)	read(a[i]);
	sort(a+1,a+N+1);
	int xx=a[N]+a[N-1];
	int tt=H/xx*2;
	H%=xx;
	if	(H>a[N])	tt++;
	if	(H)	tt++;
	printf("%d\n",tt);
}
int main()
{
	int T;read(T);
	while	(T)
		{
			work();
			T--;
		}
 	return 0;
}
