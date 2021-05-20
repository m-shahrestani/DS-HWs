#include<bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m;
queue<pair<int, int> > q;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	int dis[n][m];
	string s[n];
	for(int i = 0; i < n; i ++)
		cin >> s[i];
	memset(dis, -1, sizeof  dis);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			if(s[i][j] == 'M') {
				dis[i][j] = 0;
				q.push({i, j});
			}
	while(q.size()) {
		auto v = q.front();	q.pop();
		int x = v.first, y = v.second;
		for(int i = 0; i < 4; i ++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != 'X' && dis[nx][ny] == -1) {
				dis[nx][ny] = dis[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	for(int i = 0; i < n; i ++, cout << '\n')
		for(int j = 0; j < m; j ++)
			cout << dis[i][j] << ' ';
	return 0;
}
