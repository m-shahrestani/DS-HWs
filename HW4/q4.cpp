#include<bits/stdc++.h>

using namespace std;

const int N = 110;

int n, par;
vector<int> path, g[N];

void dfs(int v = 1) {
	path.push_back(v);
	if(v == n) {
		for(auto x : path)
			cout << x << ' ';
		exit(0);
	}
	for(auto u : g[v])
		dfs(u);
	path.pop_back();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	for(int i = 2; i <= n; i ++) {
		cin >> par;
		g[par].push_back(i);
	}
	dfs();
	return 0;
}
