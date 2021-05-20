#include<bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> pii;

const int N = 60;
const int INF = 1e18;

int s, d, l, m;
vector<pair<pii, int> > g;
vector<int> vec;




int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> m;
	int mx = 0;
	while(m --) {
		int u, v, w;
		cin >> u >> v >> w;
		g.push_back({{u, v}, w});
		mx = max({mx, u, v});
	}
	cin >> s >> d >> l;
	mx = max({mx, s, d});
	int dis[mx + 1][l + 1], par[mx + 1][l + 1];
	fill_n(dis[0], (mx+1)*(l+1), INF);
	fill_n(par[0], (mx+1)*(l+1), 0);
	dis[s][0] = 0;
	for(int i = 1; i <= l; i ++) {
		for(int t = 0; t < g.size(); t ++) {
			auto edge = g[t];
			int u = edge.first.first, v = edge.first.second, w = edge.second;
			if(dis[u][i - 1] == INF) 
				continue;
			if(dis[u][i - 1] + w < dis[v][i]) {
				dis[v][i] = dis[u][i - 1] + w;
				par[v][i] = u;
			}
		}
	}
	int res = dis[d][l];
	if(res == INF)
		return cout << "Impossible", 0;
	while(d ^ s) {
		if(l < 0 && d == 0)
			return cout << "namusan?", 0;
		vec.push_back(d);
		d = par[d][l --];
	}
	vec.push_back(s);
	reverse(vec.begin(), vec.end());
	for(auto x : vec)
		cout << x << ' ';
	cout << res;
	return 0;
}
