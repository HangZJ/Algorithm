#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

typedef struct  Edge
{
	int u;
	int v;
	int w;

	Edge(int a, int b, int c) :u(a), v(b), w(w) {};
}SEdge;

bool operator < (const Edge& a, const Edge& b) {
	return a.w < b.w;
}

unordered_map<int, int> parent;
priority_queue<Edge> edge;
vector<Edge> tree;
int P, R, u, v, w;

int FindParent(int i) {
	if (parent[i] == i) {
		return i;
	}
	parent[i] = FindParent(parent[i]);
	return parent[i];
}

int main() {
	while (scanf("%d%d", &P, &R), P) {
		for (int i = 0; i < P; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < R; i++) {
			scanf("%d%d%d", &u, &v, &w);
			SEdge sedge(u, v, w);
			edge.push(sedge);
		}
		int pu, pv;
		while(!edge.empty()) {
			SEdge sedge = edge.top();
			edge.pop();
			pu = FindParent(sedge.u);
			pv = FindParent(sedge.v);
			if (pu != pv) {
				parent[pv] = pu;
				tree.push_back(sedge);
			}
		}
		for (vector<Edge>::iterator it = tree.begin(); it != tree.end(); it++) {
			printf("%d->%d %d", it->u, it->v, it->w);
		}
	}
	return 0;
}