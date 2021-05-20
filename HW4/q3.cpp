#include<bits/stdc++.h>

using namespace std;

const int N = 510;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m, dis[N][N], res;
pair<int,int> cor;
char ch;
char s[N][N];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> s[i][j];
	cin >> ch;
	for(char w = 'Z'; w >= 'A'; w --)
		for(int i = 0; i < n; i ++)
			for(int j = 0; j < m; j ++)
				if(s[i][j] == w) {
					dis[i][j] = 1;
					for(int t = 0; t < 8; t ++) {
						int x = i + dx[t], y = j + dy[t];
						if(x >= 0 && x < n && y >= 0 && y < m && s[x][y] == w + 1)
							dis[i][j] = max(dis[i][j], dis[x][y] + 1);
					}
					if(w == ch && dis[i][j] > res) {
						res = dis[i][j];
						cor = {i, j};
					}
				}
	cout << res << '\n' << cor.first << ' ' << cor.second;
	return 0;
}
