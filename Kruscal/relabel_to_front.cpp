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
#include <vector>
using namespace std;

#define MAXNODE 205
#define INF 0x7fffffff

int G[MAXNODE][MAXNODE];
int h[MAXNODE];
int e[MAXNODE];
vector<int> un[MAXNODE];
int u, v, c;
int n, m;//n边数  m节点数
int maxflow;

void discharge() {

}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		fill(G[0], G[0] + MAXNODE * MAXNODE, 0);
		fill(h, h + MAXNODE, 0);
		fill(e, e + MAXNODE, 0);
		h[1] = m;
		maxflow = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &u, &v, &c);
			G[u][v] += c;
		}
		for (int i = 1; i < m; i++) {
			G[i][1] += G[1][i];
			G[1][i] = 0;
		}
		printf("%d\n", maxflow);
	}
	return 0;
}