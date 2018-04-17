/*
http://poj.org/problem?id=1273
Sample Input
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10


Sample Output
50
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXNODE 205
#define INF 0x7fffffff

int G[MAXNODE][MAXNODE];
bool vis[MAXNODE];
int pre[MAXNODE];
int u, v, c;
int n, m;//n边数  m节点数
int maxflow;

bool BFS() {
	fill(vis, vis + MAXNODE, false);
	fill(pre, pre + MAXNODE, -1);
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (!q.empty() && !vis[m]) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= m; i++) {
			if (!vis[i] && G[cur][i] > 0) {
				vis[i] = true;
				pre[i] = cur;
				q.push(i);
			}
		}
	}
	return vis[m];
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		fill(G[0], G[0] + MAXNODE * MAXNODE, 0);
		maxflow = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &u, &v, &c);
			G[u][v] += c;
		}
		while (BFS()) {
			int mincap = INF, prev = 0;
			for (int cur = m; cur != 1; cur = pre[cur]) {
				prev = pre[cur];
				mincap = min(mincap, G[prev][cur]);
			}
			maxflow += mincap;
			for (int cur = m; cur != 1; cur = pre[cur]) {
				prev = pre[cur];
				G[prev][cur] -= mincap;
				G[cur][prev] += mincap;
			}
		}
		printf("%d\n", maxflow);
	}
	return 0;
}