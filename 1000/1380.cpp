#include <bits/stdc++.h>
using namespace std;

int N;
set<int> s;
vector<string> v;
int a;
char c;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int tc = 1;; tc++) {
		v.clear();
		s.clear();
		cin >> N;
		if (N == 0) break;
		v.resize(N + 1);
		getline(cin, v[0]);
		for (int i = 1; i <= N; i++) {
			getline(cin, v[i]);
		}
		for (int i = 0; i < 2 * N - 1; i++) {
			cin >> a >> c;
			if (s.find(a) == s.end())
				s.insert(a);
			else
				s.erase(a);
		}
		for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
			cout << tc << ' ' << v[*it]<< '\n';
		}
	}
	return 0;
}
