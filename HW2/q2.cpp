#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	stack <pair < string, int > > s;
	cin >> n;
	while(n--) {
		string str;
		int value;
		cin >> str >> value;
		if(str[0] == 'i') {
			s.push({str, value});
		}
		if(str[0] == 't') {
			while(value > 0 && s.size() > 0) {
				int &x = s.top().second;
				if( x > value) {
					x -= value;
					value = 0;
				}
				else if( x <= value) {
					value -= x;
					s.pop();
				}
			}
			if(s.size() == 0) {
				cout << "main" << '\n';
			}
			else {
				cout << s.top().first << '\n';
			}
		}
	}
    return 0;
}
