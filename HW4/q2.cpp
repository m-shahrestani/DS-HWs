#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef pair<int, int> pii;

int n;
string s;
map<pair<pii, bool>, bool> mp;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	cin >> n;
	while(n --) {
		cin >> s;
		pii state = {0, 0};
		int res = 0;
		for(auto c : s) {
			pii nxt;
			if(c == 'N'){
				nxt = {state.F + 1, state.S};
				res += (mp[{state, 0}] ? 1 : 5);
				mp[{state, 0}] = 1;
			}
			if(c == 'W') {
				nxt = {state.F, state.S + 1};
				res += (mp[{state, 1}] ? 1 : 5);
				mp[{state, 1}] = 1;
			}
			if(c == 'S') {
				nxt = {state.F - 1, state.S};
				res += (mp[{nxt, 0}] ? 1 : 5);
				mp[{nxt, 0}] = 1;
			}
			if(c == 'E') {
				nxt = {state.F, state.S - 1};
				res += (mp[{nxt, 1}] ? 1 : 5);
				mp[{nxt, 1}] = 1;
			}
			state = nxt;
		}
		mp.clear();
		cout << res << '\n';
	}
	return 0;
}
