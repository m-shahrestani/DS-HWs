#include<bits/stdc++.h>
using namespace std;

int main(){
	stack <int> a, s;
	string str;
	getline(cin, str);
	for(int i = str.length()-1; i >= 0; i--) {
		int j = 0, count = 0, pow = 1;
		while(str[i-j] != ' ' && i-j >= 0) {
			count += (str[i-j]-'0') * pow;
			j++;
			pow *= 10;
		}
		i-= j;
		if(j>0) {
			a.push(count);
		}
	}
    int k = 1;
	while(a.size() > 0) {
		s.push(a.top());
		a.pop();
		while( s.size() > 0 && k == s.top()) {
			s.pop();
			k ++;
		}
	}
	if(0 == s.size()) {
		cout<<"yes";
	}
	else {
		cout<<"no";	
	}
    return 0;
}
