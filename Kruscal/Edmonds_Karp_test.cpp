#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

#define MAXNODE 1010
#define INF 1e10

typedef struct  Edge
{
	int v_to;
	int capacity;
	Edge(int a, int b) :v_to(a), capacity(b) {};
}SEdge;

vector<Edge> Adj[MAXNODE];
bool vis[MAXNODE] = { false };
int pre[MAXNODE];
int u, v, c;
int n, m;//n边数  m节点数
int maxflow;

bool BFS() {
	queue<int> q;
	q.push(0);
	while (!q.empty() && !vis[m - 1]) {
		int cur = q.front();
		q.pop();
		for (int to = 0; to < Adj[cur].size(); to++)
		{
			Edge &e = Adj[cur][to];
			if (!vis[e.v_to] && e.capacity > 0) {
				vis[e.v_to] = true;
				pre[e.v_to] = cur;
				q.push(e.v_to);
			}
		}
	}
	return vis[m - 1];
}

int main() {
	while (scanf("%d%d", &m, &n)) {
		fill(pre, pre + MAXNODE, -1);
		fill(vis, vis + MAXNODE, false);
		maxflow = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &u, &v, &c);
			Adj[u].push_back(Edge(v, c));
			Adj[v].push_back(Edge(u, 0));
		}
		while (BFS()) {
			int mincap = INF;
			for (int cur = m - 1; cur != 0; cur = pre[cur]) {
				int prev = pre[cur];
				mincap = min(mincap,Adj[prev][cur].capacity);
			}
		}
	}
	return 0;
}