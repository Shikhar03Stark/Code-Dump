#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define show(x) cerr << #x << '=' << x << endl;
#define FOR(i, s, n) for(int i=0; i<(int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
using namespace std;

typedef pair<int,int> PII;
typedef unsigned long long ull;
typedef pair<ull,ull> PUU;

const int MAX = 3 * 10000 + 10;
const int P1 = 1000003;
const int P2 = 5000011;

int d[MAX];
ull h1[MAX][20];
ull h2[MAX][20];
char s[MAX];
int n, A, B;
map<PUU, vector<int> > m[20];


int main() {
	int T;
	scanf("%d", &T);
	int round = 1;
	for (int round = 1; round <= T; round++)
	{
		for(int i=0; i<20; i++)
			m[i].clear();
		memset(d, 0, sizeof d);
		scanf("%d%d%d", &n, &A, &B);
		scanf(" %s", s);
		REP(i, n)
		{
			h1[i][0] = h2[i][0] = s[i];
			m[0][PUU(h1[i][0], h2[i][0])].push_back(i);
		}
		for(int j=1; (1 << j) < n; j++) {
			ull p1 = 1, p2 = 1;
			for (int k =0; k < (1 << j); k++)
			{
				p1 = p1 * P1;
				p2 = p2 * P2;
			}
			for (int i=0; i<n; i++) {
				h1[i][j] = p1 * h1[i][j-1] + (i + (1 << (j-1)) < n ? h1[i + (1 << (j-1))][j-1] : 0); 
				h2[i][j] = p2 * h2[i][j-1] + (i + (1 << (j-1)) < n ? h2[i + (1 << (j-1))][j-1] : 0); 
				m[j][PUU(h1[i][j], h2[i][j])].push_back(i);
			}
		}
		for (int i=1; i<=n; i++)
		{
			d[i] = d[i-1] + A;
			int L = 0;
			for(int k = 1; 2 * k <= i/2; k *= 2, L++);
			vector<int> candidates;
			int done = 0;
			while(L >= 0) {
				if (i - done - (1 << L) < 0 || done + (1<<L) > i / 2) {
					L --;
					continue;
				}
				PUU hash = PUU(h1[i - done - (1<<L)][L], h2[i - done - (1 << L)][L]);
				vector<int> &v = m[L][hash];
				int idx = upper_bound(v.begin(), v.end(), i - 2 * (done + (1<<L))) - v.begin() - 1;
			/**	if (i == n)
				{
					show(L);
					show(done);
					for(int k=0; k<v.size(); k++)
						cerr << v[k] << " ";
					cerr << endl;
					show(idx);
				}
			/**/
				if (idx == -1) {
					L--;
					continue;
				}
				if (candidates.empty())
				{
					done += (1 << L);
					for(int k = 0; k <= idx; k++)
						candidates.push_back(v[k]);
					L --;
/*					if (i == n) {
						cerr << "initializing candidates" << endl;
						for(int k=0; k<candidates.size(); k++)
							cerr << candidates[k] << " ";
						cerr << endl;
						cerr << "-----" << endl;
					}
*/					continue;
				}
				unsigned i_cand = 0, i_v = 0;
				vector<int> new_cand;
/*
				cerr << "candidates: " << endl;
				for(int k = 0; k<candidates.size(); k++)
					cerr << candidates[k] << " ";
				cerr << endl;
*/
				while (i_cand < candidates.size() && i_v <= idx) {
//					show(candidates[i_cand]);
//					show(v[i_v]);
					if(candidates[i_cand] == v[i_v] + (1 << L)) {
//						cerr << "@@@" << candidates[i_cand] << " " << v[i_v] << endl;;
						new_cand.push_back(candidates[i_cand] - (1 << L));
						i_cand ++;
						i_v ++;
					}
					else if (candidates[i_cand] < v[i_v] + (1 << L))
						i_cand ++;
					else
						i_v ++;
				}
				if (!new_cand.empty()) {
					candidates = new_cand;
					done += (1 << L);
				}
				L--;
			}
			if (done > 0)
				d[i] = min(d[i], d[i - done] + B);
		}
/**
		for(int i=0; i<=n; i++)
			cerr << d[i] << " ";	cerr << endl;
/**/
		cout << d[n] << endl;
//		break;

	}
	return 0;
}

