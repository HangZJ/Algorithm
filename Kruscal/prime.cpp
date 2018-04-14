#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

#define NIL -1
#define IFINITE 0x7fffffff
#define MAXNODE 1000

typedef struct  Node
{
	int key;
	int prev;
	Node(int a, int b) :key(a), prev(b) {};
}SEdge;

bool operator <(const Node& a, const Node& b) {
	return a.key < b.key;
}


priority_queue<Node> Q;
vector<unordered_map<int, int>> E[MAXNODE];
int P, R, u, v, w;


int main() {
	while (scanf("%d%d", &P, &R), P) {
		Q.push(Node(0, NIL));
		for (int i = 1; i < P; i++) {
			Q.push(Node(IFINITE, NIL));

		}
		for (int i = 0; i < R; i++) {
			scanf("%d%d%d", &u, &v, &w);
			E[u].push_back(unordered_map<int, int>(v, w));
		}

	}
	return 0;
}