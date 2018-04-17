/*
http://poj.org/problem?id=1287
Networking
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 14766		Accepted: 7788
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define IFINITE 0x7fffffff
#define MAXNODE 55

typedef struct  Node
{
	int v;
	int key;
	Node(int a, int b) :v(a), key(b) {};
}SNode;

int P, R, u, v, w;

int main() {
	while (scanf("%d", &P), P) {
		scanf("%d", &R);
		vector<Node> Adj[MAXNODE];
		bool vis[MAXNODE] = { false };
		int d[MAXNODE];
		fill(d, d + MAXNODE, IFINITE);
		d[1] = 0;

		for (int i = 0; i < R; i++) {
			scanf("%d%d%d", &u, &v, &w);
			Adj[u].push_back(Node(v, w));
			Adj[v].push_back(Node(u, w));
		}
		int ans=0;
		for (int k = 0; k < P; k++ ) {
			int min = IFINITE, u = -1;
			for (int i = 1; i <= P; i++) {
				if (!vis[i] && d[i] < min) {
					min = d[i];
					u = i;
				}
			}
			vis[u] = true;
			ans += min;
			for (int j = 0; j < Adj[u].size(); j++) {
				int v = Adj[u][j].v;
				if (!vis[v] && d[v] > Adj[u][j].key) {
					d[v] = Adj[u][j].key;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}