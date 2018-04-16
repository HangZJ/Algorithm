#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

#define IFINITE 0x7fffffff
#define MAXNODE 1000

typedef struct  Node
{
	int v;
	int key;
	Node(int a, int b) :v(a), key(b) {};
}SNode;

bool operator <(const Node& a, const Node& b) {
	return a.key < b.key;
}

vector<Node> Adj[MAXNODE];
bool vis[MAXNODE] = { false };
int d[MAXNODE];
int P, R, u, v, w;


int main() {
	while (scanf("%d%d", &P, &R), P) {
		fill(d, d + MAXNODE, IFINITE);
		d[0] = 0;
		for (int i = 0; i < R; i++) {
			scanf("%d%d%d", &u, &v, &w);
			Adj[u].push_back(Node(v, w));
			Adj[v].push_back(Node(u, w));
		}
		int min = IFINITE, u = -1, ans=0;
		for (int k = 0; k < P; k++) {
			for (int i = 0; i < P; i++) {
				if (!vis[i] && d[i] < min) {
					min = d[i];
					u = i;
				}
			}
			vis[u] = true;
			ans += d[u];
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