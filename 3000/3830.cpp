#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, a, b, w;
char c;
vector<int> root;
vector<int> dist;

pii find(int a) {
	if (a == root[a])
		return { a, 0 };
	
	pii val = find(root[a]);
	root[a] = val.first;
	dist[a] += val.second;

	return { root[a], dist[a] };
}

void merge(int a, int b, int w) {
	pii ra = find(a);
	pii rb = find(b);
	root[ra.first] = rb.first;
	dist[ra.first] = rb.second - ra.second - w;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) 
			return 0;
		
		root.clear();
		dist.clear();
		root.resize(N + 1);
		dist.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			root[i] = i;
		}

		for (int i = 0; i < M; i++) {
			cin >> c >> a >> b;
			if (c == '!') {
				cin >> w;
				merge(a, b, w);
			}
			else {
				pii ra = find(a);
				pii rb = find(b);
				if (ra.first == rb.first)
					cout << rb.second - ra.second << '\n';
				else
					cout << "UNKNOWN\n";
			}
		}
	}
	return 0;
}
