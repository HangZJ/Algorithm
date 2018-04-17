/*
http://poj.org/problem?id=1287
Networking
Time Limit: 1000MS		Memory Limit: 10000K
Total Submissions: 14766		Accepted: 7788
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;

typedef struct  Edge
{
	int u;
	int v;
	int w;

	Edge(int a, int b, int c) :u(a), v(b), w(c) {};

	friend bool operator < (Edge a, Edge b) {
		return a.w > b.w;
	}
}SEdge;

map<int, int> parent;
int P, R, u, v, w, ans;

int FindParent(int i) {
	if (parent[i] == i) {
		return i;
	}
	parent[i] = FindParent(parent[i]);
	return FindParent(parent[i]);
}

int main() {
	while (scanf("%d", &P), P) {
		scanf("%d", &R);
		for (int i = 1; i <= P; i++) {
			parent[i] = i;
		}
		priority_queue<Edge> edge;
		ans = 0;
		for (int i = 0; i < R; i++) {
			scanf("%d%d%d", &u, &v, &w);
			SEdge sedge(u, v, w);
			edge.push(sedge);
		}
		int pu, pv, ecounter = 0;
		while (ecounter < P - 1) {
			SEdge sedge = edge.top();
			edge.pop();
			pu = FindParent(sedge.u);
			pv = FindParent(sedge.v);
			if (pu != pv) {
				parent[pv] = pu;
				ans += sedge.w;
				ecounter++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}